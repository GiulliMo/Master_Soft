//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  SECodegen_data.cpp
//
//  Code generation for function 'SECodegen_data'
//


// Include files
#include "SECodegen_data.h"
#include "SECodegen.h"
#include "rt_nonfinite.h"
#include <string.h>

// Variable Definitions
emlrtCTX emlrtRootTLSGlobal = NULL;
const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
omp_lock_t emlrtLockGlobal;
omp_nest_lock_t emlrtNestLockGlobal;
emlrtContext emlrtContextGlobal = { true,// bFirstTime
  false,                               // bInitialized
  131594U,                             // fVersionInfo
  NULL,                                // fErrorFunction
  "SECodegen",                         // fFunctionName
  NULL,                                // fRTCallStack
  false,                               // bDebugMode
  { 2026898844U, 2671121497U, 3797198563U, 950114688U },// fSigWrd
  NULL                                 // fSigMem
};

emlrtRSInfo i_emlrtRSI = { 1,          // lineNo
  "loadDeepLearningNetwork",           // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/shared/dlcoder_base/dlcoder_base/+coder/+internal/loadDeepLearningNetwork.p"// pathName 
};

emlrtRSInfo j_emlrtRSI = { 1,          // lineNo
  "DeepLearningNetwork/callSetup",     // fcnName
  "/home/alf/Documents/MATLAB/SupportPackages/R2020a/toolbox/shared/dlcoder_base/supportpackages/shared_dl_targets/+coder/@DeepLear"
  "ningNetwork/DeepLearningNetwork.p"  // pathName
};

emlrtRSInfo m_emlrtRSI = { 34,         // lineNo
  "designMelFilterBank",               // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/audio/audio/+audio/+internal/designMelFilterBank.m"// pathName 
};

emlrtRSInfo o_emlrtRSI = { 28,         // lineNo
  "colon",                             // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/colon.m"// pathName
};

emlrtRSInfo sb_emlrtRSI = { 30,        // lineNo
  "eml_switch_helper",                 // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"// pathName 
};

emlrtRSInfo tb_emlrtRSI = { 37,        // lineNo
  "eml_switch_helper",                 // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"// pathName 
};

emlrtRSInfo ub_emlrtRSI = { 76,        // lineNo
  "eml_not_iscell_switch_helper",      // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"// pathName 
};

emlrtRSInfo vb_emlrtRSI = { 18,        // lineNo
  "ifWhileCond",                       // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/ifWhileCond.m"// pathName 
};

emlrtRSInfo wb_emlrtRSI = { 31,        // lineNo
  "checkNoNaNs",                       // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/ifWhileCond.m"// pathName 
};

emlrtRSInfo cc_emlrtRSI = { 190,       // lineNo
  "local_ismember",                    // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/ismember.m"// pathName
};

emlrtRSInfo lc_emlrtRSI = { 21,        // lineNo
  "fftw",                              // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/fftw.m"// pathName
};

emlrtRSInfo mc_emlrtRSI = { 15,        // lineNo
  "MATLABFFTWCallback/fft1d",          // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/+fft/MATLABFFTWCallback.m"// pathName 
};

emlrtRSInfo nc_emlrtRSI = { 44,        // lineNo
  "psdfreqvec",                        // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/shared/siglib/psdfreqvec.m"// pathName
};

emlrtRSInfo oc_emlrtRSI = { 70,        // lineNo
  "frequencygrid",                     // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/shared/siglib/psdfreqvec.m"// pathName
};

emlrtRSInfo pc_emlrtRSI = { 109,       // lineNo
  "NPTSinfo",                          // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/shared/siglib/psdfreqvec.m"// pathName
};

emlrtRSInfo qc_emlrtRSI = { 96,        // lineNo
  "NPTSinfo",                          // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/shared/siglib/psdfreqvec.m"// pathName
};

emlrtRSInfo sc_emlrtRSI = { 83,        // lineNo
  "frequencygrid",                     // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/shared/siglib/psdfreqvec.m"// pathName
};

emlrtRSInfo vc_emlrtRSI = { 38,        // lineNo
  "computepsd",                        // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/computepsd.m"// pathName
};

emlrtRSInfo wc_emlrtRSI = { 9,         // lineNo
  "isodd",                             // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/private/isodd.m"// pathName
};

emlrtRSInfo xc_emlrtRSI = { 12,        // lineNo
  "isodd",                             // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/shared/signalwavelet/signalwavelet/+signalwavelet/+internal/isodd.m"// pathName 
};

emlrtRSInfo fd_emlrtRSI = { 16,        // lineNo
  "centerest",                         // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/signal/signal/private/centerest.m"// pathName 
};

emlrtRSInfo hd_emlrtRSI = { 12,        // lineNo
  "iseven",                            // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/shared/signalwavelet/signalwavelet/+signalwavelet/+internal/iseven.m"// pathName 
};

