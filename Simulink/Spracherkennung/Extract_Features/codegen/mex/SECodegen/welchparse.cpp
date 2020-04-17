//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  welchparse.cpp
//
//  Code generation for function 'welchparse'
//


// Include files
#include "welchparse.h"
#include "DeepLearningNetwork.h"
#include "SECodegen.h"
#include "ifWhileCond.h"
#include "psdoptions.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include <string.h>

// Variable Definitions
static emlrtRSInfo bb_emlrtRSI = { 359,// lineNo
  "welch_options",                     // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/private/welchparse.m"// pathName 
};

static emlrtRSInfo cb_emlrtRSI = { 58, // lineNo
  "psdoptions",                        // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/psdoptions.m"// pathName
};

static emlrtRSInfo db_emlrtRSI = { 104,// lineNo
  "psdoptions",                        // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/psdoptions.m"// pathName
};

static emlrtRSInfo eb_emlrtRSI = { 109,// lineNo
  "psdoptions",                        // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/psdoptions.m"// pathName
};

static emlrtRSInfo fb_emlrtRSI = { 111,// lineNo
  "psdoptions",                        // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/psdoptions.m"// pathName
};

static emlrtRSInfo gb_emlrtRSI = { 113,// lineNo
  "psdoptions",                        // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/psdoptions.m"// pathName
};

static emlrtRSInfo hb_emlrtRSI = { 121,// lineNo
  "psdoptions",                        // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/psdoptions.m"// pathName
};

static emlrtRSInfo ib_emlrtRSI = { 135,// lineNo
  "psdoptions",                        // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/psdoptions.m"// pathName
};

static emlrtRSInfo jb_emlrtRSI = { 151,// lineNo
  "psdoptions",                        // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/psdoptions.m"// pathName
};

static emlrtRSInfo kb_emlrtRSI = { 166,// lineNo
  "psdoptions",                        // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/psdoptions.m"// pathName
};

static emlrtRSInfo lb_emlrtRSI = { 179,// lineNo
  "psdoptions",                        // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/psdoptions.m"// pathName
};

static emlrtRSInfo mb_emlrtRSI = { 181,// lineNo
  "psdoptions",                        // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/psdoptions.m"// pathName
};

static emlrtRSInfo nb_emlrtRSI = { 191,// lineNo
  "psdoptions",                        // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/psdoptions.m"// pathName
};

static emlrtRSInfo ob_emlrtRSI = { 193,// lineNo
  "psdoptions",                        // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/psdoptions.m"// pathName
};

static emlrtRSInfo pb_emlrtRSI = { 199,// lineNo
  "psdoptions",                        // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/psdoptions.m"// pathName
};

static emlrtRSInfo qb_emlrtRSI = { 216,// lineNo
  "psdoptions",                        // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/psdoptions.m"// pathName
};

static emlrtRSInfo rb_emlrtRSI = { 21, // lineNo
  "eml_switch_helper",                 // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"// pathName 
};

static emlrtRTEInfo i_emlrtRTEI = { 87,// lineNo
  23,                                  // colNo
  "check_switch_expression",           // fName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"// pName 
};

static emlrtRTEInfo j_emlrtRTEI = { 366,// lineNo
  5,                                   // colNo
  "ConstructErrorObj",                 // fName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/psdoptions.m"// pName
};

