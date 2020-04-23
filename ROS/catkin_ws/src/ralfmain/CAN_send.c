//S-Function Beispiel
//Uebersetzen durch: mex <SFUNCTION_NAME>.c

#define S_FUNCTION_NAME CAN_send /* Defines and Includes */
#define S_FUNCTION_LEVEL 2

#include "socketcan.h"
#include "simstruc.h"

#define PARAM_DEF0(S) ssGetSFcnParam(S, 0)
#define PARAM_DEF1(S) ssGetSFcnParam(S, 1)




int soc;
int read_can_port;

int open_port(const char *port)
{
    struct ifreq ifr;
    struct sockaddr_can addr;

    /* open socket */
    soc = socket(PF_CAN, SOCK_RAW, CAN_RAW);
    if(soc < 0)
    {
        return (-1);
    }

    addr.can_family = AF_CAN;
    strcpy(ifr.ifr_name, port);

    if (ioctl(soc, SIOCGIFINDEX, &ifr) < 0)
    {

        return (-1);
    }

    addr.can_ifindex = ifr.ifr_ifindex;

    fcntl(soc, F_SETFL, O_NONBLOCK);

    if (bind(soc, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {

        return (-1);
    }

    return 0;
}

void CAN_init(int Port){
    switch(Port)
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

int send_port(struct can_frame *frame)
{
    int retval;
   retval = write(soc, frame, sizeof(struct can_frame));
    if (retval != sizeof(struct can_frame))
    {
        return (-1);
    }
    else
    {
        return (0);
    }
}

/* this is just an example, run in a thread */
void read_port(struct can_frame *frame)
{
    int recvbytes = 0;

    read_can_port = 1;
        struct timeval timeout = {1, 0};
        fd_set readSet;
        FD_ZERO(&readSet);
        FD_SET(soc, &readSet);

        if (select((soc + 1), &readSet, NULL, NULL, &timeout) >= 0)
        {
            if (FD_ISSET(soc, &readSet))
            {
                recvbytes = read(soc, frame, sizeof(struct can_frame));
            }
        }

}

int close_port()
{
    close(soc);
    return 0;
}






/*Parameter, Ein- und Ausgaenge festlegen*/
static void mdlInitializeSizes(SimStruct *S)
{
    //Parameter
    ssSetNumSFcnParams(S, 2);
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return; /* Parameter mismatch reported by the Simulink engine*/
    }
    
    //Statische Konstanten
    ssSetNumDiscStates(S, 1);
    
    //Eingaenge
    if (!ssSetNumInputPorts(S, 1)) return;          /*Anzahl der Eingaenge*/
    ssSetInputPortWidth(S, 0, DYNAMICALLY_SIZED);   /*Eingang 0 -> dynamische groesse*/
    ssSetInputPortDirectFeedThrough(S, 0, 1);       /*Eingang 0 wird periodisch in mdlOutputs abgefragt*/
    ssSetInputPortDataType(S, 0, SS_UINT8);        /*Eingang 0 wird als double interpretiert*/
    ssSetInputPortRequiredContiguous(S, 0, 1);      /*direct input signal access*/

    ssSetNumSampleTimes(S, 1);  /*Fuer alle Ports gilt die gleiche Sampletime*/

    /* Take care when specifying exception free code - see sfuntmpl.doc */
    ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);
}

/*Sampletime einstellen*/
static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, -1);                               /*INHERITED_SAMPLE_TIME*/
    ssSetOffsetTime(S, 0, 0.0);
}

#define MDL_INITIALIZE_CONDITIONS
/* Function: mdlInitializeConditions ========================================
 * Abstract:
 *    Initialize the states
 */
static void mdlInitializeConditions(SimStruct *S)
{
    real_T *xD = ssGetRealDiscStates(S);

    xD[0] = 0;
}

/*Wird zyklisch aufgerufen*/
static void mdlOutputs(SimStruct *S, int_T tid)
{
    const int8_T *message = (const int8_T *) ssGetInputPortSignal(S, 0);
    const real_T *xD = ssGetDiscStates(S);
    const real_T *Port = (const real_T *) mxGetData(PARAM_DEF0(S));
    const real_T *Identifier = (const real_T *) mxGetData(PARAM_DEF1(S));
    const int_T u_width = ssGetInputPortWidth(S, 0);
    int_T width = ssGetInputPortWidth(S,0); 
    
    if(xD[0]==1){  
    //CAN senden
        //printf("Identifier_send: %d\n",(int)Identifier[0]);
		struct can_frame frame;
		frame.can_id = (int)Identifier[0];
        //printf("can_id_send: %d\n",frame.can_id);
        int i;
        /*for(i=0;i<width;i++){
            frame.data[i] = message[i];
            //printf("message send %u: %u\n",i,frame.data[i]);
        }*/
        frame.data[0] = message[0];
        frame.data[1] = message[1];
		frame.can_dlc = width;
		
		send_port(&frame);
        
    
    }   
}

#define MDL_UPDATE  /* Change to #undef to remove function */
/* Function: mdlUpdate ======================================================
 * Abstract:
 *    This function is called once for every major integration time step.
 *    Discrete states are typically updated here, but this function is useful
 *    for performing any tasks that should only take place once per
 *    integration step.
 */
static void mdlUpdate(SimStruct *S, int_T tid)
{
    real_T *xD = ssGetDiscStates(S);
    const uint8_T *message = (const uint8_T *) ssGetInputPortSignal(S, 0);
    const real_T *Port = (const real_T *) mxGetData(PARAM_DEF0(S));
    const real_T *Identifier = (const real_T *) mxGetData(PARAM_DEF1(S));
    const int_T u_width = ssGetInputPortWidth(S, 0);

    if(xD[0]!=1){   
        CAN_init((int)Port[0]);
        xD[0]=1;
    }
}

/*Wird beim Beenden des Programm ausgefuehrt*/
static void mdlTerminate(SimStruct *S){}

#ifdef MATLAB_MEX_FILE /* Is this file being compiled as a MEX-file? */
#include "simulink.c" /* MEX-file interface mechanism */
#else
#include "cg_sfun.h" /* Code generation registration function */
#endif