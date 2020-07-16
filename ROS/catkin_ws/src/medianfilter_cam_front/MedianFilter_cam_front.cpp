//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: MedianFilter_cam_front.cpp
//
// Code generated for Simulink model 'MedianFilter_cam_front'.
//
// Model version                  : 1.11
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Wed Apr 29 10:17:35 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "MedianFilter_cam_front.h"
#include "MedianFilter_cam_front_private.h"

// Block signals (default storage)
B_MedianFilter_cam_front_T MedianFilter_cam_front_B;

// Block states (default storage)
DW_MedianFilter_cam_front_T MedianFilter_cam_front_DW;

// Previous zero-crossings (trigger) states
PrevZCX_MedianFilter_cam_fron_T MedianFilter_cam_front_PrevZCX;

// Real-time model
RT_MODEL_MedianFilter_cam_fro_T MedianFilter_cam_front_M_ =
  RT_MODEL_MedianFilter_cam_fro_T();
RT_MODEL_MedianFilter_cam_fro_T *const MedianFilter_cam_front_M =
  &MedianFilter_cam_front_M_;

// Forward declaration for local functions
static void MedianFilter_ca_SystemCore_step(boolean_T *varargout_1, uint32_T
  *varargout_2_Height, uint32_T *varargout_2_Width, uint8_T
  varargout_2_Encoding[1036800], uint32_T *varargout_2_Encoding_SL_Info_Cu,
  uint32_T *varargout_2_Encoding_SL_Info_Re, uint8_T *varargout_2_IsBigendian,
  uint32_T *varargout_2_Step, uint8_T varargout_2_Data[1036800], uint32_T
  *varargout_2_Data_SL_Info_Curren, uint32_T *varargout_2_Data_SL_Info_Receiv,
  uint32_T *varargout_2_Header_Seq, uint8_T varargout_2_Header_FrameId[128],
  uint32_T *varargout_2_Header_FrameId_SL_I, uint32_T
  *varargout_2_Header_FrameId_SL_0, SL_Bus_MedianFilter_cam_front_ros_time_Time *
  varargout_2_Header_Stamp);
static void MdnFltH25_M_IBSymm_uu1_hBk7vz_a(const int32_T hLoc[], const int32_T
  hDims[], const uint16_T u[], const int32_T uDims[], uint16_T y[], const
  int32_T yDims[], const int32_T yOrigin[]);
static void matlabCodegenHandle_matlabCod_a(ros_slros_internal_block_Subs_T *obj);
static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Publ_T *obj);
static void rate_scheduler(void);

//
//   This function updates active task flag for each subrate.
// The function is called at model base rate, hence the
// generated code self-manages all its subrates.
//
static void rate_scheduler(void)
{
  // Compute which subrates run during the next base time step.  Subrates
  //  are an integer multiple of the base rate counter.  Therefore, the subtask
  //  counter is reset when it reaches its limit (zero means run).

  (MedianFilter_cam_front_M->Timing.TaskCounters.TID[1])++;
  if ((MedianFilter_cam_front_M->Timing.TaskCounters.TID[1]) > 1) {// Sample time: [0.1s, 0.0s] 
    MedianFilter_cam_front_M->Timing.TaskCounters.TID[1] = 0;
  }
}

static void MedianFilter_ca_SystemCore_step(boolean_T *varargout_1, uint32_T
  *varargout_2_Height, uint32_T *varargout_2_Width, uint8_T
  varargout_2_Encoding[1036800], uint32_T *varargout_2_Encoding_SL_Info_Cu,
  uint32_T *varargout_2_Encoding_SL_Info_Re, uint8_T *varargout_2_IsBigendian,
  uint32_T *varargout_2_Step, uint8_T varargout_2_Data[1036800], uint32_T
  *varargout_2_Data_SL_Info_Curren, uint32_T *varargout_2_Data_SL_Info_Receiv,
  uint32_T *varargout_2_Header_Seq, uint8_T varargout_2_Header_FrameId[128],
  uint32_T *varargout_2_Header_FrameId_SL_I, uint32_T
  *varargout_2_Header_FrameId_SL_0, SL_Bus_MedianFilter_cam_front_ros_time_Time *
  varargout_2_Header_Stamp)
{
  *varargout_1 = Sub_MedianFilter_cam_front_46.getLatestMessage
    (&MedianFilter_cam_front_B.b_varargout_2);
  *varargout_2_Height = MedianFilter_cam_front_B.b_varargout_2.Height;
  *varargout_2_Width = MedianFilter_cam_front_B.b_varargout_2.Width;
  *varargout_2_Encoding_SL_Info_Cu =
    MedianFilter_cam_front_B.b_varargout_2.Encoding_SL_Info.CurrentLength;
  *varargout_2_Encoding_SL_Info_Re =
    MedianFilter_cam_front_B.b_varargout_2.Encoding_SL_Info.ReceivedLength;
  *varargout_2_IsBigendian = MedianFilter_cam_front_B.b_varargout_2.IsBigendian;
  *varargout_2_Step = MedianFilter_cam_front_B.b_varargout_2.Step;
  memcpy(&varargout_2_Encoding[0],
         &MedianFilter_cam_front_B.b_varargout_2.Encoding[0], 1036800U * sizeof
         (uint8_T));
  memcpy(&varargout_2_Data[0], &MedianFilter_cam_front_B.b_varargout_2.Data[0],
         1036800U * sizeof(uint8_T));
  *varargout_2_Data_SL_Info_Curren =
    MedianFilter_cam_front_B.b_varargout_2.Data_SL_Info.CurrentLength;
  *varargout_2_Data_SL_Info_Receiv =
    MedianFilter_cam_front_B.b_varargout_2.Data_SL_Info.ReceivedLength;
  *varargout_2_Header_Seq = MedianFilter_cam_front_B.b_varargout_2.Header.Seq;
  memcpy(&varargout_2_Header_FrameId[0],
         &MedianFilter_cam_front_B.b_varargout_2.Header.FrameId[0], sizeof
         (uint8_T) << 7U);
  *varargout_2_Header_FrameId_SL_I =
    MedianFilter_cam_front_B.b_varargout_2.Header.FrameId_SL_Info.CurrentLength;
  *varargout_2_Header_FrameId_SL_0 =
    MedianFilter_cam_front_B.b_varargout_2.Header.FrameId_SL_Info.ReceivedLength;
  *varargout_2_Header_Stamp =
    MedianFilter_cam_front_B.b_varargout_2.Header.Stamp;
}

uint16_T PadBSymm_uu16(const uint16_T u[], const int32_T uStride[], int32_T idx[],
  const int32_T uDims[], const int32_T uStart[], const int32_T uEnd[], const
  int32_T sNumPreEdges, const int32_T sPreEdges[], const int32_T sNumPostEdges,
  const int32_T sPostEdges[])
{
  uint16_T uOut;
  int32_T edgeNum;
  int32_T d;

  // S-Function (svipmdnfilter): '<S3>/Median Filter'
  // For boundary sectors:
  // -check if index is outside of input bounds ...
  //   -if so then return pad extended value
  //   -else fetch input data at the index
  // loop through preEdges
  for (edgeNum = 0; edgeNum < sNumPreEdges; edgeNum++) {
    if (idx[sPreEdges[edgeNum]] < uStart[sPreEdges[edgeNum]]) {
      // redirect index across a pre edge
      // reflect across pre-edge
      // check if it is a case of multiple reflections
      // get modulo distance
      d = ((uStart[sPreEdges[edgeNum]] - idx[sPreEdges[edgeNum]]) - 1) %
        (uDims[sPreEdges[edgeNum]] << 1);

      // if distance<dim then index is safe to be reflected
      if (d < uDims[sPreEdges[edgeNum]]) {
        idx[sPreEdges[edgeNum]] = uStart[sPreEdges[edgeNum]] + d;

        // else d%dim is reflected across opposite edge
      } else {
        idx[sPreEdges[edgeNum]] = uEnd[sPreEdges[edgeNum]] - d %
          uDims[sPreEdges[edgeNum]];
      }
    }
  }

  // loop through postEdges
  for (edgeNum = 0; edgeNum < sNumPostEdges; edgeNum++) {
    if (idx[sPostEdges[edgeNum]] > uEnd[sPostEdges[edgeNum]]) {
      // redirect index across a post edge
      // reflect across post-edge
      // check if it is a case of multiple reflections
      // get modulo distance
      d = ((idx[sPostEdges[edgeNum]] - uEnd[sPostEdges[edgeNum]]) - 1) %
        (uDims[sPostEdges[edgeNum]] << 1);

      // if distance<dim then index is safe to be reflected
      if (d < uDims[sPostEdges[edgeNum]]) {
        idx[sPostEdges[edgeNum]] = uEnd[sPostEdges[edgeNum]] - d;

        // else d%dim is reflected across opposite edge
      } else {
        idx[sPostEdges[edgeNum]] = d % uDims[sPostEdges[edgeNum]] +
          uStart[sPostEdges[edgeNum]];
      }
    }
  }

  // linearize index and return input data
  uOut = u[idx[0U] * uStride[0U] + idx[1U] * uStride[1U]];

  // End of S-Function (svipmdnfilter): '<S3>/Median Filter'
  return uOut;
}

