//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  mtimes.cpp
//
//  Code generation for function 'mtimes'
//


// Include files
#include "mtimes.h"
#include "DeepLearningNetwork.h"
#include "SECodegen.h"
#include "blas.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
void mtimes(const real_T A[12850], const coder::array<real_T, 2U> &B, real_T C
            [4900])
{
  char_T TRANSB1;
  char_T TRANSA1;
  real_T alpha1;
  real_T beta1;
  ptrdiff_t m_t;
  ptrdiff_t n_t;
  ptrdiff_t k_t;
  ptrdiff_t lda_t;
  ptrdiff_t ldb_t;
  ptrdiff_t ldc_t;
  TRANSB1 = 'N';
  TRANSA1 = 'N';
  alpha1 = 1.0;
  beta1 = 0.0;
  m_t = (ptrdiff_t)50;
  n_t = (ptrdiff_t)98;
  k_t = (ptrdiff_t)257;
  lda_t = (ptrdiff_t)50;
  ldb_t = (ptrdiff_t)B.size(0);
  ldc_t = (ptrdiff_t)50;
  dgemm(&TRANSA1, &TRANSB1, &m_t, &n_t, &k_t, &alpha1, (real_T *)&A[0], &lda_t,
        &(((coder::array<real_T, 2U> *)&B)->data())[0], &ldb_t, &beta1, &C[0],
        &ldc_t);
}

// End of code generation (mtimes.cpp)