// Function Definitions
void welch_options(const emlrtStack *sp, boolean_T *options1_centerdc, char_T
                   options1_range[8])
{
  boolean_T options_centerdc;
  cell_wrap_0 r;
  cell_wrap_0 r1;
  int32_T ii;
  cell_wrap_0 r2;
  char_T options_range[8];
  static const char_T t0_range[8] = { 'o', 'n', 'e', 's', 'i', 'd', 'e', 'd' };

  static const char_T b_cv[8] = { 'o', 'n', 'e', 's', 'i', 'd', 'e', 'd' };

  cell_wrap_0 r3;
  cell_wrap_0 r4;
  cell_wrap_0 r5;
  static const char_T cv1[5] = { 'a', 'd', 'a', 'p', 't' };

  static const char_T cv2[5] = { 'u', 'n', 'i', 't', 'y' };

  cell_wrap_0 r6;
  cell_wrap_0 r7;
  cell_wrap_0 r8;
  static const char_T cv3[5] = { 'w', 'h', 'o', 'l', 'e' };

  cell_wrap_0 r9;
  static const char_T cv4[8] = { 't', 'w', 'o', 's', 'i', 'd', 'e', 'd' };

  cell_wrap_0 r10;
  cell_wrap_0 r11;
  cell_wrap_0 r12;
  static const char_T cv5[5] = { 'e', 'i', 'g', 'e', 'n' };

  cell_wrap_0 r13;
  cell_wrap_0 exclusiveOpts[14];
  static const char_T cv6[8] = { 'c', 'e', 'n', 't', 'e', 'r', 'e', 'd' };

  int32_T idx;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T x[3];
  boolean_T result;
  static const boolean_T bv[19] = { false, true, false, false, false, false,
    false, false, false, false, false, false, false, false, false, false, false,
    false, false };

  boolean_T b_guard1 = false;
  int32_T i_size[2];
  int8_T ii_data[19];
  real_T i_data[19];
  int32_T case_expression_size[2];
  boolean_T case_expression_data[19];
  real_T visitedOpts[16];
  real_T b_index;
  int32_T tmp_size[2];
  static const int8_T varargin_6[8] = { 11, 12, 13, 14, 16, 17, 18, 19 };

  emlrtStack st;
  emlrtStack b_st;
  emlrtStack c_st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &bb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  options_centerdc = false;
  r.f1.size[0] = 1;
  r.f1.size[1] = 4;
  r.f1.data[0] = 'h';
  r.f1.data[1] = 'a';
  r.f1.data[2] = 'l';
  r.f1.data[3] = 'f';
  r1.f1.size[0] = 1;
  r1.f1.size[1] = 8;
  for (ii = 0; ii < 8; ii++) {
    options_range[ii] = t0_range[ii];
    r1.f1.data[ii] = b_cv[ii];
  }

  r2.f1.size[0] = 1;
  r2.f1.size[1] = 5;
  r3.f1.size[0] = 1;
  r3.f1.size[1] = 5;
  r4.f1.size[0] = 1;
  r4.f1.size[1] = 5;
  for (ii = 0; ii < 5; ii++) {
    r2.f1.data[ii] = cv1[ii];
    r3.f1.data[ii] = cv1[ii];
    r4.f1.data[ii] = cv2[ii];
  }

  r5.f1.size[0] = 1;
  r5.f1.size[1] = 4;
  r5.f1.data[0] = 'h';
  r5.f1.data[1] = 'a';
  r5.f1.data[2] = 'l';
  r5.f1.data[3] = 'f';
  r6.f1.size[0] = 1;
  r6.f1.size[1] = 8;
  for (ii = 0; ii < 8; ii++) {
    r6.f1.data[ii] = b_cv[ii];
  }

  r7.f1.size[0] = 1;
  r7.f1.size[1] = 5;
  for (ii = 0; ii < 5; ii++) {
    r7.f1.data[ii] = cv3[ii];
  }

  r8.f1.size[0] = 1;
  r8.f1.size[1] = 8;
  for (ii = 0; ii < 8; ii++) {
    r8.f1.data[ii] = cv4[ii];
  }

  r9.f1.size[0] = 1;
  r9.f1.size[1] = 5;
  r10.f1.size[0] = 1;
  r10.f1.size[1] = 5;
  r11.f1.size[0] = 1;
  r11.f1.size[1] = 5;
  for (ii = 0; ii < 5; ii++) {
    r9.f1.data[ii] = cv2[ii];
    r10.f1.data[ii] = cv5[ii];
    r11.f1.data[ii] = cv5[ii];
  }

  r12.f1.size[0] = 1;
  r12.f1.size[1] = 8;
  r13.f1.size[0] = 1;
  r13.f1.size[1] = 8;
  for (ii = 0; ii < 8; ii++) {
    r12.f1.data[ii] = cv6[ii];
    r13.f1.data[ii] = cv6[ii];
  }

  exclusiveOpts[0] = r;
  exclusiveOpts[1] = r1;
  exclusiveOpts[2] = r2;
  exclusiveOpts[3] = r3;
  exclusiveOpts[4] = r4;
  exclusiveOpts[5] = r5;
  exclusiveOpts[6] = r6;
  exclusiveOpts[7] = r7;
  exclusiveOpts[8] = r8;
  exclusiveOpts[9] = r9;
  exclusiveOpts[10] = r10;
  exclusiveOpts[11] = r11;
  exclusiveOpts[12] = r12;
  exclusiveOpts[13] = r13;
  idx = 0;
  guard1 = false;
  guard2 = false;
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (idx < 7) {
      boolean_T exitg2;
      b_strcmp(exclusiveOpts[idx].f1.data, exclusiveOpts[idx].f1.size, x);
      result = false;
      ii = 0;
      exitg2 = false;
      while ((!exitg2) && (ii < 3)) {
        if (x[ii]) {
          result = true;
          exitg2 = true;
        } else {
          ii++;
        }
      }

      if (result) {
        b_strcmp(exclusiveOpts[idx + 7].f1.data, exclusiveOpts[idx + 7].f1.size,
                 x);
        result = false;
        ii = 0;
        exitg2 = false;
        while ((!exitg2) && (ii < 3)) {
          if (x[ii]) {
            result = true;
            exitg2 = true;
          } else {
            ii++;
          }
        }

        if (result) {
          b_st.site = &cb_emlrtRSI;
          emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
            "signal:psdoptions:ConflictingOptions",
            "signal:psdoptions:ConflictingOptions", 6, 4, exclusiveOpts[idx].
            f1.size[1], &exclusiveOpts[idx].f1.data[0], 4, exclusiveOpts[idx + 7]
            .f1.size[1], &exclusiveOpts[idx + 7].f1.data[0]);
        } else {
          b_guard1 = true;
        }
      } else {
        b_guard1 = true;
      }

      if (b_guard1) {
        idx++;
        guard1 = false;
        guard2 = false;
      }
    } else {
      boolean_T exitg2;
      idx = 0;
      ii = 0;
      exitg2 = false;
      while ((!exitg2) && (ii < 19)) {
        if (bv[ii]) {
          idx++;
          ii_data[idx - 1] = static_cast<int8_T>(ii + 1);
          if (idx >= 19) {
            exitg2 = true;
          } else {
            ii++;
          }
        } else {
          ii++;
        }
      }

      if (1 > idx) {
        idx = 0;
      }

      i_size[0] = 1;
      i_size[1] = idx;
      for (ii = 0; ii < idx; ii++) {
        i_data[ii] = ii_data[ii];
      }

      if (idx > 1) {
        b_st.site = &db_emlrtRSI;
        emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
          "signal:psdoptions:UnknStringOption",
          "signal:psdoptions:UnknStringOption", 0);
      } else {
        int32_T exitg5;
        b_st.site = &eb_emlrtRSI;
        c_st.site = &rb_emlrtRSI;
        if (idx != 1) {
          emlrtErrorWithMessageIdR2018a(&c_st, &i_emlrtRTEI,
            "Coder:builtins:SwitchExpression", "Coder:builtins:SwitchExpression",
            0);
        }

        idx = 0;
        do {
          exitg5 = 0;
          if (idx < 4) {
            result = false;
            case_expression_size[0] = 1;
            case_expression_size[1] = 1;
            case_expression_data[0] = (idx + 1 == static_cast<int32_T>(i_data[0]));
            if (ifWhileCond(case_expression_data, case_expression_size)) {
              result = true;
            }

            if (result) {
              idx = 0;
              exitg5 = 1;
            } else {
              idx++;
            }
          } else {
            idx = 0;
            exitg5 = 2;
          }
        } while (exitg5 == 0);

        if (exitg5 != 1) {
          int32_T exitg4;
          do {
            exitg4 = 0;
            if (idx < 3) {
              result = false;
              case_expression_size[0] = 1;
              case_expression_size[1] = 1;
              case_expression_data[0] = (idx + 5 == static_cast<int32_T>(i_data
                [0]));
              if (ifWhileCond(case_expression_data, case_expression_size)) {
                result = true;
              }

              if (result) {
                idx = 1;
                exitg4 = 1;
              } else {
                idx++;
              }
            } else {
              result = false;
              case_expression_size[0] = 1;
              case_expression_size[1] = 1;
              case_expression_data[0] = (8.0 == i_data[0]);
              if (ifWhileCond(case_expression_data, case_expression_size)) {
                result = true;
              }

              exitg4 = 2;
            }
          } while (exitg4 == 0);

          if (exitg4 != 1) {
            if (result) {
              idx = 2;
            } else {
              result = false;
              case_expression_size[0] = 1;
              case_expression_size[1] = 1;
              case_expression_data[0] = (9.0 == i_data[0]);
              if (ifWhileCond(case_expression_data, case_expression_size)) {
                result = true;
              }

              if (result) {
                idx = 3;
              } else {
                result = false;
                case_expression_size[0] = 1;
                case_expression_size[1] = 1;
                case_expression_data[0] = (10.0 == i_data[0]);
                if (ifWhileCond(case_expression_data, case_expression_size)) {
                  result = true;
                }

                if (result) {
                  idx = 4;
                } else {
                  idx = 0;
                  int32_T exitg3;
                  do {
                    exitg3 = 0;
                    if (idx < 8) {
                      result = false;
                      case_expression_size[0] = 1;
                      case_expression_size[1] = 1;
                      case_expression_data[0] = (varargin_6[idx] == static_cast<
                        int32_T>(i_data[0]));
                      if (ifWhileCond(case_expression_data, case_expression_size))
                      {
                        result = true;
                      }

                      if (result) {
                        idx = 5;
                        exitg3 = 1;
                      } else {
                        idx++;
                      }
                    } else {
                      result = false;
                      case_expression_size[0] = 1;
                      case_expression_size[1] = 1;
                      case_expression_data[0] = (15.0 == i_data[0]);
                      if (ifWhileCond(case_expression_data, case_expression_size))
                      {
                        result = true;
                      }

                      if (result) {
                        idx = 6;
                      } else {
                        idx = -1;
                      }

                      exitg3 = 1;
                    }
                  } while (exitg3 == 0);
                }
              }
            }
          }
        }

        switch (idx) {
         case 0:
          b_st.site = &fb_emlrtRSI;
          checkUniqueOpts(&b_st, i_data, i_size, &result, visitedOpts, &b_index);
          if (result) {
            b_st.site = &gb_emlrtRSI;
            emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
              "signal:psdoptions:MultipleValues",
              "signal:psdoptions:MultipleValues", 0);
          } else {
            case_expression_size[0] = 1;
            case_expression_size[1] = 1;
            case_expression_data[0] = (i_data[0] == 1.0);
            b_st.site = &hb_emlrtRSI;
            if (ifWhileCond(case_expression_data, case_expression_size)) {
              guard2 = true;
            } else {
              tmp_size[0] = 1;
              tmp_size[1] = 1;
              case_expression_data[0] = (case_expression_data[0] || (i_data[0] ==
                2.0));
              b_st.site = &hb_emlrtRSI;
              if (ifWhileCond(case_expression_data, tmp_size)) {
                guard2 = true;
              } else {
                for (ii = 0; ii < 8; ii++) {
                  options_range[ii] = cv4[ii];
                }

                guard1 = true;
              }
            }
          }
          break;

         case 1:
          b_st.site = &ib_emlrtRSI;
          emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
            "signal:psdoptions:UnrecognizedString",
            "signal:psdoptions:UnrecognizedString", 0);
          break;

         case 2:
          b_st.site = &jb_emlrtRSI;
          emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
            "signal:psdoptions:UnrecognizedString",
            "signal:psdoptions:UnrecognizedString", 0);
          break;

         case 3:
          b_st.site = &kb_emlrtRSI;
          emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
            "signal:psdoptions:UnrecognizedString",
            "signal:psdoptions:UnrecognizedString", 0);
          break;

         case 4:
          b_st.site = &lb_emlrtRSI;
          checkUniqueOpts(&b_st, i_data, i_size, &result, visitedOpts, &b_index);
          if (result) {
            b_st.site = &mb_emlrtRSI;
            emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
              "signal:psdoptions:MultipleValues",
              "signal:psdoptions:MultipleValues", 0);
          } else {
            options_centerdc = true;
            guard1 = true;
          }
          break;

         case 5:
          guard1 = true;
          break;

         case 6:
          b_st.site = &nb_emlrtRSI;
          checkUniqueOpts(&b_st, i_data, i_size, &result, visitedOpts, &b_index);
          if (result) {
            b_st.site = &ob_emlrtRSI;
            emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
              "signal:psdoptions:MultipleValues",
              "signal:psdoptions:MultipleValues", 0);
          } else {
            b_st.site = &pb_emlrtRSI;
            emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
              "signal:psdoptions:MissingConfLevelValue",
              "signal:psdoptions:MissingConfLevelValue", 0);
          }
          break;

         default:
          b_st.site = &qb_emlrtRSI;
          emlrtErrorWithMessageIdR2018a(&b_st, &j_emlrtRTEI,
            "signal:psdoptions:IdxOutOfBound", "signal:psdoptions:IdxOutOfBound",
            0);
          break;
        }
      }

      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (guard2) {
    for (ii = 0; ii < 8; ii++) {
      options_range[ii] = b_cv[ii];
    }

    guard1 = true;
  }

  if (guard1) {
    *options1_centerdc = options_centerdc;
    for (ii = 0; ii < 8; ii++) {
      options1_range[ii] = options_range[ii];
    }
  }
}

// End of code generation (welchparse.cpp)