static void MdnFltH25_M_IBSymm_uu1_hBk7vz_a(const int32_T hLoc[], const int32_T
  hDims[], const uint16_T u[], const int32_T uDims[], uint16_T y[], const
  int32_T yDims[], const int32_T yOrigin[])
{
  uint16_T acc;
  boolean_T isEnd;
  boolean_T dimIsPre;
  boolean_T dimIsInside;
  int32_T left;
  int32_T mid;
  int32_T rightIdx;
  uint16_T temp;
  int32_T hIdxA_idx_1;
  int32_T hEnd_idx_0;
  int32_T hEnd_idx_1;
  int32_T idxA_idx_1;
  int32_T idxB_idx_0;
  int32_T idxA_idx_0;
  int32_T idxBLin_idx_0;
  int32_T yPost_tmp;
  uint16_T pivot;
  int32_T exitg1;

  // S-Function (svipmdnfilter): '<S3>/Median Filter'
  MedianFilter_cam_front_B.uOrigin[0U] = 0;
  MedianFilter_cam_front_B.uEnd[0U] = uDims[0U] - 1;
  MedianFilter_cam_front_B.uStride[0U] = 1;
  MedianFilter_cam_front_B.uOrigin[1U] = 0;
  MedianFilter_cam_front_B.uEnd[1U] = uDims[1U] - 1;
  MedianFilter_cam_front_B.uStride[1U] = uDims[0U];
  hEnd_idx_0 = hDims[0U] - 1;
  hEnd_idx_1 = hDims[1U] - 1;

  //  COMPUTE MARGINS BETWEEN INPUT AND OUTPUT
  // ===============================================
  //      _________________________________________
  //     |u                                        |
  //     |                                         |
  //     |         ______________________          |
  //     |        |y                     |         |
  //     |        |                      |         |
  //     |<-yPre->|                      |<-yPost->|
  //
  //  KERNEL MARIGINS
  // ==============================================
  //      ____________________
  //     |h                   |
  //     |        |<--hPost-->|
  //     |        |           |
  //     |        x(hCenter)  |
  //     |<-hPre->|           |
  //  MARGINS (Valid, Boundary and Outside) definitions:
  //  Valid Margin: Processing region where entire kernel stays inside input boundaries. All input data thus considered is 'valid' data 
  //  Boundary Margin: Processing region where part of kernel stays inside the input boundaries and part of it goes outside input boundaries. 
  //  Outside Margin: Processing region where entire kernel stays outside the input boundaries and never touches input data. In most situations this region does not need to be processed. Instead output pad values are filled in 
  // ===========================================================
  //   y |        |        |               |         |         |
  //     |<-oPre->|<-bPre->|<----valid---->|<-bPost->|<-oPost->|
  //     |        |        |               |         |         |
  //  All margin locations are stored relative to the output origin
  // margins between y and u
  MedianFilter_cam_front_B.yPre = -yOrigin[0];
  yPost_tmp = (yOrigin[0] + yDims[0U]) - 1;
  MedianFilter_cam_front_B.yPost = yPost_tmp - MedianFilter_cam_front_B.uEnd[0];

  // margins caused by kernel - defined by center location
  // hLoc and hEnd are defined relative to origin
  MedianFilter_cam_front_B.hPost = hLoc[0] + hEnd_idx_0;

  // margins outside of kernel's influence around input
  // note that we subtract h'Post' from y'Pre'
  MedianFilter_cam_front_B.preMinus = MedianFilter_cam_front_B.yPre -
    MedianFilter_cam_front_B.hPost;

  // note that we subtract h'Pre' from y'Post'
  MedianFilter_cam_front_B.postMinus = MedianFilter_cam_front_B.yPost + hLoc[0];
  MedianFilter_cam_front_B.yPre -= hLoc[0];
  MedianFilter_cam_front_B.postPlus = MedianFilter_cam_front_B.yPost +
    MedianFilter_cam_front_B.hPost;

  // W refers to margin Width
  // L refers to margin Location
  // outer Pre
  // saturate
  if (MedianFilter_cam_front_B.preMinus < 0) {
    MedianFilter_cam_front_B.yPost = 0;
  } else if (MedianFilter_cam_front_B.preMinus > yDims[0]) {
    MedianFilter_cam_front_B.yPost = yDims[0];
  } else {
    MedianFilter_cam_front_B.yPost = MedianFilter_cam_front_B.preMinus;
  }

  // boundary Pre
  // saturate
  if (MedianFilter_cam_front_B.yPre < 0) {
    MedianFilter_cam_front_B.yPre = 0;
  } else {
    if (MedianFilter_cam_front_B.yPre > yDims[0]) {
      MedianFilter_cam_front_B.yPre = yDims[0];
    }
  }

  if (MedianFilter_cam_front_B.preMinus < 0) {
    MedianFilter_cam_front_B.preMinus = 0;
  } else {
    if (MedianFilter_cam_front_B.preMinus > yDims[0]) {
      MedianFilter_cam_front_B.preMinus = yDims[0];
    }
  }

  MedianFilter_cam_front_B.preMinus = MedianFilter_cam_front_B.yPre -
    MedianFilter_cam_front_B.preMinus;
  MedianFilter_cam_front_B.yPre = yOrigin[0] + MedianFilter_cam_front_B.yPost;

  // outer Post
  // saturate
  if (MedianFilter_cam_front_B.postMinus < 0) {
    MedianFilter_cam_front_B.hPost = 0;
  } else if (MedianFilter_cam_front_B.postMinus > yDims[0]) {
    MedianFilter_cam_front_B.hPost = yDims[0];
  } else {
    MedianFilter_cam_front_B.hPost = MedianFilter_cam_front_B.postMinus;
  }

  yPost_tmp = (yPost_tmp - MedianFilter_cam_front_B.hPost) + 1;

  // boundary Post
  // saturate
  if (MedianFilter_cam_front_B.postPlus < 0) {
    MedianFilter_cam_front_B.postPlus = 0;
  } else {
    if (MedianFilter_cam_front_B.postPlus > yDims[0]) {
      MedianFilter_cam_front_B.postPlus = yDims[0];
    }
  }

  if (MedianFilter_cam_front_B.postMinus < 0) {
    MedianFilter_cam_front_B.postMinus = 0;
  } else {
    if (MedianFilter_cam_front_B.postMinus > yDims[0]) {
      MedianFilter_cam_front_B.postMinus = yDims[0];
    }
  }

  MedianFilter_cam_front_B.postMinus = MedianFilter_cam_front_B.postPlus -
    MedianFilter_cam_front_B.postMinus;
  MedianFilter_cam_front_B.postPlus = yPost_tmp -
    MedianFilter_cam_front_B.postMinus;
  MedianFilter_cam_front_B.bPreEnd = MedianFilter_cam_front_B.yPre +
    MedianFilter_cam_front_B.preMinus;
  MedianFilter_cam_front_B.bPostEnd = MedianFilter_cam_front_B.postPlus +
    MedianFilter_cam_front_B.postMinus;
  if (MedianFilter_cam_front_B.bPreEnd - 1 >= MedianFilter_cam_front_B.postPlus)
  {
    // defines situation where hDims > uDims
    MedianFilter_cam_front_B.preMinus = MedianFilter_cam_front_B.postPlus -
      MedianFilter_cam_front_B.yPre;
    MedianFilter_cam_front_B.postPlus = MedianFilter_cam_front_B.bPreEnd;
    MedianFilter_cam_front_B.postMinus = MedianFilter_cam_front_B.bPostEnd -
      MedianFilter_cam_front_B.bPreEnd;
  }

  // assign to the margin set of mLoc and mWidth
  MedianFilter_cam_front_B.mLoc[0] = MedianFilter_cam_front_B.yPre +
    MedianFilter_cam_front_B.preMinus;
  MedianFilter_cam_front_B.mWidth[0] = (((yDims[0] -
    MedianFilter_cam_front_B.yPost) - MedianFilter_cam_front_B.hPost) -
    MedianFilter_cam_front_B.preMinus) - MedianFilter_cam_front_B.postMinus;
  MedianFilter_cam_front_B.mLoc[2] = MedianFilter_cam_front_B.yPre;
  MedianFilter_cam_front_B.mWidth[2] = MedianFilter_cam_front_B.preMinus;
  MedianFilter_cam_front_B.mLoc[4] = MedianFilter_cam_front_B.postPlus;
  MedianFilter_cam_front_B.mWidth[4] = MedianFilter_cam_front_B.postMinus;
  MedianFilter_cam_front_B.mLoc[6] = yOrigin[0];
  MedianFilter_cam_front_B.mWidth[6] = MedianFilter_cam_front_B.yPost;
  MedianFilter_cam_front_B.mLoc[8] = yPost_tmp;
  MedianFilter_cam_front_B.mWidth[8] = MedianFilter_cam_front_B.hPost;

  // margins between y and u
  MedianFilter_cam_front_B.yPre = -yOrigin[1];
  yPost_tmp = (yOrigin[1] + yDims[1U]) - 1;
  MedianFilter_cam_front_B.yPost = yPost_tmp - MedianFilter_cam_front_B.uEnd[1];

  // margins caused by kernel - defined by center location
  // hLoc and hEnd are defined relative to origin
  MedianFilter_cam_front_B.hPost = hLoc[1] + hEnd_idx_1;

  // margins outside of kernel's influence around input
  // note that we subtract h'Post' from y'Pre'
  MedianFilter_cam_front_B.preMinus = MedianFilter_cam_front_B.yPre -
    MedianFilter_cam_front_B.hPost;

  // note that we subtract h'Pre' from y'Post'
  MedianFilter_cam_front_B.postMinus = MedianFilter_cam_front_B.yPost + hLoc[1];
  MedianFilter_cam_front_B.yPre -= hLoc[1];
  MedianFilter_cam_front_B.postPlus = MedianFilter_cam_front_B.yPost +
    MedianFilter_cam_front_B.hPost;

  // W refers to margin Width
  // L refers to margin Location
  // outer Pre
  // saturate
  if (MedianFilter_cam_front_B.preMinus < 0) {
    MedianFilter_cam_front_B.yPost = 0;
  } else if (MedianFilter_cam_front_B.preMinus > yDims[1]) {
    MedianFilter_cam_front_B.yPost = yDims[1];
  } else {
    MedianFilter_cam_front_B.yPost = MedianFilter_cam_front_B.preMinus;
  }

  // boundary Pre
  // saturate
  if (MedianFilter_cam_front_B.yPre < 0) {
    MedianFilter_cam_front_B.yPre = 0;
  } else {
    if (MedianFilter_cam_front_B.yPre > yDims[1]) {
      MedianFilter_cam_front_B.yPre = yDims[1];
    }
  }

  if (MedianFilter_cam_front_B.preMinus < 0) {
    MedianFilter_cam_front_B.preMinus = 0;
  } else {
    if (MedianFilter_cam_front_B.preMinus > yDims[1]) {
      MedianFilter_cam_front_B.preMinus = yDims[1];
    }
  }

  MedianFilter_cam_front_B.preMinus = MedianFilter_cam_front_B.yPre -
    MedianFilter_cam_front_B.preMinus;
  MedianFilter_cam_front_B.yPre = yOrigin[1] + MedianFilter_cam_front_B.yPost;

  // outer Post
  // saturate
  if (MedianFilter_cam_front_B.postMinus < 0) {
    MedianFilter_cam_front_B.hPost = 0;
  } else if (MedianFilter_cam_front_B.postMinus > yDims[1]) {
    MedianFilter_cam_front_B.hPost = yDims[1];
  } else {
    MedianFilter_cam_front_B.hPost = MedianFilter_cam_front_B.postMinus;
  }

  yPost_tmp = (yPost_tmp - MedianFilter_cam_front_B.hPost) + 1;

  // boundary Post
  // saturate
  if (MedianFilter_cam_front_B.postPlus < 0) {
    MedianFilter_cam_front_B.postPlus = 0;
  } else {
    if (MedianFilter_cam_front_B.postPlus > yDims[1]) {
      MedianFilter_cam_front_B.postPlus = yDims[1];
    }
  }

  if (MedianFilter_cam_front_B.postMinus < 0) {
    MedianFilter_cam_front_B.postMinus = 0;
  } else {
    if (MedianFilter_cam_front_B.postMinus > yDims[1]) {
      MedianFilter_cam_front_B.postMinus = yDims[1];
    }
  }

  MedianFilter_cam_front_B.postMinus = MedianFilter_cam_front_B.postPlus -
    MedianFilter_cam_front_B.postMinus;
  MedianFilter_cam_front_B.postPlus = yPost_tmp -
    MedianFilter_cam_front_B.postMinus;
  MedianFilter_cam_front_B.bPreEnd = MedianFilter_cam_front_B.yPre +
    MedianFilter_cam_front_B.preMinus;
  MedianFilter_cam_front_B.bPostEnd = MedianFilter_cam_front_B.postPlus +
    MedianFilter_cam_front_B.postMinus;
  if (MedianFilter_cam_front_B.bPreEnd - 1 >= MedianFilter_cam_front_B.postPlus)
  {
    // defines situation where hDims > uDims
    MedianFilter_cam_front_B.preMinus = MedianFilter_cam_front_B.postPlus -
      MedianFilter_cam_front_B.yPre;
    MedianFilter_cam_front_B.postPlus = MedianFilter_cam_front_B.bPreEnd;
    MedianFilter_cam_front_B.postMinus = MedianFilter_cam_front_B.bPostEnd -
      MedianFilter_cam_front_B.bPreEnd;
  }

  // assign to the margin set of mLoc and mWidth
  MedianFilter_cam_front_B.mLoc[1] = MedianFilter_cam_front_B.yPre +
    MedianFilter_cam_front_B.preMinus;
  MedianFilter_cam_front_B.mWidth[1] = (((yDims[1] -
    MedianFilter_cam_front_B.yPost) - MedianFilter_cam_front_B.hPost) -
    MedianFilter_cam_front_B.preMinus) - MedianFilter_cam_front_B.postMinus;
  MedianFilter_cam_front_B.mLoc[3] = MedianFilter_cam_front_B.yPre;
  MedianFilter_cam_front_B.mWidth[3] = MedianFilter_cam_front_B.preMinus;
  MedianFilter_cam_front_B.mLoc[5] = MedianFilter_cam_front_B.postPlus;
  MedianFilter_cam_front_B.mWidth[5] = MedianFilter_cam_front_B.postMinus;
  MedianFilter_cam_front_B.mLoc[7] = yOrigin[1];
  MedianFilter_cam_front_B.mWidth[7] = MedianFilter_cam_front_B.yPost;
  MedianFilter_cam_front_B.mLoc[9] = yPost_tmp;
  MedianFilter_cam_front_B.mWidth[9] = MedianFilter_cam_front_B.hPost;

  //  //////////////////////////////////////////
  //  COMPUTE INSIDE SECTOR
  //  ==========================================
  //  Original arrangement of sectors
  //   |   3   |   1   |   0   |   2   |   4   |
  //   | OutPre| BndPre| Inside|BndPost|OutPost|
  //    _______________________________________
  //   |       |       |       |       |       |
  //  3| (3,3) | (3,1) | (3,0) | (3,2) | (3,4) |
  //  1| (1,3) | (1,1) | (1,0) | (1,2) | (1,4) |
  //   |       |       | VALID |       |       |
  //  0| (0,3) | (0,1) | (0,0) | (0,2) | (0,4) |
  //  2| (2,3) | (2,1) | (2,0) | (2,2) | (2,4) |
  //  4| (4,3) | (4,1) | (4,0) | (4,2) | (4,4) |
  //    ---------------------------------------
  //  Sectors rearranged in order from 0 to 4
  //   |   0   |   1   |   2   |   3   |   4   |
  //   | Inside| BndPre|BndPost| OutPre|OutPost|
  //   |///////|       |       |       |       |
  //   |/VALID/|       |       |       |       |
  //  0|/(0,0)/| (0,1) | (0,2) | (0,3) | (0,4) |
  //  1| (1,0) | (1,1) | (1,2) | (1,3) | (1,4) |
  //  2| (2,0) | (2,1) | (2,2) | (2,3) | (2,4) |
  //  3| (3,0) | (3,1) | (3,2) | (3,3) | (3,4) |
  //  4| (4,0) | (4,1) | (4,2) | (4,3) | (4,4) |
  // setup counter for valid sector, that is 0 in all dims
  // compute inside sector
  // compute sector if not empty
  if ((MedianFilter_cam_front_B.mWidth[0] > 0) &&
      (MedianFilter_cam_front_B.mWidth[1] > 0)) {
    // sector start corresponds to margin loc
    // apply offset of margin width for sector end
    // setup indices for the loops
    // Origin stores the origin of Y with respect to U
    //  where the origin of Y is at its top left corner
    // Compute offset between origin of Y and origin of U(0,0)
    // sector start and end were computed relative to U
    // make them relative to Y by adding offset
    MedianFilter_cam_front_B.yPost = MedianFilter_cam_front_B.mLoc[0] - yOrigin
      [0U];
    MedianFilter_cam_front_B.preMinus = ((MedianFilter_cam_front_B.mLoc[0] +
      MedianFilter_cam_front_B.mWidth[0]) - yOrigin[0U]) - 1;
    MedianFilter_cam_front_B.hPost = ((MedianFilter_cam_front_B.mLoc[1] +
      MedianFilter_cam_front_B.mWidth[1]) - yOrigin[1U]) - 1;

    // adjust offset for kernel center
    MedianFilter_cam_front_B.postMinus = -yOrigin[0U] - hLoc[0U];
    yPost_tmp = -yOrigin[1U] - hLoc[1U];

    // loop kernel over data
    MedianFilter_cam_front_B.yPre = MedianFilter_cam_front_B.mLoc[1] - yOrigin
      [1U];
    while (MedianFilter_cam_front_B.yPre <= MedianFilter_cam_front_B.hPost) {
      MedianFilter_cam_front_B.postPlus = (MedianFilter_cam_front_B.yPre -
        yPost_tmp) * uDims[0U];
      MedianFilter_cam_front_B.bPostEnd = yDims[0U] *
        MedianFilter_cam_front_B.yPre;
      for (idxB_idx_0 = MedianFilter_cam_front_B.yPost; idxB_idx_0 <=
           MedianFilter_cam_front_B.preMinus; idxB_idx_0++) {
        idxBLin_idx_0 = MedianFilter_cam_front_B.bPostEnd + idxB_idx_0;
        MedianFilter_cam_front_B.bPreEnd = (MedianFilter_cam_front_B.postPlus +
          idxB_idx_0) - MedianFilter_cam_front_B.postMinus;

        // loop over kernel and compute median value
        MedianFilter_cam_front_B.idxHLin = 0;

        // loop over kernel
        for (hIdxA_idx_1 = 0; hIdxA_idx_1 <= hEnd_idx_1; hIdxA_idx_1++) {
          for (left = 0; left <= hEnd_idx_0; left++) {
            // cache away u for the window
            MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin] =
              u[MedianFilter_cam_front_B.bPreEnd];
            MedianFilter_cam_front_B.bPreEnd++;
            MedianFilter_cam_front_B.idxHLin++;
          }

          MedianFilter_cam_front_B.bPreEnd = (MedianFilter_cam_front_B.bPreEnd +
            uDims[0]) - hDims[0];
        }

        MedianFilter_cam_front_B.idxHLin = hDims[0U] * hDims[1U] - 1;
        hIdxA_idx_1 = ((MedianFilter_cam_front_B.idxHLin + 2) >> 1) - 1;
        if ((MedianFilter_cam_front_B.idxHLin + 1) % 2 == 0) {
          // Perform the scanning only if the current partition has
          // at least three elements.
          left = 0;
          idxA_idx_0 = MedianFilter_cam_front_B.idxHLin;
          while (idxA_idx_0 > left + 1) {
            // Use the median of the three values as the partitioning key
            // Use median-of-three method to return the partitioning key (pivot). 
            // This method makes worst-case behavior much less likely and
            // avoids the needs for sentinel values outside the array.
            // //////////////////////////////////////////////////////////////////// 
            // First we sort the first, middle, and last element of the partition. 
            mid = (left + idxA_idx_0) >> 1;
            if (MedianFilter_cam_front_B.uW[left] >
                MedianFilter_cam_front_B.uW[mid]) {
              temp = MedianFilter_cam_front_B.uW[left];
              MedianFilter_cam_front_B.uW[left] =
                MedianFilter_cam_front_B.uW[mid];
              MedianFilter_cam_front_B.uW[mid] = temp;
            }

            if (MedianFilter_cam_front_B.uW[left] >
                MedianFilter_cam_front_B.uW[idxA_idx_0]) {
              temp = MedianFilter_cam_front_B.uW[left];
              MedianFilter_cam_front_B.uW[left] =
                MedianFilter_cam_front_B.uW[idxA_idx_0];
              MedianFilter_cam_front_B.uW[idxA_idx_0] = temp;
            }

            if (MedianFilter_cam_front_B.uW[mid] >
                MedianFilter_cam_front_B.uW[idxA_idx_0]) {
              temp = MedianFilter_cam_front_B.uW[mid];
              MedianFilter_cam_front_B.uW[mid] =
                MedianFilter_cam_front_B.uW[idxA_idx_0];
              MedianFilter_cam_front_B.uW[idxA_idx_0] = temp;
            }

            // //////////////////////////////////////////////////////////////////// 
            // Now swap the middle value with the next-to-last value.
            temp = MedianFilter_cam_front_B.uW[mid];
            MedianFilter_cam_front_B.uW[mid] =
              MedianFilter_cam_front_B.uW[idxA_idx_0 - 1];
            MedianFilter_cam_front_B.uW[idxA_idx_0 - 1] = temp;

            // return pivot for partitioning
            pivot = MedianFilter_cam_front_B.uW[idxA_idx_0 - 1];

            // Start the partitioning scan.  Note that because we sorted
            // the left and right values, we can start the comparisons
            // with (left+1) and (right-2).  This is how we avoid the
            // need for sentinel values.
            mid = left;
            rightIdx = idxA_idx_0 - 1;
            do {
              exitg1 = 0;
              do {
                mid++;
              } while (MedianFilter_cam_front_B.uW[mid] < pivot);

              do {
                rightIdx--;
              } while (MedianFilter_cam_front_B.uW[rightIdx] > pivot);

              // pointers crossed -> end scan
              if (mid >= rightIdx) {
                exitg1 = 1;
              } else {
                // Swap values at end of current interval.
                temp = MedianFilter_cam_front_B.uW[mid];
                MedianFilter_cam_front_B.uW[mid] =
                  MedianFilter_cam_front_B.uW[rightIdx];
                MedianFilter_cam_front_B.uW[rightIdx] = temp;
              }
            } while (exitg1 == 0);

            // One last swap needed at end of scan
            temp = MedianFilter_cam_front_B.uW[mid];
            MedianFilter_cam_front_B.uW[mid] =
              MedianFilter_cam_front_B.uW[idxA_idx_0 - 1];
            MedianFilter_cam_front_B.uW[idxA_idx_0 - 1] = temp;

            // Select the left or right subpartition depending on
            // the value of order.
            if (mid >= hIdxA_idx_1) {
              idxA_idx_0 = mid - 1;
            }

            if (mid <= hIdxA_idx_1) {
              left = mid + 1;
            }
          }

          if ((idxA_idx_0 - left == 1) && (MedianFilter_cam_front_B.uW[left] >
               MedianFilter_cam_front_B.uW[idxA_idx_0])) {
            // Last partition has two elements that may not be sorted.
            temp = MedianFilter_cam_front_B.uW[left];
            MedianFilter_cam_front_B.uW[left] =
              MedianFilter_cam_front_B.uW[idxA_idx_0];
            MedianFilter_cam_front_B.uW[idxA_idx_0] = temp;
          }

          acc = MedianFilter_cam_front_B.uW[hIdxA_idx_1];

          // Perform the scanning only if the current partition has
          // at least three elements.
          left = 0;
          while (MedianFilter_cam_front_B.idxHLin > left + 1) {
            // Use the median of the three values as the partitioning key
            // Use median-of-three method to return the partitioning key (pivot). 
            // This method makes worst-case behavior much less likely and
            // avoids the needs for sentinel values outside the array.
            // //////////////////////////////////////////////////////////////////// 
            // First we sort the first, middle, and last element of the partition. 
            mid = (left + MedianFilter_cam_front_B.idxHLin) >> 1;
            if (MedianFilter_cam_front_B.uW[left] >
                MedianFilter_cam_front_B.uW[mid]) {
              temp = MedianFilter_cam_front_B.uW[left];
              MedianFilter_cam_front_B.uW[left] =
                MedianFilter_cam_front_B.uW[mid];
              MedianFilter_cam_front_B.uW[mid] = temp;
            }

            if (MedianFilter_cam_front_B.uW[left] >
                MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin]) {
              temp = MedianFilter_cam_front_B.uW[left];
              MedianFilter_cam_front_B.uW[left] =
                MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin];
              MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin] =
                temp;
            }

            if (MedianFilter_cam_front_B.uW[mid] >
                MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin]) {
              temp = MedianFilter_cam_front_B.uW[mid];
              MedianFilter_cam_front_B.uW[mid] =
                MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin];
              MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin] =
                temp;
            }

            // //////////////////////////////////////////////////////////////////// 
            // Now swap the middle value with the next-to-last value.
            temp = MedianFilter_cam_front_B.uW[mid];
            MedianFilter_cam_front_B.uW[mid] =
              MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin - 1];
            MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin - 1] =
              temp;

            // return pivot for partitioning
            pivot = MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin
              - 1];

            // Start the partitioning scan.  Note that because we sorted
            // the left and right values, we can start the comparisons
            // with (left+1) and (right-2).  This is how we avoid the
            // need for sentinel values.
            mid = left;
            rightIdx = MedianFilter_cam_front_B.idxHLin - 1;
            do {
              exitg1 = 0;
              do {
                mid++;
              } while (MedianFilter_cam_front_B.uW[mid] < pivot);

              do {
                rightIdx--;
              } while (MedianFilter_cam_front_B.uW[rightIdx] > pivot);

              // pointers crossed -> end scan
              if (mid >= rightIdx) {
                exitg1 = 1;
              } else {
                // Swap values at end of current interval.
                temp = MedianFilter_cam_front_B.uW[mid];
                MedianFilter_cam_front_B.uW[mid] =
                  MedianFilter_cam_front_B.uW[rightIdx];
                MedianFilter_cam_front_B.uW[rightIdx] = temp;
              }
            } while (exitg1 == 0);

            // One last swap needed at end of scan
            temp = MedianFilter_cam_front_B.uW[mid];
            MedianFilter_cam_front_B.uW[mid] =
              MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin - 1];
            MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin - 1] =
              temp;

            // Select the left or right subpartition depending on
            // the value of order.
            if (mid >= hIdxA_idx_1 + 1) {
              MedianFilter_cam_front_B.idxHLin = mid - 1;
            }

            if (mid <= hIdxA_idx_1 + 1) {
              left = mid + 1;
            }
          }

          if ((MedianFilter_cam_front_B.idxHLin - left == 1) &&
              (MedianFilter_cam_front_B.uW[left] >
               MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin])) {
            // Last partition has two elements that may not be sorted.
            temp = MedianFilter_cam_front_B.uW[left];
            MedianFilter_cam_front_B.uW[left] =
              MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin];
            MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin] = temp;
          }

          acc = static_cast<uint16_T>(static_cast<uint32_T>
            (MedianFilter_cam_front_B.uW[hIdxA_idx_1 + 1]) + acc);
          temp = static_cast<uint16_T>(static_cast<uint32_T>(acc) >> 1);
        } else {
          // Perform the scanning only if the current partition has
          // at least three elements.
          left = 0;
          while (MedianFilter_cam_front_B.idxHLin > left + 1) {
            // Use the median of the three values as the partitioning key
            // Use median-of-three method to return the partitioning key (pivot). 
            // This method makes worst-case behavior much less likely and
            // avoids the needs for sentinel values outside the array.
            // //////////////////////////////////////////////////////////////////// 
            // First we sort the first, middle, and last element of the partition. 
            mid = (left + MedianFilter_cam_front_B.idxHLin) >> 1;
            if (MedianFilter_cam_front_B.uW[left] >
                MedianFilter_cam_front_B.uW[mid]) {
              temp = MedianFilter_cam_front_B.uW[left];
              MedianFilter_cam_front_B.uW[left] =
                MedianFilter_cam_front_B.uW[mid];
              MedianFilter_cam_front_B.uW[mid] = temp;
            }

            if (MedianFilter_cam_front_B.uW[left] >
                MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin]) {
              temp = MedianFilter_cam_front_B.uW[left];
              MedianFilter_cam_front_B.uW[left] =
                MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin];
              MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin] =
                temp;
            }

            if (MedianFilter_cam_front_B.uW[mid] >
                MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin]) {
              temp = MedianFilter_cam_front_B.uW[mid];
              MedianFilter_cam_front_B.uW[mid] =
                MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin];
              MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin] =
                temp;
            }

            // //////////////////////////////////////////////////////////////////// 
            // Now swap the middle value with the next-to-last value.
            temp = MedianFilter_cam_front_B.uW[mid];
            MedianFilter_cam_front_B.uW[mid] =
              MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin - 1];
            MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin - 1] =
              temp;

            // return pivot for partitioning
            pivot = MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin
              - 1];

            // Start the partitioning scan.  Note that because we sorted
            // the left and right values, we can start the comparisons
            // with (left+1) and (right-2).  This is how we avoid the
            // need for sentinel values.
            mid = left;
            rightIdx = MedianFilter_cam_front_B.idxHLin - 1;
            do {
              exitg1 = 0;
              do {
                mid++;
              } while (MedianFilter_cam_front_B.uW[mid] < pivot);

              do {
                rightIdx--;
              } while (MedianFilter_cam_front_B.uW[rightIdx] > pivot);

              // pointers crossed -> end scan
              if (mid >= rightIdx) {
                exitg1 = 1;
              } else {
                // Swap values at end of current interval.
                temp = MedianFilter_cam_front_B.uW[mid];
                MedianFilter_cam_front_B.uW[mid] =
                  MedianFilter_cam_front_B.uW[rightIdx];
                MedianFilter_cam_front_B.uW[rightIdx] = temp;
              }
            } while (exitg1 == 0);

            // One last swap needed at end of scan
            temp = MedianFilter_cam_front_B.uW[mid];
            MedianFilter_cam_front_B.uW[mid] =
              MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin - 1];
            MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin - 1] =
              temp;

            // Select the left or right subpartition depending on
            // the value of order.
            if (mid >= hIdxA_idx_1) {
              MedianFilter_cam_front_B.idxHLin = mid - 1;
            }

            if (mid <= hIdxA_idx_1) {
              left = mid + 1;
            }
          }

          if ((MedianFilter_cam_front_B.idxHLin - left == 1) &&
              (MedianFilter_cam_front_B.uW[left] >
               MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin])) {
            // Last partition has two elements that may not be sorted.
            temp = MedianFilter_cam_front_B.uW[left];
            MedianFilter_cam_front_B.uW[left] =
              MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin];
            MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin] = temp;
          }

          temp = MedianFilter_cam_front_B.uW[hIdxA_idx_1];
        }

        if (idxBLin_idx_0 >= 0) {
          y[idxBLin_idx_0] = temp;
        }
      }

      MedianFilter_cam_front_B.yPre++;
    }
  }

  //  //////////////////////////////////////////
  //  COMPUTE ON-BOUNDARY SECTORS
  // ===========================================
  //   |   0   |   1   |   2   |   3   |   4   |
  //   | Inside| BndPre|BndPost| OutPre|OutPost|
  //    _______________________________________
  //   |       |///////|///////|       |       |
  //   | VALID |///////|///////|       |       |
  //  0| (0,0) |/(0,1)/|/(0,2)/| (0,3) | (0,4) |
  //   |///////|///////|///////|       |       |
  //  1|/(1,0)/|/(1,1)/|/(1,2)/| (1,3) | (1,4) |
  //  2|/(2,0)/|/(2,1)/|/(2,2)/| (2,3) | (2,4) |
  //   |       |       |       |       |       |
  //  3| (3,0) | (3,1) | (3,2) | (3,3) | (3,4) |
  //  4| (4,0) | (4,1) | (4,2) | (4,3) | (4,4) |
  //    ---------------------------------------
  MedianFilter_cam_front_B.o[0U] = 0;
  MedianFilter_cam_front_B.o[1U] = 1;
  MedianFilter_cam_front_B.o[2U] = 2;
  MedianFilter_cam_front_B.o[3U] = 3;
  MedianFilter_cam_front_B.o[4U] = 4;
  isEnd = false;
  MedianFilter_cam_front_B.c[1U] = 0;

  // if hDims < uDims then the all INSIDE sector will not be pushed into the boundary sectors... hence the counter needs to skip the all INSIDEs sector and start from one sector down. 
  MedianFilter_cam_front_B.c[0U] = 1;
  while (!isEnd) {
    MedianFilter_cam_front_B.postPlus = 0;
    MedianFilter_cam_front_B.bPreEnd = 0;

    // compute on-boundary sector
    // compute sector if not empty
    if ((MedianFilter_cam_front_B.mWidth[MedianFilter_cam_front_B.o[MedianFilter_cam_front_B.c
         [0U]] << 1] > 0) && (MedianFilter_cam_front_B.mWidth
         [(MedianFilter_cam_front_B.o[MedianFilter_cam_front_B.c[1U]] << 1) + 1]
         > 0)) {
      // compute sector for this dim
      // sector start corresponds to margin loc
      MedianFilter_cam_front_B.preMinus =
        MedianFilter_cam_front_B.o[MedianFilter_cam_front_B.c[0]] << 1;

      // apply offset of margin width for sector end
      // Inside Sector if 0 in all dimensions
      dimIsInside = (MedianFilter_cam_front_B.o[MedianFilter_cam_front_B.c[0]] ==
                     0);
      dimIsPre = ((MedianFilter_cam_front_B.o[MedianFilter_cam_front_B.c[0]] ==
                   3) || (MedianFilter_cam_front_B.o[MedianFilter_cam_front_B.c
                          [0]] == 1));
      if (dimIsPre || dimIsInside) {
        MedianFilter_cam_front_B.sPreEdges[0] = 0;
        MedianFilter_cam_front_B.postPlus = 1;
      }

      if (((!dimIsPre) && (!dimIsInside)) || dimIsInside) {
        MedianFilter_cam_front_B.sPostEdges[0] = 0;
        MedianFilter_cam_front_B.bPreEnd = 1;
      }

      // compute sector for this dim
      // sector start corresponds to margin loc
      MedianFilter_cam_front_B.hPost =
        (MedianFilter_cam_front_B.o[MedianFilter_cam_front_B.c[1]] << 1) + 1;

      // apply offset of margin width for sector end
      // Inside Sector if 0 in all dimensions
      dimIsInside = (MedianFilter_cam_front_B.o[MedianFilter_cam_front_B.c[1]] ==
                     0);
      dimIsPre = ((MedianFilter_cam_front_B.o[MedianFilter_cam_front_B.c[1]] ==
                   3) || (MedianFilter_cam_front_B.o[MedianFilter_cam_front_B.c
                          [1]] == 1));
      if (dimIsPre || dimIsInside) {
        MedianFilter_cam_front_B.sPreEdges[MedianFilter_cam_front_B.postPlus] =
          1;
        MedianFilter_cam_front_B.postPlus++;
      }

      if (((!dimIsPre) && (!dimIsInside)) || dimIsInside) {
        MedianFilter_cam_front_B.sPostEdges[MedianFilter_cam_front_B.bPreEnd] =
          1;
        MedianFilter_cam_front_B.bPreEnd++;
      }

      // setup indices for the loops
      // Origin stores the origin of Y with respect to U
      //  where the origin of Y is at its top left corner
      // Compute offset between origin of Y and origin of U(0,0)
      MedianFilter_cam_front_B.postMinus = -yOrigin[0U];
      yPost_tmp = -yOrigin[1U];

      // sector start and end were computed relative to U
      // make them relative to Y by adding offset
      MedianFilter_cam_front_B.yPost =
        MedianFilter_cam_front_B.mLoc[MedianFilter_cam_front_B.preMinus] +
        MedianFilter_cam_front_B.postMinus;
      MedianFilter_cam_front_B.preMinus =
        ((MedianFilter_cam_front_B.mWidth[MedianFilter_cam_front_B.preMinus] +
          MedianFilter_cam_front_B.mLoc[MedianFilter_cam_front_B.preMinus]) +
         MedianFilter_cam_front_B.postMinus) - 1;
      MedianFilter_cam_front_B.yPre =
        MedianFilter_cam_front_B.mLoc[MedianFilter_cam_front_B.hPost] +
        yPost_tmp;
      MedianFilter_cam_front_B.hPost =
        ((MedianFilter_cam_front_B.mWidth[MedianFilter_cam_front_B.hPost] +
          MedianFilter_cam_front_B.mLoc[MedianFilter_cam_front_B.hPost]) +
         yPost_tmp) - 1;

      // adjust offset for kernel center
      MedianFilter_cam_front_B.postMinus -= hLoc[0U];
      yPost_tmp -= hLoc[1U];

      // loop kernel over data
      while (MedianFilter_cam_front_B.yPre <= MedianFilter_cam_front_B.hPost) {
        idxA_idx_1 = MedianFilter_cam_front_B.yPre - yPost_tmp;
        MedianFilter_cam_front_B.bPostEnd = yDims[0] *
          MedianFilter_cam_front_B.yPre;
        for (idxB_idx_0 = MedianFilter_cam_front_B.yPost; idxB_idx_0 <=
             MedianFilter_cam_front_B.preMinus; idxB_idx_0++) {
          idxA_idx_0 = idxB_idx_0 - MedianFilter_cam_front_B.postMinus;
          idxBLin_idx_0 = MedianFilter_cam_front_B.bPostEnd + idxB_idx_0;

          // loop over kernel and compute median
          MedianFilter_cam_front_B.idxHLin = 0;

          // loop over kernel
          for (hIdxA_idx_1 = 0; hIdxA_idx_1 <= hEnd_idx_1; hIdxA_idx_1++) {
            MedianFilter_cam_front_B.hIdxB[1] = idxA_idx_1 + hIdxA_idx_1;
            for (left = 0; left <= hEnd_idx_0; left++) {
              MedianFilter_cam_front_B.hIdxB[0] = idxA_idx_0 + left;
              MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin] =
                PadBSymm_uu16(&u[0U], &MedianFilter_cam_front_B.uStride[0U],
                              &MedianFilter_cam_front_B.hIdxB[0U], &uDims[0U],
                              &MedianFilter_cam_front_B.uOrigin[0U],
                              &MedianFilter_cam_front_B.uEnd[0U],
                              MedianFilter_cam_front_B.postPlus,
                              &MedianFilter_cam_front_B.sPreEdges[0U],
                              MedianFilter_cam_front_B.bPreEnd,
                              &MedianFilter_cam_front_B.sPostEdges[0U]);

              // cache away u for the window
              MedianFilter_cam_front_B.idxHLin++;
            }
          }

          MedianFilter_cam_front_B.idxHLin = hDims[0U] * hDims[1U] - 1;
          hIdxA_idx_1 = ((MedianFilter_cam_front_B.idxHLin + 2) >> 1) - 1;
          if ((MedianFilter_cam_front_B.idxHLin + 1) % 2 == 0) {
            // Perform the scanning only if the current partition has
            // at least three elements.
            left = 0;
            idxA_idx_0 = MedianFilter_cam_front_B.idxHLin;
            while (idxA_idx_0 > left + 1) {
              // Use the median of the three values as the partitioning key
              // Use median-of-three method to return the partitioning key (pivot). 
              // This method makes worst-case behavior much less likely and
              // avoids the needs for sentinel values outside the array.
              // //////////////////////////////////////////////////////////////////// 
              // First we sort the first, middle, and last element of the partition. 
              mid = (left + idxA_idx_0) >> 1;
              if (MedianFilter_cam_front_B.uW[left] >
                  MedianFilter_cam_front_B.uW[mid]) {
                temp = MedianFilter_cam_front_B.uW[left];
                MedianFilter_cam_front_B.uW[left] =
                  MedianFilter_cam_front_B.uW[mid];
                MedianFilter_cam_front_B.uW[mid] = temp;
              }

              if (MedianFilter_cam_front_B.uW[left] >
                  MedianFilter_cam_front_B.uW[idxA_idx_0]) {
                temp = MedianFilter_cam_front_B.uW[left];
                MedianFilter_cam_front_B.uW[left] =
                  MedianFilter_cam_front_B.uW[idxA_idx_0];
                MedianFilter_cam_front_B.uW[idxA_idx_0] = temp;
              }

              if (MedianFilter_cam_front_B.uW[mid] >
                  MedianFilter_cam_front_B.uW[idxA_idx_0]) {
                temp = MedianFilter_cam_front_B.uW[mid];
                MedianFilter_cam_front_B.uW[mid] =
                  MedianFilter_cam_front_B.uW[idxA_idx_0];
                MedianFilter_cam_front_B.uW[idxA_idx_0] = temp;
              }

              // //////////////////////////////////////////////////////////////////// 
              // Now swap the middle value with the next-to-last value.
              temp = MedianFilter_cam_front_B.uW[mid];
              MedianFilter_cam_front_B.uW[mid] =
                MedianFilter_cam_front_B.uW[idxA_idx_0 - 1];
              MedianFilter_cam_front_B.uW[idxA_idx_0 - 1] = temp;

              // return pivot for partitioning
              pivot = MedianFilter_cam_front_B.uW[idxA_idx_0 - 1];

              // Start the partitioning scan.  Note that because we sorted
              // the left and right values, we can start the comparisons
              // with (left+1) and (right-2).  This is how we avoid the
              // need for sentinel values.
              mid = left;
              rightIdx = idxA_idx_0 - 1;
              do {
                exitg1 = 0;
                do {
                  mid++;
                } while (MedianFilter_cam_front_B.uW[mid] < pivot);

                do {
                  rightIdx--;
                } while (MedianFilter_cam_front_B.uW[rightIdx] > pivot);

                // pointers crossed -> end scan
                if (mid >= rightIdx) {
                  exitg1 = 1;
                } else {
                  // Swap values at end of current interval.
                  temp = MedianFilter_cam_front_B.uW[mid];
                  MedianFilter_cam_front_B.uW[mid] =
                    MedianFilter_cam_front_B.uW[rightIdx];
                  MedianFilter_cam_front_B.uW[rightIdx] = temp;
                }
              } while (exitg1 == 0);

              // One last swap needed at end of scan
              temp = MedianFilter_cam_front_B.uW[mid];
              MedianFilter_cam_front_B.uW[mid] =
                MedianFilter_cam_front_B.uW[idxA_idx_0 - 1];
              MedianFilter_cam_front_B.uW[idxA_idx_0 - 1] = temp;

              // Select the left or right subpartition depending on
              // the value of order.
              if (mid >= hIdxA_idx_1) {
                idxA_idx_0 = mid - 1;
              }

              if (mid <= hIdxA_idx_1) {
                left = mid + 1;
              }
            }

            if ((idxA_idx_0 - left == 1) && (MedianFilter_cam_front_B.uW[left] >
                 MedianFilter_cam_front_B.uW[idxA_idx_0])) {
              // Last partition has two elements that may not be sorted.
              temp = MedianFilter_cam_front_B.uW[left];
              MedianFilter_cam_front_B.uW[left] =
                MedianFilter_cam_front_B.uW[idxA_idx_0];
              MedianFilter_cam_front_B.uW[idxA_idx_0] = temp;
            }

            acc = MedianFilter_cam_front_B.uW[hIdxA_idx_1];

            // Perform the scanning only if the current partition has
            // at least three elements.
            left = 0;
            while (MedianFilter_cam_front_B.idxHLin > left + 1) {
              // Use the median of the three values as the partitioning key
              // Use median-of-three method to return the partitioning key (pivot). 
              // This method makes worst-case behavior much less likely and
              // avoids the needs for sentinel values outside the array.
              // //////////////////////////////////////////////////////////////////// 
              // First we sort the first, middle, and last element of the partition. 
              mid = (left + MedianFilter_cam_front_B.idxHLin) >> 1;
              if (MedianFilter_cam_front_B.uW[left] >
                  MedianFilter_cam_front_B.uW[mid]) {
                temp = MedianFilter_cam_front_B.uW[left];
                MedianFilter_cam_front_B.uW[left] =
                  MedianFilter_cam_front_B.uW[mid];
                MedianFilter_cam_front_B.uW[mid] = temp;
              }

              if (MedianFilter_cam_front_B.uW[left] >
                  MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin])
              {
                temp = MedianFilter_cam_front_B.uW[left];
                MedianFilter_cam_front_B.uW[left] =
                  MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin];
                MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin] =
                  temp;
              }

              if (MedianFilter_cam_front_B.uW[mid] >
                  MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin])
              {
                temp = MedianFilter_cam_front_B.uW[mid];
                MedianFilter_cam_front_B.uW[mid] =
                  MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin];
                MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin] =
                  temp;
              }

              // //////////////////////////////////////////////////////////////////// 
              // Now swap the middle value with the next-to-last value.
              temp = MedianFilter_cam_front_B.uW[mid];
              MedianFilter_cam_front_B.uW[mid] =
                MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin - 1];
              MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin - 1] =
                temp;

              // return pivot for partitioning
              pivot =
                MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin - 1];

              // Start the partitioning scan.  Note that because we sorted
              // the left and right values, we can start the comparisons
              // with (left+1) and (right-2).  This is how we avoid the
              // need for sentinel values.
              mid = left;
              rightIdx = MedianFilter_cam_front_B.idxHLin - 1;
              do {
                exitg1 = 0;
                do {
                  mid++;
                } while (MedianFilter_cam_front_B.uW[mid] < pivot);

                do {
                  rightIdx--;
                } while (MedianFilter_cam_front_B.uW[rightIdx] > pivot);

                // pointers crossed -> end scan
                if (mid >= rightIdx) {
                  exitg1 = 1;
                } else {
                  // Swap values at end of current interval.
                  temp = MedianFilter_cam_front_B.uW[mid];
                  MedianFilter_cam_front_B.uW[mid] =
                    MedianFilter_cam_front_B.uW[rightIdx];
                  MedianFilter_cam_front_B.uW[rightIdx] = temp;
                }
              } while (exitg1 == 0);

              // One last swap needed at end of scan
              temp = MedianFilter_cam_front_B.uW[mid];
              MedianFilter_cam_front_B.uW[mid] =
                MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin - 1];
              MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin - 1] =
                temp;

              // Select the left or right subpartition depending on
              // the value of order.
              if (mid >= hIdxA_idx_1 + 1) {
                MedianFilter_cam_front_B.idxHLin = mid - 1;
              }

              if (mid <= hIdxA_idx_1 + 1) {
                left = mid + 1;
              }
            }

            if ((MedianFilter_cam_front_B.idxHLin - left == 1) &&
                (MedianFilter_cam_front_B.uW[left] >
                 MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin]))
            {
              // Last partition has two elements that may not be sorted.
              temp = MedianFilter_cam_front_B.uW[left];
              MedianFilter_cam_front_B.uW[left] =
                MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin];
              MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin] =
                temp;
            }

            acc = static_cast<uint16_T>(static_cast<uint32_T>
              (MedianFilter_cam_front_B.uW[hIdxA_idx_1 + 1]) + acc);
            temp = static_cast<uint16_T>(static_cast<uint32_T>(acc) >> 1);
          } else {
            // Perform the scanning only if the current partition has
            // at least three elements.
            left = 0;
            while (MedianFilter_cam_front_B.idxHLin > left + 1) {
              // Use the median of the three values as the partitioning key
              // Use median-of-three method to return the partitioning key (pivot). 
              // This method makes worst-case behavior much less likely and
              // avoids the needs for sentinel values outside the array.
              // //////////////////////////////////////////////////////////////////// 
              // First we sort the first, middle, and last element of the partition. 
              mid = (left + MedianFilter_cam_front_B.idxHLin) >> 1;
              if (MedianFilter_cam_front_B.uW[left] >
                  MedianFilter_cam_front_B.uW[mid]) {
                temp = MedianFilter_cam_front_B.uW[left];
                MedianFilter_cam_front_B.uW[left] =
                  MedianFilter_cam_front_B.uW[mid];
                MedianFilter_cam_front_B.uW[mid] = temp;
              }

              if (MedianFilter_cam_front_B.uW[left] >
                  MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin])
              {
                temp = MedianFilter_cam_front_B.uW[left];
                MedianFilter_cam_front_B.uW[left] =
                  MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin];
                MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin] =
                  temp;
              }

              if (MedianFilter_cam_front_B.uW[mid] >
                  MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin])
              {
                temp = MedianFilter_cam_front_B.uW[mid];
                MedianFilter_cam_front_B.uW[mid] =
                  MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin];
                MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin] =
                  temp;
              }

              // //////////////////////////////////////////////////////////////////// 
              // Now swap the middle value with the next-to-last value.
              temp = MedianFilter_cam_front_B.uW[mid];
              MedianFilter_cam_front_B.uW[mid] =
                MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin - 1];
              MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin - 1] =
                temp;

              // return pivot for partitioning
              pivot =
                MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin - 1];

              // Start the partitioning scan.  Note that because we sorted
              // the left and right values, we can start the comparisons
              // with (left+1) and (right-2).  This is how we avoid the
              // need for sentinel values.
              mid = left;
              rightIdx = MedianFilter_cam_front_B.idxHLin - 1;
              do {
                exitg1 = 0;
                do {
                  mid++;
                } while (MedianFilter_cam_front_B.uW[mid] < pivot);

                do {
                  rightIdx--;
                } while (MedianFilter_cam_front_B.uW[rightIdx] > pivot);

                // pointers crossed -> end scan
                if (mid >= rightIdx) {
                  exitg1 = 1;
                } else {
                  // Swap values at end of current interval.
                  temp = MedianFilter_cam_front_B.uW[mid];
                  MedianFilter_cam_front_B.uW[mid] =
                    MedianFilter_cam_front_B.uW[rightIdx];
                  MedianFilter_cam_front_B.uW[rightIdx] = temp;
                }
              } while (exitg1 == 0);

              // One last swap needed at end of scan
              temp = MedianFilter_cam_front_B.uW[mid];
              MedianFilter_cam_front_B.uW[mid] =
                MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin - 1];
              MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin - 1] =
                temp;

              // Select the left or right subpartition depending on
              // the value of order.
              if (mid >= hIdxA_idx_1) {
                MedianFilter_cam_front_B.idxHLin = mid - 1;
              }

              if (mid <= hIdxA_idx_1) {
                left = mid + 1;
              }
            }

            if ((MedianFilter_cam_front_B.idxHLin - left == 1) &&
                (MedianFilter_cam_front_B.uW[left] >
                 MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin]))
            {
              // Last partition has two elements that may not be sorted.
              temp = MedianFilter_cam_front_B.uW[left];
              MedianFilter_cam_front_B.uW[left] =
                MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin];
              MedianFilter_cam_front_B.uW[MedianFilter_cam_front_B.idxHLin] =
                temp;
            }

            temp = MedianFilter_cam_front_B.uW[hIdxA_idx_1];
          }

          if (idxBLin_idx_0 >= 0) {
            y[idxBLin_idx_0] = temp;
          }
        }

        MedianFilter_cam_front_B.yPre++;
      }
    }

    // advance sector counter
    MedianFilter_cam_front_B.yPost = 0;
    while (MedianFilter_cam_front_B.yPost < 2) {
      MedianFilter_cam_front_B.c[MedianFilter_cam_front_B.yPost]++;
      if (MedianFilter_cam_front_B.c[MedianFilter_cam_front_B.yPost] <= 2) {
        isEnd = false;
        MedianFilter_cam_front_B.yPost = 2;
      } else {
        MedianFilter_cam_front_B.c[MedianFilter_cam_front_B.yPost] = 0;
        isEnd = true;
      }

      MedianFilter_cam_front_B.yPost++;
    }
  }

  // End of S-Function (svipmdnfilter): '<S3>/Median Filter'
}

