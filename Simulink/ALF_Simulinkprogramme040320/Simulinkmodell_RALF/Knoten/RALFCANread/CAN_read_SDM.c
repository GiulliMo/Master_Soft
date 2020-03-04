//S-Function Beispiel
//Uebersetzen durch: mex <SFUNCTION_NAME>.c


/*Defines und Includes*/

#define S_FUNCTION_NAME CAN_read_SDM 
#define S_FUNCTION_LEVEL 2
#define PARAM_DEF0(S) ssGetSFcnParam(S, 0)
#define PARAM_DEF1(S) ssGetSFcnParam(S, 1)
#define MDL_INITIALIZE_CONDITIONS
#define MDL_UPDATE 


#define CAN_MAX_TRY 20

#include "socketcan.h"
#include "simstruc.h"


int s = -1;
struct can_listener *head = NULL;

struct can_listener
{
    int id;

    int has_frame;
    struct can_frame frame;

    struct can_listener *next;
};

int open_port(const char *port)
{
    struct ifreq ifr;
    struct sockaddr_can addr;
    s = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    
    if (s < 0)
    {
        return -1;
    }

    addr.can_family = AF_CAN;
    strcpy(ifr.ifr_name, port);

    if (ioctl(s, SIOCGIFINDEX, &ifr) < 0)
    {
        return -1;
    }

    addr.can_ifindex = ifr.ifr_ifindex;
    fcntl(s, F_SETFL, O_NONBLOCK);

    if (bind(s, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        return -1;
    }

    return 0;
}


void CAN_init(int port)
{
    switch (port)
    {
        case 1:  open_port("can0");
                 printf("openPort can0\n");
                 break;
        case 2:  open_port("can1");
                 printf("openPort can1\n");
                 break;
        default: open_port("can0");
                 printf("unguetige Eingabe:\n");
                 printf("openPort can0\n");
    }
}


int read_port(struct can_frame *frame)
{
    static struct timeval timeout = {1, 0};
    fd_set readSet;
    FD_ZERO(&readSet);
    FD_SET(s, &readSet);

    if (select((s + 1), &readSet, NULL, NULL, &timeout) >= 0)
    {
        if (FD_ISSET(s, &readSet))
        {
            int recvbytes = read(s, frame, sizeof(struct can_frame));

            if (recvbytes == sizeof(struct can_frame))
                return 0;
            else
                return -1;
        }
    }
}

int close_port()
{
    close(s);
    return 0;
}


void find_msg(int id, uint8_T *data)
{
    int cnt = 0;

    struct can_frame frame;

    struct can_listener *ptr = head;
    
    while (ptr)
    {
        if (ptr->id == id)
        {
            if (ptr->has_frame)
            {
                memcpy(data, &ptr->frame.data[0], 2);
                ptr->has_frame = 0;
                
                return;
            }
            break;
        }
        
        ptr = ptr->next;
    }
    
    do {
        if (read_port(&frame) == 0)
        {
            if (frame.can_id == id)
            {
                memcpy(data, &frame.data[0], 2);
                return;
            }
            
            struct can_listener* ptr = head;

            while (ptr)
            {
                if (ptr->id == frame.can_id)
                {
                    memcpy(&(ptr->frame), &frame, sizeof(struct can_frame));
                    ptr->has_frame = 1;

                    break;
                }

                ptr = ptr->next;
            }
        }
    } while (++cnt < CAN_MAX_TRY);
}

/*Modellparametrierung*/

static void mdlInitializeSizes(SimStruct *S)
{
    ssSetNumSFcnParams(S, 2);                               
    
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return; 
    }
    
    ssSetNumDiscStates(S, 1);
    
    //Eingaenge
    if (!ssSetNumInputPorts(S, 1)) return;                                 //Anzahl der Eingaenge
    ssSetInputPortWidth(S, 0, DYNAMICALLY_SIZED);                          //Datenformat (Bei CAN_read.c durch Nullmatrix vorgegeben)
    ssSetInputPortDirectFeedThrough(S, 0, 1);        

    //Ausgaenge
    if (!ssSetNumOutputPorts(S,1)) return;                                 //Anzahl der Ausgaenge
    ssSetOutputPortWidth(S, 0, DYNAMICALLY_SIZED);   
    ssSetOutputPortDataType(S, 0, SS_UINT8);        
    
    ssSetNumSampleTimes(S, 1);                                             //Eine Sampletime fuer alle Ports
    ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);
}


static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, -1);                          //Einstellung Sampletime INHERITED_SAMPLE_TIME
    ssSetOffsetTime(S, 0, 0.0);
}

static void mdlInitializeConditions(SimStruct *S)
{
    real_T *xD = ssGetRealDiscStates(S);
    xD[0] = 0;
}

static void mdlOutputs(SimStruct *S, int_T tid)
{
 
    const real_T *xD = ssGetDiscStates(S);
    uint8_T *data = (uint8_T *) ssGetOutputPortSignal(S, 0);            
    const real_T *Identifier = (const real_T *)mxGetData(PARAM_DEF1(S));
    
    if (xD[0] == 1)
    {  

        find_msg((int)Identifier[0], data);
    }
}


static void mdlUpdate(SimStruct *S, int_T tid)
{
    real_T *xD = ssGetDiscStates(S);
    const real_T *Port = (const real_T *) mxGetData(PARAM_DEF0(S));
    const real_T *Identifier = (const real_T *)mxGetData(PARAM_DEF1(S));
    
    if (xD[0] != 1)
    {
        if (s == -1)
            CAN_init((int)Port[0]);

        xD[0] = 1;

        struct can_listener *listener = malloc(sizeof(struct can_listener));
        
        memset(listener, 0, sizeof(struct can_listener));

        listener->id = (int)Identifier[0];

        printf("Registering listener %d\n", listener->id);
        
        if (head == NULL)
        {
            head = listener;
            printf("Inserted id %d into head\n", listener->id);
        }
        else
        {
            struct can_listener **ptr = &head;

            while ((*ptr)->next)
            {
                printf("Iterating over %d...\n", (*ptr)->id);
                ptr = &((*ptr)->next);
            }
            
            (*ptr)->next = listener;
            printf("Inserted id %d into next\n", listener->id);
        }
    }
}


static void mdlTerminate(SimStruct *S){}

#ifdef MATLAB_MEX_FILE 
#include "simulink.c" 
#else
#include "cg_sfun.h" 
#endif