//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  SECodegen_data.h
//
//  Code generation for function 'SECodegen_data'
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

// Variable Declarations
extern emlrtCTX emlrtRootTLSGlobal;
extern const volatile char_T *emlrtBreakCheckR2012bFlagVar;
extern omp_lock_t emlrtLockGlobal;
extern omp_nest_lock_t emlrtNestLockGlobal;
extern emlrtContext emlrtContextGlobal;
extern emlrtRSInfo i_emlrtRSI;
extern emlrtRSInfo j_emlrtRSI;
extern emlrtRSInfo m_emlrtRSI;
extern emlrtRSInfo o_emlrtRSI;
extern emlrtRSInfo sb_emlrtRSI;
extern emlrtRSInfo tb_emlrtRSI;
extern emlrtRSInfo ub_emlrtRSI;
extern emlrtRSInfo vb_emlrtRSI;
extern emlrtRSInfo wb_emlrtRSI;
extern emlrtRSInfo cc_emlrtRSI;
extern emlrtRSInfo lc_emlrtRSI;
extern emlrtRSInfo mc_emlrtRSI;
extern emlrtRSInfo nc_emlrtRSI;
extern emlrtRSInfo oc_emlrtRSI;
extern emlrtRSInfo pc_emlrtRSI;
extern emlrtRSInfo qc_emlrtRSI;
extern emlrtRSInfo sc_emlrtRSI;
extern emlrtRSInfo vc_emlrtRSI;
extern emlrtRSInfo wc_emlrtRSI;
extern emlrtRSInfo xc_emlrtRSI;
extern emlrtRSInfo fd_emlrtRSI;
extern emlrtRSInfo hd_emlrtRSI;
extern emlrtRSInfo ud_emlrtRSI;
extern emlrtRSInfo vd_emlrtRSI;
extern emlrtRSInfo wd_emlrtRSI;
extern emlrtRSInfo be_emlrtRSI;
extern emlrtRSInfo ce_emlrtRSI;
extern emlrtRSInfo de_emlrtRSI;
extern emlrtRSInfo ee_emlrtRSI;
extern emlrtRSInfo ge_emlrtRSI;
extern emlrtRSInfo je_emlrtRSI;
extern emlrtRSInfo ke_emlrtRSI;
extern emlrtRSInfo le_emlrtRSI;
extern emlrtRSInfo me_emlrtRSI;
extern emlrtRSInfo ne_emlrtRSI;
extern emlrtRSInfo oe_emlrtRSI;
extern emlrtRSInfo pe_emlrtRSI;
extern emlrtRSInfo qe_emlrtRSI;
extern const real_T dv[400];
extern const char_T cv[128];

#define MAX_THREADS                    omp_get_max_threads()

// End of code generation (SECodegen_data.h)
