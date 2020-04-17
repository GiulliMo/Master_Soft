//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  designAuditoryFilterBank.cpp
//
//  Code generation for function 'designAuditoryFilterBank'
//


// Include files
#include "designAuditoryFilterBank.h"
#include "DeepLearningNetwork.h"
#include "SECodegen.h"
#include "bark2hz.h"
#include "designMelFilterBank.h"
#include "rt_nonfinite.h"
#include <string.h>

// Variable Definitions
static emlrtRSInfo k_emlrtRSI = { 94,  // lineNo
  "designAuditoryFilterBank",          // fcnName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/Extract_Features/designAuditoryFilterBank.m"// pathName 
};

static emlrtRSInfo l_emlrtRSI = { 96,  // lineNo
  "designAuditoryFilterBank",          // fcnName
  "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/Extract_Features/designAuditoryFilterBank.m"// pathName 
};

// Function Definitions
void designAuditoryFilterBank(SECodegenStackData *SD, const emlrtStack *sp,
  real_T filterBank[12850], real_T Fc[50])
{
  real_T bandEdges[52];
  boolean_T FFTLengthTooSmall;
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;

  // DESIGNAUDITORYFILTERBANK Design auditory filter bank.
  //    filterBank = designAuditoryFilterBank(fs) returns a frequency-domain
  //    auditory filter bank, filterBank. fs is the input sample rate, in Hz.
  //    filterBank is returned as a N-by-L array, where N is the number of
  //    bands and L is the number of frequency points, respectively.
  //
  //    filterBank = designAuditoryFilterBank(fs,'FrequencyScale',SCALE)
  //    specifies the frequency scale as either 'mel', 'bark', or 'erb'. If
  //    unspecified, SCALE defaults to 'mel'.
  //
  //    filterBank = designAuditoryFilterBank(fs,'FFTLength',FFTLENGTH)
  //    specifies the FFT length. If unspecified, FFTLENGTH defaults to 1024.
  //
  //    filterBank = designAuditoryFilterBank(fs,'FrequencyRange',FREQRANGE)
  //    specifies the frequency range over which to design the filter bank.
  //    If unspecified, FREQRANGE defaults to [0, fs/2].
  //
  //    filterBank = designAuditoryFilterBank(fs,'NumBands',NUMBANDS)
  //    specifies the number of bands in the filter bank. If unspecified,
  //    NUMBANDS defaults to ceil(hz2erb(FREQRANGE(2)) - hz2erb(FREQRANGE(1)))
  //    when FrequencyScale is 'erb', and to 32 otherwise.
  //
  //    filterbank = designAuditoryFilterBank('Normalization',NORM) specifies
  //    how the filter bank energy is normalized as either 'bandwidth', 'area',
  //    or 'none'. If unspecified, NORM defaults to 'bandwidth'.
  //
  //    [filterbank,Fc,BW] = designAuditoryFilterBank(...) returns the
  //    center frequencies, Fc, of the bands (in Hz) and the bandwidths, BW, of
  //    each filter in Hz.
  //
  //    % Example: Design an auditory filter bank and use it to compute a
  //    % mel spectrogram.
  //
  //    [audioIn,fs] = audioread('Counting-16-44p1-mono-15secs.wav');
  //
  //    % Compute spectrogram
  //    win     = hann(1024,'periodic');
  //    [~,F,T,S] = spectrogram(audioIn,win,512,1024,fs,'onesided');
  //
  //    % Design auditory filter bank
  //    [filterBank,CF] = designAuditoryFilterBank(fs,'FFTLength',1024,...
  //                         'NumBands',16,'Normalization','none');
  //
  //    % Visualize filter bank
  //    plot(F , filterBank.')
  //    grid on
  //    title('Mel Filter Bank')
  //    xlabel('Frequency (Hz)')
  //
  //    % Compute mel spectrogram
  //    SMel = filterBank * S;
  //
  //    See also gammatoneFilterBank, melSpectrogram.
  //    Copyright 2019 The MathWorks, Inc.
  st.site = &k_emlrtRSI;
  bark2hz(&st, bandEdges);
  st.site = &l_emlrtRSI;
  designMelFilterBank(&st, bandEdges, SD->f1.fbank, Fc, &FFTLengthTooSmall);

  //  EVEN
  for (int32_T i = 0; i < 257; i++) {
    for (int32_T i1 = 0; i1 < 50; i1++) {
      filterBank[i1 + 50 * i] = SD->f1.fbank[i + (i1 << 9)];
    }
  }
}

// End of code generation (designAuditoryFilterBank.cpp)