emlrtRSInfo ud_emlrtRSI = { 16,        // lineNo
  "fftshift",                          // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/fftshift.m"// pathName 
};

emlrtRSInfo vd_emlrtRSI = { 165,       // lineNo
  "eml_fftshift",                      // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/private/eml_fftshift.m"// pathName 
};

emlrtRSInfo wd_emlrtRSI = { 143,       // lineNo
  "eml_fftshift",                      // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/datafun/private/eml_fftshift.m"// pathName 
};

emlrtRSInfo be_emlrtRSI = { 168,       // lineNo
  "mtimes",                            // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/+blas/mtimes.m"// pathName 
};

emlrtRSInfo ce_emlrtRSI = { 164,       // lineNo
  "mtimes",                            // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/+blas/mtimes.m"// pathName 
};

emlrtRSInfo de_emlrtRSI = { 45,        // lineNo
  "mpower",                            // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/mpower.m"// pathName
};

emlrtRSInfo ee_emlrtRSI = { 70,        // lineNo
  "power",                             // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/power.m"// pathName
};

emlrtRSInfo ge_emlrtRSI = { 1,         // lineNo
  "DeepLearningNetwork/predict",       // fcnName
  "/home/alf/Documents/MATLAB/SupportPackages/R2020a/toolbox/shared/dlcoder_base/supportpackages/shared_dl_targets/+coder/@DeepLear"
  "ningNetwork/predict.p"              // pathName
};

emlrtRSInfo je_emlrtRSI = { 644,       // lineNo
  "categorical/initData",              // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/matlab/datatypes/codegen/categorical/+matlab/+internal/+coder/@categorical/categorical.m"// pathName 
};

emlrtRSInfo ke_emlrtRSI = { 113,       // lineNo
  "categorical/getCategoryNames",      // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/matlab/datatypes/codegen/categorical/+matlab/+internal/+coder/@categorical/getCategoryNames.m"// pathName 
};

emlrtRSInfo le_emlrtRSI = { 114,       // lineNo
  "categorical/getCategoryNames",      // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/matlab/datatypes/codegen/categorical/+matlab/+internal/+coder/@categorical/getCategoryNames.m"// pathName 
};

emlrtRSInfo me_emlrtRSI = { 115,       // lineNo
  "categorical/getCategoryNames",      // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/matlab/datatypes/codegen/categorical/+matlab/+internal/+coder/@categorical/getCategoryNames.m"// pathName 
};

emlrtRSInfo ne_emlrtRSI = { 124,       // lineNo
  "categorical/getCategoryNames",      // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/matlab/datatypes/codegen/categorical/+matlab/+internal/+coder/@categorical/getCategoryNames.m"// pathName 
};

emlrtRSInfo oe_emlrtRSI = { 61,        // lineNo
  "strcmp",                            // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/strcmp.m"// pathName 
};

emlrtRSInfo pe_emlrtRSI = { 104,       // lineNo
  "loc_strcmp",                        // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/eml/+coder/+internal/strcmp.m"// pathName 
};

emlrtRSInfo qe_emlrtRSI = { 13,        // lineNo
  "all",                               // fcnName
  "/usr/local/MATLAB/R2020a/toolbox/eml/lib/matlab/ops/all.m"// pathName
};

