//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  psdfreqvec.h
//
//  Code generation for function 'psdfreqvec'
//


#pragma once

// Include files
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "mex.h"
#include "emlrt.h"
#include "rtwtypes.h"
#include "omp.h"
#include "SECodegen_types.h"
#define MAX_THREADS                    omp_get_max_threads()

// Function Declarations
void b_psdfreqvec(real_T w_data[], int32_T w_size[1]);
void psdfreqvec(real_T w_data[], int32_T w_size[1]);

// End of code generation (psdfreqvec.h)
