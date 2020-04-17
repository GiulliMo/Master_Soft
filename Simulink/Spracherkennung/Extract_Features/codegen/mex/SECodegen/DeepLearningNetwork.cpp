//
//  Academic License - for use in teaching, academic research, and meeting
//  course requirements at degree granting institutions only.  Not for
//  government, commercial, or other organizational use.
//
//  DeepLearningNetwork.cpp
//
//  Code generation for function 'DeepLearningNetwork'
//


// Include files
#include "DeepLearningNetwork.h"
#include "MWDeepLearningUtils.hpp"
#include "SECodegen.h"
#include "SECodegen_mexutil.h"
#include "rt_nonfinite.h"
#include <string.h>

// Type Definitions
#include "MWElementwiseAffineLayer.hpp"
#include "cnn_api.hpp"
#include "MWFusedConvReLULayer.hpp"
#include "MWTargetNetworkImpl.hpp"

// Function Definitions
void b_commandNet_0::allocate()
{
  this->targetImpl->allocate(2, this->layers, this->numLayers);
  for (int32_T idx = 0; idx < 15; idx++) {
    this->layers[idx]->allocate();
  }

  this->inputTensor->setData(this->layers[0]->getLayerOutput(0));
  this->outputTensor->setData(this->layers[14]->getLayerOutput(0));
}

void b_commandNet_0::cleanup()
{
  this->deallocate();
  for (int32_T idx = 0; idx < 15; idx++) {
    this->layers[idx]->cleanup();
  }

  if (this->targetImpl) {
    this->targetImpl->cleanup();
  }
}

b_commandNet_0::b_commandNet_0()
{
  this->numLayers = 15;
  this->targetImpl = 0;
  this->layers[0] = new MWInputLayer;
  this->layers[0]->setName("imageinput");
  this->layers[1] = new MWElementwiseAffineLayer;
  this->layers[1]->setName("imageinput_normalization");
  this->layers[2] = new MWFusedConvReLULayer;
  this->layers[2]->setName("conv_1_relu_1");
  this->layers[3] = new MWMaxPoolingLayer;
  this->layers[3]->setName("maxpool_1");
  this->layers[4] = new MWFusedConvReLULayer;
  this->layers[4]->setName("conv_2_relu_2");
  this->layers[5] = new MWMaxPoolingLayer;
  this->layers[5]->setName("maxpool_2");
  this->layers[6] = new MWFusedConvReLULayer;
  this->layers[6]->setName("conv_3_relu_3");
  this->layers[7] = new MWMaxPoolingLayer;
  this->layers[7]->setName("maxpool_3");
  this->layers[8] = new MWFusedConvReLULayer;
  this->layers[8]->setName("conv_4_relu_4");
  this->layers[9] = new MWFusedConvReLULayer;
  this->layers[9]->setName("conv_5_relu_5");
  this->layers[10] = new MWMaxPoolingLayer;
  this->layers[10]->setName("maxpool_4");
  this->layers[11] = new MWPassthroughLayer;
  this->layers[11]->setName("dropout");
  this->layers[12] = new MWFCLayer;
  this->layers[12]->setName("fc");
  this->layers[13] = new MWSoftmaxLayer;
  this->layers[13]->setName("softmax");
  this->layers[14] = new MWOutputLayer;
  this->layers[14]->setName("classoutput");
  this->targetImpl = new MWTargetNetworkImpl;
  this->inputTensor = new MWTensor;
  this->inputTensor->setHeight(98);
  this->inputTensor->setWidth(50);
  this->inputTensor->setChannels(1);
  this->inputTensor->setBatchSize(1);
  this->inputTensor->setSequenceLength(1);
  this->outputTensor = new MWTensor;
}

b_commandNet_0::~b_commandNet_0()
{
  this->cleanup();
  for (int32_T idx = 0; idx < 15; idx++) {
    delete this->layers[idx];
  }

  if (this->targetImpl) {
    delete this->targetImpl;
  }

  delete this->inputTensor;
  delete this->outputTensor;
}

void b_commandNet_0::deallocate()
{
  this->targetImpl->deallocate();
  for (int32_T idx = 0; idx < 15; idx++) {
    this->layers[idx]->deallocate();
  }
}

real32_T *b_commandNet_0::getInputDataPointer()
{
  return this->inputTensor->getFloatData();
}

real32_T *b_commandNet_0::getLayerOutput(int32_T layerIndex, int32_T portIndex)
{
  return this->targetImpl->getLayerOutput(this->layers, layerIndex, portIndex);
}

real32_T *b_commandNet_0::getOutputDataPointer()
{
  return this->outputTensor->getFloatData();
}

void b_commandNet_0::postsetup()
{
  this->targetImpl->postSetup();
}

void b_commandNet_0::predict()
{
  for (int32_T idx = 0; idx < 15; idx++) {
    this->layers[idx]->predict();
  }
}

void b_commandNet_0::setSize()
{
  for (int32_T idx = 0; idx < 15; idx++) {
    this->layers[idx]->propagateSize();
  }

  this->allocate();
  this->postsetup();
}

