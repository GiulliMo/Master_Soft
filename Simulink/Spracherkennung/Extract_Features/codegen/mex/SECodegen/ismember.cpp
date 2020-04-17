//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  ismember.cpp
//
//  Code generation for function 'ismember'
//


// Include files
#include "ismember.h"
#include "DeepLearningNetwork.h"
#include "SECodegen.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Declarations
static int32_T bsearchni(int32_T k, const real_T x_data[]);

// Function Definitions
static int32_T bsearchni(int32_T k, const real_T x_data[])
{
  int32_T idx;
  real_T x;
  int32_T ilo;
  boolean_T exitg1;
  x = x_data[k - 1];
  idx = 0;
  ilo = 1;
  exitg1 = false;
  while ((!exitg1) && (16 >= ilo)) {
    ilo = (ilo >> 1) + 8;
    if (x == 0.0) {
      idx = ilo;
      exitg1 = true;
    } else {
      ilo++;
    }
  }

  if (idx > 0) {
    idx--;
    while ((idx > 0) && (x == 0.0)) {
      idx--;
    }

    idx++;
  }

  return idx;
}

void local_ismember(const emlrtStack *sp, const real_T a_data[], const int32_T
                    a_size[2], boolean_T tf_data[], int32_T tf_size[2])
{
  int8_T unnamed_idx_1;
  int32_T loop_ub;
  int32_T n;
  unnamed_idx_1 = static_cast<int8_T>(a_size[1]);
  tf_size[0] = 1;
  tf_size[1] = unnamed_idx_1;
  loop_ub = unnamed_idx_1;
  if (0 <= loop_ub - 1) {
    memset(&tf_data[0], 0, loop_ub * sizeof(boolean_T));
  }

  loop_ub = a_size[1] - 1;
  emlrtEnterParallelRegion(sp, omp_in_parallel());

#pragma omp parallel for \
 num_threads(emlrtAllocRegionTLSs(sp->tls, omp_in_parallel(), omp_get_max_threads(), omp_get_num_procs())) \
 private(n)

  for (int32_T k = 0; k <= loop_ub; k++) {
    n = bsearchni(k + 1, a_data);
    if (n > 0) {
      tf_data[k] = true;
    }
  }

  emlrtExitParallelRegion(sp, omp_in_parallel());
}

// End of code generation (ismember.cpp)