const real_T dv[400] = { 0.0, 6.1683759169706143E-5, 0.0002467198171342,
  0.00055506251901499271, 0.00098663578586422052, 0.0015413331334360181,
  0.0022190176984600019, 0.0030195222724101467, 0.003942649342761062,
  0.0049881711417212315, 0.0061558297024311148, 0.0074453369226130661,
  0.00885637463565564, 0.010388594689117125, 0.012041619030626283,
  0.013815039801161721, 0.015708419435684462, 0.017721290771100962,
  0.019853157161528467, 0.02210349260083494, 0.024471741852423234,
  0.026957320586227351, 0.029559615522887273, 0.032277984585066366,
  0.035111757055874271, 0.038060233744356631, 0.04112268715800943,
  0.044298361682277354, 0.047586473766990267, 0.050986212119692176,
  0.054496737905816051, 0.058117184955653267, 0.061846659978068208,
  0.0656842427809044, 0.069628986498028178, 0.073679917822953855,
  0.077836037248992462, 0.082096319315864863, 0.086459712862719085,
  0.0909251412874883, 0.095491502812526274, 0.10015767075645471,
  0.10492249381215479, 0.1097847963308351, 0.11474337861210537,
  0.11979701719998453, 0.12494446518477026, 0.1301844525106951,
  0.13551568628929422, 0.14093685111840554, 0.14644660940672621,
  0.15204360170384285, 0.15772644703565564, 0.16349374324511334,
  0.16934406733817409, 0.17527597583490823, 0.18128800512565518,
  0.18737867183214735, 0.1935464731735117, 0.19978988733705794,
  0.20610737385376343, 0.21249737397836072, 0.21895831107393471,
  0.2254885910009341, 0.23208660251050173, 0.23875071764202555,
  0.2454792921248144, 0.2522706657837962, 0.25912316294914239,
  0.26603509286971327, 0.27300475013022657, 0.2800304150720424,
  0.28711035421746367, 0.29424282069744556, 0.30142605468260975,
  0.30865828381745508, 0.31593772365766093, 0.3232625781103714,
  0.33063103987735426, 0.33804129090092527, 0.34549150281252627,
  0.35297983738384808, 0.36050444698038525, 0.36806347501731351,
  0.37565505641757252, 0.38327731807204724, 0.39092837930172863,
  0.39860635232174374, 0.40630934270713764, 0.41403544986029522,
  0.42178276747988452, 0.42954938403120868, 0.43733338321784787,
  0.44513284445447743, 0.45294584334074273, 0.46077045213607748,
  0.46860474023534326, 0.47644677464517865, 0.4842946204609358,
  0.49214634134408969, 0.49999999999999994, 0.50785365865591026,
  0.51570537953906415, 0.52355322535482129, 0.53139525976465674,
  0.53922954786392241, 0.54705415665925716, 0.55486715554552257,
  0.56266661678215213, 0.57045061596879132, 0.57821723252011548,
  0.58596455013970483, 0.59369065729286241, 0.60139364767825609,
  0.60907162069827114, 0.61672268192795254, 0.62434494358242731,
  0.63193652498268627, 0.63949555301961458, 0.64702016261615192,
  0.65450849718747373, 0.66195870909907462, 0.66936896012264568,
  0.67673742188962849, 0.684062276342339, 0.69134171618254481,
  0.69857394531739025, 0.70575717930255433, 0.71288964578253633,
  0.7199695849279576, 0.72699524986977337, 0.73396490713028661,
  0.74087683705085772, 0.7477293342162038, 0.75452070787518566,
  0.7612492823579744, 0.76791339748949849, 0.7745114089990659,
  0.78104168892606518, 0.78750262602163912, 0.79389262614623646,
  0.800210112662942, 0.80645352682648808, 0.81262132816785249,
  0.81871199487434487, 0.82472402416509172, 0.83065593266182591,
  0.83650625675488655, 0.84227355296434436, 0.8479563982961571,
  0.85355339059327373, 0.8590631488815943, 0.86448431371070567,
  0.8698155474893049, 0.8750555348152298, 0.88020298280001541,
  0.88525662138789452, 0.890215203669165, 0.89507750618784521,
  0.89984232924354524, 0.90450849718747373, 0.90907485871251181,
  0.913540287137281, 0.917903680684135, 0.92216396275100743, 0.92632008217704609,
  0.93037101350197182, 0.93431575721909554, 0.93815334002193174,
  0.94188281504434679, 0.94550326209418389, 0.94901378788030777,
  0.95241352623300968, 0.95570163831772259, 0.95887731284199051,
  0.96193976625564337, 0.96488824294412567, 0.96772201541493363,
  0.97044038447711278, 0.97304267941377265, 0.97552825814757682,
  0.977896507399165, 0.98014684283847153, 0.982278709228899, 0.98429158056431554,
  0.98618496019883828, 0.98795838096937372, 0.98961140531088287,
  0.99114362536434431, 0.99255466307738693, 0.99384417029756889,
  0.99501182885827877, 0.99605735065723888, 0.9969804777275898, 0.99778098230154,
  0.998458666866564, 0.99901336421413578, 0.999444937480985, 0.9997532801828658,
  0.99993831624083029, 1.0, 0.99993831624083029, 0.9997532801828658,
  0.999444937480985, 0.99901336421413578, 0.998458666866564, 0.99778098230154,
  0.9969804777275898, 0.99605735065723888, 0.99501182885827877,
  0.99384417029756889, 0.99255466307738693, 0.99114362536434431,
  0.98961140531088287, 0.98795838096937372, 0.98618496019883828,
  0.98429158056431554, 0.982278709228899, 0.98014684283847153, 0.977896507399165,
  0.97552825814757682, 0.97304267941377265, 0.97044038447711278,
  0.96772201541493363, 0.96488824294412567, 0.96193976625564337,
  0.95887731284199051, 0.95570163831772259, 0.95241352623300968,
  0.94901378788030777, 0.94550326209418389, 0.94188281504434679,
  0.93815334002193174, 0.93431575721909554, 0.93037101350197182,
  0.92632008217704609, 0.92216396275100743, 0.917903680684135, 0.913540287137281,
  0.90907485871251181, 0.90450849718747373, 0.89984232924354524,
  0.89507750618784521, 0.890215203669165, 0.88525662138789452,
  0.88020298280001541, 0.8750555348152298, 0.8698155474893049,
  0.86448431371070567, 0.8590631488815943, 0.85355339059327373,
  0.8479563982961571, 0.84227355296434436, 0.83650625675488655,
  0.83065593266182591, 0.82472402416509172, 0.81871199487434487,
  0.81262132816785249, 0.80645352682648808, 0.800210112662942,
  0.79389262614623646, 0.78750262602163912, 0.78104168892606518,
  0.7745114089990659, 0.76791339748949849, 0.7612492823579744,
  0.75452070787518566, 0.7477293342162038, 0.74087683705085772,
  0.73396490713028661, 0.72699524986977337, 0.7199695849279576,
  0.71288964578253633, 0.70575717930255433, 0.69857394531739025,
  0.69134171618254481, 0.684062276342339, 0.67673742188962849,
  0.66936896012264568, 0.66195870909907462, 0.65450849718747373,
  0.64702016261615192, 0.63949555301961458, 0.63193652498268627,
  0.62434494358242731, 0.61672268192795254, 0.60907162069827114,
  0.60139364767825609, 0.59369065729286241, 0.58596455013970483,
  0.57821723252011548, 0.57045061596879132, 0.56266661678215213,
  0.55486715554552257, 0.54705415665925716, 0.53922954786392241,
  0.53139525976465674, 0.52355322535482129, 0.51570537953906415,
  0.50785365865591026, 0.49999999999999994, 0.49214634134408969,
  0.4842946204609358, 0.47644677464517865, 0.46860474023534326,
  0.46077045213607748, 0.45294584334074273, 0.44513284445447743,
  0.43733338321784787, 0.42954938403120868, 0.42178276747988452,
  0.41403544986029522, 0.40630934270713764, 0.39860635232174374,
  0.39092837930172863, 0.38327731807204724, 0.37565505641757252,
  0.36806347501731351, 0.36050444698038525, 0.35297983738384808,
  0.34549150281252627, 0.33804129090092527, 0.33063103987735426,
  0.3232625781103714, 0.31593772365766093, 0.30865828381745508,
  0.30142605468260975, 0.29424282069744556, 0.28711035421746367,
  0.2800304150720424, 0.27300475013022657, 0.26603509286971327,
  0.25912316294914239, 0.2522706657837962, 0.2454792921248144,
  0.23875071764202555, 0.23208660251050173, 0.2254885910009341,
  0.21895831107393471, 0.21249737397836072, 0.20610737385376343,
  0.19978988733705794, 0.1935464731735117, 0.18737867183214735,
  0.18128800512565518, 0.17527597583490823, 0.16934406733817409,
  0.16349374324511334, 0.15772644703565564, 0.15204360170384285,
  0.14644660940672621, 0.14093685111840554, 0.13551568628929422,
  0.1301844525106951, 0.12494446518477026, 0.11979701719998453,
  0.11474337861210537, 0.1097847963308351, 0.10492249381215479,
  0.10015767075645471, 0.095491502812526274, 0.0909251412874883,
  0.086459712862719085, 0.082096319315864863, 0.077836037248992462,
  0.073679917822953855, 0.069628986498028178, 0.0656842427809044,
  0.061846659978068208, 0.058117184955653267, 0.054496737905816051,
  0.050986212119692176, 0.047586473766990267, 0.044298361682277354,
  0.04112268715800943, 0.038060233744356631, 0.035111757055874271,
  0.032277984585066366, 0.029559615522887273, 0.026957320586227351,
  0.024471741852423234, 0.02210349260083494, 0.019853157161528467,
  0.017721290771100962, 0.015708419435684462, 0.013815039801161721,
  0.012041619030626283, 0.010388594689117125, 0.00885637463565564,
  0.0074453369226130661, 0.0061558297024311148, 0.0049881711417212315,
  0.003942649342761062, 0.0030195222724101467, 0.0022190176984600019,
  0.0015413331334360181, 0.00098663578586422052, 0.00055506251901499271,
  0.0002467198171342, 6.1683759169706143E-5 };

const char_T cv[128] = { '\x00', '\x01', '\x02', '\x03', '\x04', '\x05', '\x06',
  '\x07', '\x08', '\x09', '\x0a', '\x0b', '\x0c', '\x0d', '\x0e', '\x0f', '\x10',
  '\x11', '\x12', '\x13', '\x14', '\x15', '\x16', '\x17', '\x18', '\x19', '\x1a',
  '\x1b', '\x1c', '\x1d', '\x1e', '\x1f', ' ', '!', '\"', '#', '$', '%', '&',
  '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5',
  '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'a', 'b', 'c', 'd', 'e',
  'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u',
  'v', 'w', 'x', 'y', 'z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd',
  'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
  'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~', '\x7f' };

// End of code generation (SECodegen_data.cpp)