static void matlabCodegenHandle_matlabCod_a(ros_slros_internal_block_Subs_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Publ_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

// Model step function
void MedianFilter_cam_front_step(void)
{
  uint8_T b_varargout_2_IsBigendian;
  boolean_T b_varargout_1;
  if (MedianFilter_cam_front_M->Timing.TaskCounters.TID[1] == 0) {
    // Outputs for Atomic SubSystem: '<Root>/Subscribe'
    // MATLABSystem: '<S2>/SourceBlock' incorporates:
    //   Inport: '<S4>/In1'

    MedianFilter_ca_SystemCore_step(&b_varargout_1,
      &MedianFilter_cam_front_B.b_varargout_2_Height,
      &MedianFilter_cam_front_B.b_varargout_2_Width,
      MedianFilter_cam_front_B.b_varargout_2_Encoding,
      &MedianFilter_cam_front_B.b_varargout_2_Encoding_SL_Info_,
      &MedianFilter_cam_front_B.b_varargout_2_Encoding_SL_Inf_c,
      &b_varargout_2_IsBigendian, &MedianFilter_cam_front_B.b_varargout_2_Step,
      MedianFilter_cam_front_B.b_varargout_2_Data,
      &MedianFilter_cam_front_B.b_varargout_2_Data_SL_Info_Curr,
      &MedianFilter_cam_front_B.b_varargout_2_Data_SL_Info_Rece,
      &MedianFilter_cam_front_B.b_varargout_2_Header_Seq,
      MedianFilter_cam_front_B.b_varargout_2_Header_FrameId,
      &MedianFilter_cam_front_B.b_varargout_2_Header_FrameId_SL,
      &MedianFilter_cam_front_B.b_varargout_2_Header_FrameId__p,
      &MedianFilter_cam_front_B.b_varargout_2_Header_Stamp);

    // Outputs for Enabled SubSystem: '<S2>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S4>/Enable'

    if (b_varargout_1) {
      MedianFilter_cam_front_B.In1.Height =
        MedianFilter_cam_front_B.b_varargout_2_Height;
      MedianFilter_cam_front_B.In1.Width =
        MedianFilter_cam_front_B.b_varargout_2_Width;
      MedianFilter_cam_front_B.In1.Encoding_SL_Info.CurrentLength =
        MedianFilter_cam_front_B.b_varargout_2_Encoding_SL_Info_;
      MedianFilter_cam_front_B.In1.Encoding_SL_Info.ReceivedLength =
        MedianFilter_cam_front_B.b_varargout_2_Encoding_SL_Inf_c;
      MedianFilter_cam_front_B.In1.IsBigendian = b_varargout_2_IsBigendian;
      MedianFilter_cam_front_B.In1.Step =
        MedianFilter_cam_front_B.b_varargout_2_Step;
      memcpy(&MedianFilter_cam_front_B.In1.Encoding[0],
             &MedianFilter_cam_front_B.b_varargout_2_Encoding[0], 1036800U *
             sizeof(uint8_T));
      memcpy(&MedianFilter_cam_front_B.In1.Data[0],
             &MedianFilter_cam_front_B.b_varargout_2_Data[0], 1036800U * sizeof
             (uint8_T));
      MedianFilter_cam_front_B.In1.Data_SL_Info.CurrentLength =
        MedianFilter_cam_front_B.b_varargout_2_Data_SL_Info_Curr;
      MedianFilter_cam_front_B.In1.Data_SL_Info.ReceivedLength =
        MedianFilter_cam_front_B.b_varargout_2_Data_SL_Info_Rece;
      MedianFilter_cam_front_B.In1.Header.Seq =
        MedianFilter_cam_front_B.b_varargout_2_Header_Seq;
      memcpy(&MedianFilter_cam_front_B.In1.Header.FrameId[0],
             &MedianFilter_cam_front_B.b_varargout_2_Header_FrameId[0], sizeof
             (uint8_T) << 7U);
      MedianFilter_cam_front_B.In1.Header.FrameId_SL_Info.CurrentLength =
        MedianFilter_cam_front_B.b_varargout_2_Header_FrameId_SL;
      MedianFilter_cam_front_B.In1.Header.FrameId_SL_Info.ReceivedLength =
        MedianFilter_cam_front_B.b_varargout_2_Header_FrameId__p;
      MedianFilter_cam_front_B.In1.Header.Stamp =
        MedianFilter_cam_front_B.b_varargout_2_Header_Stamp;
    }

    // End of Outputs for SubSystem: '<S2>/Enabled Subsystem'

    // Outputs for Triggered SubSystem: '<Root>/Subsystem' incorporates:
    //   TriggerPort: '<S3>/Trigger'

    if (b_varargout_1 && (MedianFilter_cam_front_PrevZCX.Subsystem_Trig_ZCE !=
                          POS_ZCSIG)) {
      // S-Function (byte2any_svd): '<S3>/Byte Unpack'

      // Unpack: <S3>/Byte Unpack
      {
        uint32_T MW_inputPortOffset = 0;
        uint32_T MW_outputPortWidth = 0;
        uint32_T MW_remainder2 = 0;

        // Packed input data type - uint8_T
        // Unpacking the values to output 1
        // Output data type - uint16_T, size - 518400
        {
          MW_outputPortWidth = 518400 * sizeof(uint16_T);
          memcpy((uint8_T*)&MedianFilter_cam_front_B.ByteUnpack[0], (uint8_T*)
                 &MedianFilter_cam_front_B.In1.Data[0] + MW_inputPortOffset,
                 MW_outputPortWidth);
        }
      }

      // PermuteDimensions: '<S3>/Permute Dimensions'
      MedianFilter_cam_front_B.yElIdx = 0;
      MedianFilter_cam_front_B.uElOffset1 = 0;
      for (MedianFilter_cam_front_B.ntIdx1 = 0; MedianFilter_cam_front_B.ntIdx1 <
           960; MedianFilter_cam_front_B.ntIdx1++) {
        MedianFilter_cam_front_B.uElOffset0 =
          MedianFilter_cam_front_B.uElOffset1;
        for (MedianFilter_cam_front_B.ntIdx0 = 0;
             MedianFilter_cam_front_B.ntIdx0 < 540;
             MedianFilter_cam_front_B.ntIdx0++) {
          MedianFilter_cam_front_B.PermuteDimensions[MedianFilter_cam_front_B.yElIdx]
            =
            MedianFilter_cam_front_B.ByteUnpack[MedianFilter_cam_front_B.uElOffset0];
          MedianFilter_cam_front_B.yElIdx++;
          MedianFilter_cam_front_B.uElOffset0 += 960;
        }

        MedianFilter_cam_front_B.uElOffset1++;
      }

      // End of PermuteDimensions: '<S3>/Permute Dimensions'

      // S-Function (svipmdnfilter): '<S3>/Median Filter'
      MedianFilter_cam_front_B.h1Dims[0U] = 5;
      MedianFilter_cam_front_B.h1Dims[1U] = 5;
      MedianFilter_cam_front_B.uDims[0U] = 540;
      MedianFilter_cam_front_B.uDims[1U] = 960;

      // set up kernel related coordinates
      // compute center
      // hLoc is the location of top left corner relative to the center of kernel. 
      MedianFilter_cam_front_B.hLoc[0U] = -2;

      // compute center
      // hLoc is the location of top left corner relative to the center of kernel. 
      MedianFilter_cam_front_B.hLoc[1U] = -2;

      // Region of Support (ROS) definition: A selected region that restricts the input space for processing. 
      // ======================================================
      //                       ---------------------
      //                      |ROI                  |
      //                      |                     |
      //  ----------------------------------------------------
      // | INPUT(u)           |                     |         |
      // |                    |                     |         |
      // |   ---------------------------------------------    |
      // |  | ROS             |OUTPUT(y)////////////|     |   |
      // |  |                 |/////////////////////|     |   |
      // |  |                  ---------------------      |   |
      // |  |                                             |   |
      // The user's output mode choices of 'Valid', 'Same as input' and 'Full' map onto correspending definitions of a rectangular ROS. 
      // Output range support is computed as an intersection of ROS with Region of Interest (ROI) 
      // /////////////////////
      // begin ROS computation
      // compute ROS based on u, h and output mode
      // ROS is SAME AS INPUT
      // end ROS computation
      // ///////////////////
      // /////////////////////////
      // begin y sizes computation
      // we need to compute yOrigin and yEnd
      // yOrigin definition: Location of center of reference (origin) of output (y) coordintate system with respect to input (u) coordinate system 
      // y sizes are same as ros sizes because there is no ROI
      MedianFilter_cam_front_B.yOrigin[0U] = 0;
      MedianFilter_cam_front_B.yDims[0U] = 540;

      // y sizes are same as ros sizes because there is no ROI
      MedianFilter_cam_front_B.yOrigin[1U] = 0;
      MedianFilter_cam_front_B.yDims[1U] = 960;

      // make yOrigin same as roiLoc when y is empty
      // end y sizes computation
      // ///////////////////////
      MdnFltH25_M_IBSymm_uu1_hBk7vz_a(&MedianFilter_cam_front_B.hLoc[0U],
        &MedianFilter_cam_front_B.h1Dims[0U],
        &MedianFilter_cam_front_B.PermuteDimensions[0U],
        &MedianFilter_cam_front_B.uDims[0U],
        &MedianFilter_cam_front_B.MedianFilter[0U],
        &MedianFilter_cam_front_B.yDims[0U], &MedianFilter_cam_front_B.yOrigin
        [0U]);

      // PermuteDimensions: '<S3>/Permute Dimensions1'
      MedianFilter_cam_front_B.yElIdx = 0;
      MedianFilter_cam_front_B.uElOffset1 = 0;
      for (MedianFilter_cam_front_B.ntIdx1 = 0; MedianFilter_cam_front_B.ntIdx1 <
           540; MedianFilter_cam_front_B.ntIdx1++) {
        MedianFilter_cam_front_B.uElOffset0 =
          MedianFilter_cam_front_B.uElOffset1;
        for (MedianFilter_cam_front_B.ntIdx0 = 0;
             MedianFilter_cam_front_B.ntIdx0 < 960;
             MedianFilter_cam_front_B.ntIdx0++) {
          MedianFilter_cam_front_B.PermuteDimensions1[MedianFilter_cam_front_B.yElIdx]
            =
            MedianFilter_cam_front_B.MedianFilter[MedianFilter_cam_front_B.uElOffset0];
          MedianFilter_cam_front_B.yElIdx++;
          MedianFilter_cam_front_B.uElOffset0 += 540;
        }

        MedianFilter_cam_front_B.uElOffset1++;
      }

      // End of PermuteDimensions: '<S3>/Permute Dimensions1'

      // S-Function (any2byte_svd): '<S3>/Byte Pack1'

      // Pack: <S3>/Byte Pack1
      {
        uint32_T MW_outputPortOffset = 0;
        uint32_T MW_inputPortWidth = 0;
        uint32_T MW_remainder1 = 0;

        // Packed output data type - uint8_T
        // Packing the values of Input 1
        // Input data type - uint16_T, size - 518400
        {
          MW_inputPortWidth = 518400 * sizeof(uint16_T);
          memcpy((uint8_T*)((uint8_T*)&MedianFilter_cam_front_B.BytePack1[0] +
                            MW_outputPortOffset), (uint8_T*)
                 &MedianFilter_cam_front_B.PermuteDimensions1[0],
                 MW_inputPortWidth);
        }
      }

      // BusAssignment: '<S3>/Bus Assignment1' incorporates:
      //   Constant: '<S5>/Constant'

      MedianFilter_cam_front_B.BusAssignment1 =
        MedianFilter_cam_front_P.Constant_Value_m;
      MedianFilter_cam_front_B.BusAssignment1.Height =
        MedianFilter_cam_front_B.In1.Height;
      MedianFilter_cam_front_B.BusAssignment1.Width =
        MedianFilter_cam_front_B.In1.Width;
      MedianFilter_cam_front_B.BusAssignment1.Encoding_SL_Info =
        MedianFilter_cam_front_B.In1.Encoding_SL_Info;
      MedianFilter_cam_front_B.BusAssignment1.IsBigendian =
        MedianFilter_cam_front_B.In1.IsBigendian;
      MedianFilter_cam_front_B.BusAssignment1.Step =
        MedianFilter_cam_front_B.In1.Step;
      memcpy(&MedianFilter_cam_front_B.BusAssignment1.Encoding[0],
             &MedianFilter_cam_front_B.In1.Encoding[0], 1036800U * sizeof
             (uint8_T));
      memcpy(&MedianFilter_cam_front_B.BusAssignment1.Data[0],
             &MedianFilter_cam_front_B.BytePack1[0], 1036800U * sizeof(uint8_T));
      MedianFilter_cam_front_B.BusAssignment1.Data_SL_Info =
        MedianFilter_cam_front_B.In1.Data_SL_Info;
      MedianFilter_cam_front_B.BusAssignment1.Header =
        MedianFilter_cam_front_B.In1.Header;
    }

    MedianFilter_cam_front_PrevZCX.Subsystem_Trig_ZCE = b_varargout_1;

    // End of MATLABSystem: '<S2>/SourceBlock'
    // End of Outputs for SubSystem: '<Root>/Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe'

    // Outputs for Atomic SubSystem: '<Root>/Publish'
    // MATLABSystem: '<S1>/SinkBlock'
    Pub_MedianFilter_cam_front_47.publish
      (&MedianFilter_cam_front_B.BusAssignment1);

    // End of Outputs for SubSystem: '<Root>/Publish'
  }

  rate_scheduler();
}

// Model initialize function
void MedianFilter_cam_front_initialize(void)
{
  // Registration code

  // block I/O
  (void) memset((static_cast<void *>(&MedianFilter_cam_front_B)), 0,
                sizeof(B_MedianFilter_cam_front_T));

  // states (dwork)
  (void) memset(static_cast<void *>(&MedianFilter_cam_front_DW), 0,
                sizeof(DW_MedianFilter_cam_front_T));

  {
    char_T tmp[30];
    int32_T i;
    static const char_T tmp_0[29] = { '/', 'k', 'i', 'n', 'e', 'c', 't', '2',
      '/', 'q', 'h', 'd', '/', 'i', 'm', 'a', 'g', 'e', '_', 'd', 'e', 'p', 't',
      'h', '_', 'r', 'e', 'c', 't' };

    static const char_T tmp_1[33] = { '/', 'k', 'i', 'n', 'e', 'c', 't', '2',
      '/', 'q', 'h', 'd', '/', 'd', 'e', 'p', 't', 'h', '_', 'i', 'm', 'a', 'g',
      'e', '_', 'f', 'i', 'l', 't', 'e', 'r', 'e', 'd' };

    MedianFilter_cam_front_PrevZCX.Subsystem_Trig_ZCE = POS_ZCSIG;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S2>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S4>/Out1'
    MedianFilter_cam_front_B.In1 = MedianFilter_cam_front_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S2>/Enabled Subsystem'

    // Start for MATLABSystem: '<S2>/SourceBlock'
    MedianFilter_cam_front_DW.obj_f.matlabCodegenIsDeleted = false;
    MedianFilter_cam_front_DW.obj_f.isInitialized = 1;
    for (i = 0; i < 29; i++) {
      tmp[i] = tmp_0[i];
    }

    tmp[29] = '\x00';
    Sub_MedianFilter_cam_front_46.createSubscriber(tmp, 1);
    MedianFilter_cam_front_DW.obj_f.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S2>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Triggered SubSystem: '<Root>/Subsystem'
    // SystemInitialize for Outport: '<S3>/Out1'
    MedianFilter_cam_front_B.BusAssignment1 = MedianFilter_cam_front_P.Out1_Y0_n;

    // End of SystemInitialize for SubSystem: '<Root>/Subsystem'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S1>/SinkBlock'
    MedianFilter_cam_front_DW.obj.matlabCodegenIsDeleted = false;
    MedianFilter_cam_front_DW.obj.isInitialized = 1;
    for (i = 0; i < 33; i++) {
      MedianFilter_cam_front_B.cv[i] = tmp_1[i];
    }

    MedianFilter_cam_front_B.cv[33] = '\x00';
    Pub_MedianFilter_cam_front_47.createPublisher(MedianFilter_cam_front_B.cv, 1);
    MedianFilter_cam_front_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S1>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'
  }
}

// Model terminate function
void MedianFilter_cam_front_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S2>/SourceBlock'
  matlabCodegenHandle_matlabCod_a(&MedianFilter_cam_front_DW.obj_f);

  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S1>/SinkBlock'
  matlabCodegenHandle_matlabCodeg(&MedianFilter_cam_front_DW.obj);

  // End of Terminate for SubSystem: '<Root>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