void b_commandNet_0::setup()
{
  this->targetImpl->preSetup();
  (dynamic_cast<MWInputLayer *>(this->layers[0]))->createInputLayer
    (this->targetImpl, this->inputTensor, 98, 50, 1, 0, "", 0);
  (dynamic_cast<MWElementwiseAffineLayer *>(this->layers[1]))
    ->createElementwiseAffineLayer(this->targetImpl, this->layers[0]
    ->getOutputTensor(0), 1, 1, 1, 1, 1, 1, false, 1, 1,
    "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/Extract_Features/codegen/mex/SECodegen/cnn_commandNet_imageinput_sca"
    "le.bin",
    "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/Extract_Features/codegen/mex/SECodegen/cnn_commandNet_imageinput_off"
    "set.bin", 1);
  (dynamic_cast<MWFusedConvReLULayer *>(this->layers[2]))
    ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[1]
    ->getOutputTensor(0), 3, 3, 1, 12, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/Extract_Features/codegen/mex/SECodegen/cnn_commandNet_conv_1_w.bin",
    "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/Extract_Features/codegen/mex/SECodegen/cnn_commandNet_conv_1_b.bin",
    0);
  (dynamic_cast<MWMaxPoolingLayer *>(this->layers[3]))->createMaxPoolingLayer
    (this->targetImpl, this->layers[2]->getOutputTensor(0), 3, 3, 2, 2, 0, 1, 0,
     1, 0, 1, 1);
  (dynamic_cast<MWFusedConvReLULayer *>(this->layers[4]))
    ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[3]
    ->getOutputTensor(0), 3, 3, 12, 24, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/Extract_Features/codegen/mex/SECodegen/cnn_commandNet_conv_2_w.bin",
    "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/Extract_Features/codegen/mex/SECodegen/cnn_commandNet_conv_2_b.bin",
    0);
  (dynamic_cast<MWMaxPoolingLayer *>(this->layers[5]))->createMaxPoolingLayer
    (this->targetImpl, this->layers[4]->getOutputTensor(0), 3, 3, 2, 2, 1, 1, 1,
     1, 0, 1, 1);
  (dynamic_cast<MWFusedConvReLULayer *>(this->layers[6]))
    ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[5]
    ->getOutputTensor(0), 3, 3, 24, 48, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/Extract_Features/codegen/mex/SECodegen/cnn_commandNet_conv_3_w.bin",
    "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/Extract_Features/codegen/mex/SECodegen/cnn_commandNet_conv_3_b.bin",
    0);
  (dynamic_cast<MWMaxPoolingLayer *>(this->layers[7]))->createMaxPoolingLayer
    (this->targetImpl, this->layers[6]->getOutputTensor(0), 3, 3, 2, 2, 1, 1, 1,
     1, 0, 1, 1);
  (dynamic_cast<MWFusedConvReLULayer *>(this->layers[8]))
    ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[7]
    ->getOutputTensor(0), 3, 3, 48, 48, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/Extract_Features/codegen/mex/SECodegen/cnn_commandNet_conv_4_w.bin",
    "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/Extract_Features/codegen/mex/SECodegen/cnn_commandNet_conv_4_b.bin",
    0);
  (dynamic_cast<MWFusedConvReLULayer *>(this->layers[9]))
    ->createFusedConvReLULayer(this->targetImpl, 1, this->layers[8]
    ->getOutputTensor(0), 3, 3, 48, 48, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/Extract_Features/codegen/mex/SECodegen/cnn_commandNet_conv_5_w.bin",
    "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/Extract_Features/codegen/mex/SECodegen/cnn_commandNet_conv_5_b.bin",
    1);
  (dynamic_cast<MWMaxPoolingLayer *>(this->layers[10]))->createMaxPoolingLayer
    (this->targetImpl, this->layers[9]->getOutputTensor(0), 13, 1, 1, 1, 0, 0, 0,
     0, 0, 1, 0);
  (dynamic_cast<MWPassthroughLayer *>(this->layers[11]))->createPassthroughLayer
    (this->targetImpl, this->layers[10]->getOutputTensor(0), 0);
  (dynamic_cast<MWFCLayer *>(this->layers[12]))->createFCLayer(this->targetImpl,
    this->layers[11]->getOutputTensor(0), 336, 12,
    "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/Extract_Features/codegen/mex/SECodegen/cnn_commandNet_fc_w.bin",
    "/home/alf/Schreibtisch/Master_Soft/Simulink/Spracherkennung/Extract_Features/codegen/mex/SECodegen/cnn_commandNet_fc_b.bin",
    1);
  (dynamic_cast<MWSoftmaxLayer *>(this->layers[13]))->createSoftmaxLayer
    (this->targetImpl, this->layers[12]->getOutputTensor(0), 0);
  (dynamic_cast<MWOutputLayer *>(this->layers[14]))->createOutputLayer
    (this->targetImpl, this->layers[13]->getOutputTensor(0), 0);
  this->setSize();
}

void DeepLearningNetwork_setup(b_commandNet_0 *obj)
{
  TRY_DL_ERROR_CHECK();
  obj->setup();
  CATCH_DL_ERROR_CHECK();
  checkRunTimeError(err.what(), __FILE__, __LINE__);
  LEAVE_DL_ERROR_CHECK();
  obj->batchSize = 1;
}

// End of code generation (DeepLearningNetwork.cpp)
