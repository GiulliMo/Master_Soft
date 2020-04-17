#include "MWElementwiseAffineLayerImpl.hpp"
#include "MWTargetNetworkImpl.hpp"
#include "cnn_api.hpp"
#include <math.h>
#include <cassert>
#include <stdio.h>
#include <algorithm>
#include "MWMkldnnUtils.hpp"
 MWElementwiseAffineLayerImpl::MWElementwiseAffineLayerImpl(MWCNNLayer* layer, 
MWTargetNetworkImpl* ntwk_impl, int scale_H, int scale_W, int scale_C, int 
offset_H, int offset_W, int offset_C, bool isClipped, int lowerbound, int 
upperbound, const char* scale_file, const char* offset_file) : 
MWCNNLayerImpl(layer, ntwk_impl) , intermediateOp(NULL) , 
omxlPZbBePZdWaJOBUUG(scale_H) , puSFZkRJmyuFPfQRswDK(scale_W) , 
olKGEIcsxmLSoMhRhEtP(scale_C) , gzSTokDHvkXefhiGDcWL(offset_H) , 
hljcfGWsvZXJZNrImpJB(offset_W) , gTcJMwtYuwiqqUmqvKhT(offset_C) , 
aLsOwwcceEmRSYzllBNs(isClipped) , enPbWLzEmxYCBmzGJutZ(lowerbound) , 
vFNECEAeLZsYsUxvlgqL(upperbound) { long int pckLLTEdVPoCZLRwyDnM = (long 
int)(omxlPZbBePZdWaJOBUUG * puSFZkRJmyuFPfQRswDK * olKGEIcsxmLSoMhRhEtP); long int 
hDaNSVZAofAENeIAiWEw = (long int)(gzSTokDHvkXefhiGDcWL * hljcfGWsvZXJZNrImpJB * 
gTcJMwtYuwiqqUmqvKhT); oYbqYsqgVhrUzFEKbBbR = (float*)calloc(pckLLTEdVPoCZLRwyDnM, 
sizeof(float)); fxxCPKTclxXPxrdMAkwi = (float*)calloc(hDaNSVZAofAENeIAiWEw, 
sizeof(float)); loadScale(scale_file); loadOffset(offset_file); } 
MWElementwiseAffineLayerImpl::~MWElementwiseAffineLayerImpl() { } void 
MWElementwiseAffineLayerImpl::createScalarAffine() { long int 
pckLLTEdVPoCZLRwyDnM = (long int)(omxlPZbBePZdWaJOBUUG * puSFZkRJmyuFPfQRswDK * 
olKGEIcsxmLSoMhRhEtP); long int hDaNSVZAofAENeIAiWEw = (long 
int)(gzSTokDHvkXefhiGDcWL * hljcfGWsvZXJZNrImpJB * gTcJMwtYuwiqqUmqvKhT); 
std::shared_ptr<mkldnn::memory> srcLayerMemory = getReorderLayerMemory(); 
std::shared_ptr<mkldnn::memory> dstLayerMemory = getLayerMemory(); float 
temp_offset = *fxxCPKTclxXPxrdMAkwi; float temp_scale = *oYbqYsqgVhrUzFEKbBbR; if 
(pckLLTEdVPoCZLRwyDnM == 1 && hDaNSVZAofAENeIAiWEw != 1) { dstLayerMemory = 
intermediateOutput; temp_offset = 0.0f; } else if ((pckLLTEdVPoCZLRwyDnM != 1 && 
hDaNSVZAofAENeIAiWEw == 1)) { srcLayerMemory = intermediateOutput; temp_scale = 
1.0f; } if ((pckLLTEdVPoCZLRwyDnM == 1 && hDaNSVZAofAENeIAiWEw == 1) || 
(pckLLTEdVPoCZLRwyDnM == 1 && hDaNSVZAofAENeIAiWEw != 1) || (pckLLTEdVPoCZLRwyDnM != 
1 && hDaNSVZAofAENeIAiWEw == 1)) { scaling_d = 
std::unique_ptr<mkldnn::eltwise_forward::desc>(new 
mkldnn::eltwise_forward::desc( mkldnn::prop_kind::forward_inference, 
mkldnn::algorithm::eltwise_linear, getReorderLayerMemory()->get_desc(), 
temp_scale, temp_offset)); scaling_pd = 
std::unique_ptr<mkldnn::eltwise_forward::primitive_desc>( new 
mkldnn::eltwise_forward::primitive_desc(*scaling_d, 
*euppfEoiaoCTcVgRPVhA->eng)); scaling = 
std::unique_ptr<mkldnn::eltwise_forward>(new 
mkldnn::eltwise_forward(*scaling_pd)); pipeline_memory_args.push_back( 
{{MKLDNN_ARG_FROM, *srcLayerMemory}, {MKLDNN_ARG_TO, *dstLayerMemory}}); 
pipeline.push_back(*scaling); } } void 
MWElementwiseAffineLayerImpl::createVectorAffine() { long int 
pckLLTEdVPoCZLRwyDnM = (long int)(omxlPZbBePZdWaJOBUUG * puSFZkRJmyuFPfQRswDK * 
olKGEIcsxmLSoMhRhEtP); long int hDaNSVZAofAENeIAiWEw = (long 
int)(gzSTokDHvkXefhiGDcWL * hljcfGWsvZXJZNrImpJB * gTcJMwtYuwiqqUmqvKhT); bool 
offsetVectorImpl = (gzSTokDHvkXefhiGDcWL == 1 && hljcfGWsvZXJZNrImpJB == 1 && 
hDaNSVZAofAENeIAiWEw > 1); bool scaleVectorImpl = (omxlPZbBePZdWaJOBUUG == 1 && 
puSFZkRJmyuFPfQRswDK == 1 && pckLLTEdVPoCZLRwyDnM > 1); 
std::shared_ptr<mkldnn::memory> srcLayerMemory1 = getReorderLayerMemory(); 
std::shared_ptr<mkldnn::memory> dstLayerMemory1 = getLayerMemory(); if 
(scaleVectorImpl && !offsetVectorImpl) { dstLayerMemory1 = intermediateOutput; 
} else if (!scaleVectorImpl && offsetVectorImpl) { srcLayerMemory1 = 
intermediateOutput; } } void MWElementwiseAffineLayerImpl::propagateSize() { 
MWTensor* ipTensor = getLayer()->getInputTensor(0); auto prevMemoryDesc = 
MWMkldnnUtils::getLayerMemoryPrimitive(ipTensor, 
euppfEoiaoCTcVgRPVhA)->get_desc(); format_type formatTag = 
MWMkldnnUtils::getformatType(prevMemoryDesc, ipTensor); if ((formatTag != 
format_type::NC_FORMAT) && (formatTag != format_type::NCHW_FORMAT)){ 
MWMkldnnUtils::configureReorder(this, ipTensor, 
mkldnn::memory::format_tag::nchw); pipeline.push_back(*getReorderPrim()); 
pipeline_memory_args.push_back({{MKLDNN_ARG_FROM, 
*MWMkldnnUtils::getLayerMemoryPrimitive( ipTensor, euppfEoiaoCTcVgRPVhA)}, 
{MKLDNN_ARG_TO, *getReorderLayerMemory()}}); } else { setReorderLayerMemory( 
MWMkldnnUtils::getLayerMemoryPrimitive(ipTensor, euppfEoiaoCTcVgRPVhA)); } int 
eqOmMKQRpqBqRQCnJmxt = getLayer()->getInputTensor(0)->getBatchSize(); int QwUuNuQNtlPXrIwRNiSZ 
= getLayer()->getInputTensor(0)->getChannels(); int TxNFOfYScyqGlEFFxbAv = 
getLayer()->getInputTensor(0)->getHeight(); int vIWQzNvYZSuxmOTVDFhU = 
getLayer()->getInputTensor(0)->getWidth(); intermediateOp = 
(float*)calloc(eqOmMKQRpqBqRQCnJmxt * QwUuNuQNtlPXrIwRNiSZ * TxNFOfYScyqGlEFFxbAv * vIWQzNvYZSuxmOTVDFhU, 
sizeof(float)); intermediateOutput = std::make_shared<mkldnn::memory>( 
getReorderLayerMemory()->get_desc(), *euppfEoiaoCTcVgRPVhA->eng, 
intermediateOp); 
setLayerMemory(std::make_shared<mkldnn::memory>(getReorderLayerMemory()->get_desc(), 
*euppfEoiaoCTcVgRPVhA->eng)); createScalarAffine(); createVectorAffine(); } void 
MWElementwiseAffineLayerImpl::predict() { long int pckLLTEdVPoCZLRwyDnM = (long 
int)(omxlPZbBePZdWaJOBUUG * puSFZkRJmyuFPfQRswDK * olKGEIcsxmLSoMhRhEtP); long int 
hDaNSVZAofAENeIAiWEw = (long int)(gzSTokDHvkXefhiGDcWL * hljcfGWsvZXJZNrImpJB * 
gTcJMwtYuwiqqUmqvKhT); MWTensor* opTensor = getLayer()->getOutputTensor(0); if 
(pckLLTEdVPoCZLRwyDnM == 1 && hDaNSVZAofAENeIAiWEw == 1) { auto s = 
mkldnn::stream(*euppfEoiaoCTcVgRPVhA->eng); assert(pipeline.size() == 
pipeline_memory_args.size()); for (int i = 0; i < pipeline.size(); i++) { 
pipeline[i].execute(s, pipeline_memory_args[i]); } clipAffineOutput(); return; 
} MWTensor* ipTensor = getLayer()->getInputTensor(0); float* ipData = 
(float*)getReorderLayerMemory()->get_data_handle(); float* opData = 
intermediateOp; long int ZCArwzdUdwQuFQUWjnUE = ipTensor->getHeight() 
* ipTensor->getWidth(); long int YgcpEBUCwCLaPhyntIio = 
ZCArwzdUdwQuFQUWjnUE * ipTensor->getChannels(); if 
(pckLLTEdVPoCZLRwyDnM == 1) { auto s = mkldnn::stream(*euppfEoiaoCTcVgRPVhA->eng); 
assert(pipeline.size() == pipeline_memory_args.size()); for (int i = 0; i < 
pipeline.size(); i++) { pipeline[i].execute(s, pipeline_memory_args[i]); } } 
else if (omxlPZbBePZdWaJOBUUG == 1 && puSFZkRJmyuFPfQRswDK == 1 && 
pckLLTEdVPoCZLRwyDnM > 1) { for (int n = 0; n < ipTensor->getBatchSize(); n++) { 
for (int c = 0; c < ipTensor->getChannels(); c++) { for (int wh = 0; wh < 
ZCArwzdUdwQuFQUWjnUE; wh++) { *opData++ = *ipData++ * 
oYbqYsqgVhrUzFEKbBbR[c]; } } } } else if (ZCArwzdUdwQuFQUWjnUE == 
pckLLTEdVPoCZLRwyDnM) { for (int n = 0; n < ipTensor->getBatchSize(); n++) { for 
(int c = 0; c < ipTensor->getChannels(); c++) { for (int i = 0; i < 
ZCArwzdUdwQuFQUWjnUE; ++i) { opData[i + c * 
ZCArwzdUdwQuFQUWjnUE] = ipData[i + c * 
ZCArwzdUdwQuFQUWjnUE] * oYbqYsqgVhrUzFEKbBbR[i]; } } ipData += 
YgcpEBUCwCLaPhyntIio; opData += YgcpEBUCwCLaPhyntIio; } } else 
{ for (int n = 0; n < ipTensor->getBatchSize(); n++) { for (int i = 0; i < 
YgcpEBUCwCLaPhyntIio; ++i) { opData[i] = ipData[i] * 
oYbqYsqgVhrUzFEKbBbR[i]; } ipData += YgcpEBUCwCLaPhyntIio; opData += 
YgcpEBUCwCLaPhyntIio; } } ipData = intermediateOp; opData = 
opTensor->getData<float>(); if (hDaNSVZAofAENeIAiWEw == 1) { auto s = 
mkldnn::stream(*euppfEoiaoCTcVgRPVhA->eng); assert(pipeline.size() == 
pipeline_memory_args.size()); for (int i = 0; i < pipeline.size(); i++) { 
pipeline[i].execute(s, pipeline_memory_args[i]); } } else if 
(gzSTokDHvkXefhiGDcWL == 1 && hljcfGWsvZXJZNrImpJB == 1 && hDaNSVZAofAENeIAiWEw > 
1) { for (int n = 0; n < ipTensor->getBatchSize(); n++) { for (int c = 0; c < 
ipTensor->getChannels(); c++) { for (int wh = 0; wh < 
ZCArwzdUdwQuFQUWjnUE; wh++) { *opData++ = *ipData++ + 
fxxCPKTclxXPxrdMAkwi[c]; } } } } else if (ZCArwzdUdwQuFQUWjnUE == 
hDaNSVZAofAENeIAiWEw) { for (int n = 0; n < ipTensor->getBatchSize(); n++) { for 
(int c = 0; c < ipTensor->getChannels(); c++) { for (int i = 0; i < 
ZCArwzdUdwQuFQUWjnUE; ++i) { opData[i + c * 
ZCArwzdUdwQuFQUWjnUE] = ipData[i + c * 
ZCArwzdUdwQuFQUWjnUE] + fxxCPKTclxXPxrdMAkwi[i]; } } ipData += 
YgcpEBUCwCLaPhyntIio; opData += YgcpEBUCwCLaPhyntIio; } } else 
{ for (int n = 0; n < ipTensor->getBatchSize(); n++) { for (int i = 0; i < 
YgcpEBUCwCLaPhyntIio; ++i) { opData[i] = ipData[i] + 
fxxCPKTclxXPxrdMAkwi[i]; } ipData += YgcpEBUCwCLaPhyntIio; opData += 
YgcpEBUCwCLaPhyntIio; } } clipAffineOutput();
#if MW_AFFINE_TAP
 mw_interm_tap(opData, YgcpEBUCwCLaPhyntIio, tap_count++);
#endif
 return; } void MWElementwiseAffineLayerImpl::clipAffineOutput() { MWTensor* 
opTensor = getLayer()->getOutputTensor(0); float* outputBuffer = 
opTensor->getData<float>(); if (!aLsOwwcceEmRSYzllBNs) { return; } for (int n = 
0; n < opTensor->getNumElements(); n++) { outputBuffer[n] = outputBuffer[n] > 
vFNECEAeLZsYsUxvlgqL ? vFNECEAeLZsYsUxvlgqL : outputBuffer[n]; 
outputBuffer[n] = outputBuffer[n] < enPbWLzEmxYCBmzGJutZ ? 
enPbWLzEmxYCBmzGJutZ : outputBuffer[n]; } } void 
MWElementwiseAffineLayerImpl::cleanup() { if (oYbqYsqgVhrUzFEKbBbR) { 
free(oYbqYsqgVhrUzFEKbBbR); oYbqYsqgVhrUzFEKbBbR = NULL; } if (fxxCPKTclxXPxrdMAkwi) { 
free(fxxCPKTclxXPxrdMAkwi); fxxCPKTclxXPxrdMAkwi = NULL; } } void 
MWElementwiseAffineLayerImpl::deallocate() { if (intermediateOp) { 
free(intermediateOp); intermediateOp = NULL; } } void 
MWElementwiseAffineLayerImpl::loadScale(const char* qWwjVYwfnvEnFKlgpqwA) { 
FILE* SGsAudmgjmvcUXzzrUtf = MWCNNLayer::openBinaryFile(qWwjVYwfnvEnFKlgpqwA); 
assert(SGsAudmgjmvcUXzzrUtf); long int eybNKlJCSDUvsznWynwK = (long int)(omxlPZbBePZdWaJOBUUG 
* puSFZkRJmyuFPfQRswDK * olKGEIcsxmLSoMhRhEtP); call_fread(oYbqYsqgVhrUzFEKbBbR, 
sizeof(float), eybNKlJCSDUvsznWynwK, SGsAudmgjmvcUXzzrUtf, qWwjVYwfnvEnFKlgpqwA); 
fclose(SGsAudmgjmvcUXzzrUtf); } void MWElementwiseAffineLayerImpl::loadOffset(const 
char* hnewnpwgzKmOdualajhn) { FILE* SGsAudmgjmvcUXzzrUtf = 
MWCNNLayer::openBinaryFile(hnewnpwgzKmOdualajhn); assert(SGsAudmgjmvcUXzzrUtf); long 
int eybNKlJCSDUvsznWynwK = (long int)(gzSTokDHvkXefhiGDcWL * hljcfGWsvZXJZNrImpJB * 
gTcJMwtYuwiqqUmqvKhT); call_fread(fxxCPKTclxXPxrdMAkwi, sizeof(float), 
eybNKlJCSDUvsznWynwK, SGsAudmgjmvcUXzzrUtf, hnewnpwgzKmOdualajhn); fclose(SGsAudmgjmvcUXzzrUtf); }