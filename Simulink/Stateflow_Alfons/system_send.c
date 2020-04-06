//S-Function Beispiel
//Uebersetzen durch: mex <SFUNCTION_NAME>.c

#define S_FUNCTION_NAME system_send/* Defines and Includes */
#define S_FUNCTION_LEVEL 2


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"
#include "simstruc.h"



// #define SHELLSCRIPT "\
// #! /bin/sh/\n\
// cd ~\n\
// ./launch.sh"

// #define SHELLSCRIPT "\
// #! /bin/sh/\n\
// cd ~/Documents\n\
// ./launch.sh"
 

/*Parameter, Ein- und Ausgaenge festlegen*/
static void mdlInitializeSizes(SimStruct *S)
{
    ssSetNumSFcnParams(S, 2);
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        return; /* Parameter mismatch will be reported by Simulink */
    }
    
    //Eingaenge
    if (!ssSetNumInputPorts(S, 1)) return;          /*Anzahl der Eingaenge*/
    ssSetInputPortWidth(S, 0, DYNAMICALLY_SIZED);   /*Eingang 0 -> dynamische groesse*/
    ssSetInputPortDirectFeedThrough(S, 0, 1);       /*Eingang 0 wird periodisch in mdlOutputs abgefragt*/

    ssSetNumSampleTimes(S, 1);  /*Fuer alle Ports gilt die gleiche Sampletime*/

    /* Take care when specifying exception free code - see sfuntmpl.doc */
    ssSetOptions(S, SS_OPTION_EXCEPTION_FREE_CODE);
    ssSetNumSFcnParams(S, 2);  /* Number of expected parameters */
    
}

/*Sampletime einstellen*/
static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, INHERITED_SAMPLE_TIME);
    ssSetOffsetTime(S, 0, 0.0);
}


/*Auslesen S-Function Parameter*/

static char *myString(const mxArray* mxPrm)
{
    char * String;
    int_T status;
    int_T buflen;
    buflen = mxGetN((mxPrm))*sizeof(mxChar)+1;
    String = mxMalloc(buflen);
    status = mxGetString((mxPrm), String,buflen);  
    return String;
   
 }

/*Wird zyklisch aufgerufen*/
static void mdlOutputs(SimStruct *S, int_T tid)
{
    int_T i;
    InputRealPtrsType uPtrs = ssGetInputPortRealSignalPtrs(S,0);
    real_T *y = ssGetOutputPortRealSignal(S,0);
    int_T width = ssGetOutputPortWidth(S,0);
    
  //  mexPrintf("The string being passed as a Paramater is - %s\n ", myString(ssGetSFcnParam(S, 0)));          
  //  mexPrintf("The string being passed as a Paramater is - %s\n ", myString(ssGetSFcnParam(S, 1)));
       
    char textA[100]="\#! /bin/sh";
    char textB[100]="\n\cd ";
    char textD[100]=" \n\ ";
    
    #define Script strcat(strcat(textA,strcat(textB,myString(ssGetSFcnParam(S, 0)))),strcat(textD,myString(ssGetSFcnParam(S, 1))))
    
    
    if(*uPtrs>0)
     {
        puts("Will execute sh with the following script :");
       // puts(Script);
        puts("Starting now:");
        system(Script);  
     }
         
}



/*Wird beim Beenden des Programm ausgefuehrt*/
static void mdlTerminate(SimStruct *S){}

#ifdef MATLAB_MEX_FILE /* Is this file being compiled as a MEX-file? */
#include "simulink.c" /* MEX-file interface mechanism */
#else
#include "cg_sfun.h" /* Code generation registration function */
#endif