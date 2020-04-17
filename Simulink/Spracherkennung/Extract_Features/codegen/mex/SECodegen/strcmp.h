//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  strcmp.h
//
//  Code generation for function 'strcmp'
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
void b_strcmp(const char_T a_data[], const int32_T a_size[2], boolean_T b_bool[3]);
boolean_T c_strcmp(const char_T a[8]);

// End of code generation (strcmp.h)
