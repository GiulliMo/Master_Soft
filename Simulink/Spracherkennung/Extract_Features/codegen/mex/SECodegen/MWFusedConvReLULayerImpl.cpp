#include "MWFusedConvReLULayer.hpp"
#include "MWFusedConvReLULayerImpl.hpp"
#include <cassert>
#include "MWCNNLayerImpl.hpp"
#include "MWTargetNetworkImpl.hpp"
#include "MWMkldnnUtils.hpp"
#include "cnn_api.hpp"
#if MW_CONV_TAP
 extern int tap_count; extern void mw_interm_tap(float* inp, int size, int count);
#endif
 MWFusedConvReLULayerImpl::MWFusedConvReLULayerImpl(MWCNNLayer* layer, 
MWTargetNetworkImpl* ntwk_impl, int filt_H, int filt_W, int numGrps, int 
numChnls, int numFilts, int JwxFdqOKggeawILBfGgg, int KCudOrFMfgCzUPMcdePX, int 
ECTnqgWHyHCHCLBZlffd, int DqxLTLaJwwgQqmrtCDuu, int GnxRkpzrPZimKtYYHSuG, 
int GsZlHFuhbvjLtRMDjXnW, int AIXLuRgdeiqpaCehGSYD, int 
ATEikvMQPqBefhJzjzhc, int , const char* xHViLEwTujGGrPZZgmbF, const 
char* QVgVGfoCXYiYXzPhvVPX) : MWCNNLayerImpl(layer, ntwk_impl) , 
AwZQzUhuWVLGrWgLHRuM(filt_H) , AzTsxYcYjIEJsGQbeYHm(filt_W) , 
CZNYmBcNFSZWvaCklqeM(numGrps) , JwxFdqOKggeawILBfGgg(JwxFdqOKggeawILBfGgg) , 
KCudOrFMfgCzUPMcdePX(KCudOrFMfgCzUPMcdePX) , 
ECTnqgWHyHCHCLBZlffd(ECTnqgWHyHCHCLBZlffd) , 
DqxLTLaJwwgQqmrtCDuu(DqxLTLaJwwgQqmrtCDuu) , 
GnxRkpzrPZimKtYYHSuG(GnxRkpzrPZimKtYYHSuG) , 
GsZlHFuhbvjLtRMDjXnW(GsZlHFuhbvjLtRMDjXnW) , 
AIXLuRgdeiqpaCehGSYD(AIXLuRgdeiqpaCehGSYD) , 
ATEikvMQPqBefhJzjzhc(ATEikvMQPqBefhJzjzhc) { int eybNKlJCSDUvsznWynwK = 
numChnls * numFilts * CZNYmBcNFSZWvaCklqeM * AwZQzUhuWVLGrWgLHRuM * 
AzTsxYcYjIEJsGQbeYHm; vIWQzNvYZSuxmOTVDFhU = (float*)calloc(eybNKlJCSDUvsznWynwK, 
sizeof(float)); PmFfARVzoHVAYkfpuvqK = (float*)calloc(numFilts * CZNYmBcNFSZWvaCklqeM, 
sizeof(float)); loadWeights(xHViLEwTujGGrPZZgmbF, eybNKlJCSDUvsznWynwK); 
loadBias(QVgVGfoCXYiYXzPhvVPX, numFilts * CZNYmBcNFSZWvaCklqeM); auto 
weights_md = CZNYmBcNFSZWvaCklqeM > 1 ? 
mkldnn::memory::desc({{CZNYmBcNFSZWvaCklqeM, numFilts, numChnls, 
AwZQzUhuWVLGrWgLHRuM, AzTsxYcYjIEJsGQbeYHm}, 
mkldnn::memory::data_type::f32, mkldnn::memory::format_tag::goihw}) : 
mkldnn::memory::desc({{numFilts, numChnls, AwZQzUhuWVLGrWgLHRuM, 
AzTsxYcYjIEJsGQbeYHm}, mkldnn::memory::data_type::f32, 
mkldnn::memory::format_tag::oihw}); weights = std::shared_ptr<mkldnn::memory>( 
new mkldnn::memory(weights_md, *euppfEoiaoCTcVgRPVhA->eng, vIWQzNvYZSuxmOTVDFhU)); auto 
bias_md = with_bias ? mkldnn::memory::desc({{numFilts * CZNYmBcNFSZWvaCklqeM}, 
mkldnn::memory::data_type::f32, mkldnn::memory::format_tag::x}) : 
mkldnn::memory::desc( {{}, mkldnn::memory::data_type::f32, 
mkldnn::memory::format_tag::x}); bias = with_bias ? 
std::shared_ptr<mkldnn::memory>( new mkldnn::memory(bias_md, 
*euppfEoiaoCTcVgRPVhA->eng, PmFfARVzoHVAYkfpuvqK)) : std::shared_ptr<mkldnn::memory>( 
new mkldnn::memory(bias_md, *euppfEoiaoCTcVgRPVhA->eng)); conv_bias_md = 
std::unique_ptr<mkldnn::memory::desc>( new mkldnn::memory::desc({numFilts * 
CZNYmBcNFSZWvaCklqeM}, mkldnn::memory::data_type::f32, 
mkldnn::memory::format_tag::any)); conv_weights_md = CZNYmBcNFSZWvaCklqeM > 1 ? 
std::unique_ptr<mkldnn::memory::desc>(new mkldnn::memory::desc( 
{CZNYmBcNFSZWvaCklqeM, numFilts, numChnls, AwZQzUhuWVLGrWgLHRuM, 
AzTsxYcYjIEJsGQbeYHm}, mkldnn::memory::data_type::f32, 
mkldnn::memory::format_tag::any)) : std::unique_ptr<mkldnn::memory::desc>(new 
mkldnn::memory::desc( {numFilts, numChnls, AwZQzUhuWVLGrWgLHRuM, 
AzTsxYcYjIEJsGQbeYHm}, mkldnn::memory::data_type::f32, 
mkldnn::memory::format_tag::any)); reorderedWeightsDesc = weights->get_desc(); 
} void MWFusedConvReLULayerImpl::propagateSize() { MWFusedConvReLULayer* 
convLayer = static_cast<MWFusedConvReLULayer*>(getLayer()); MWTensor* ipTensor 
= convLayer->getInputTensor(0); MWTensor* opTensor = 
convLayer->getOutputTensor(0); reorderAdditionIpData = false; int numInputs = 
(int)getLayer()->getNumInputs(); int n = ipTensor->getBatchSize(); int c = 
ipTensor->getChannels(); int h = ipTensor->getHeight(); int w = 
ipTensor->getWidth(); int num_filts = opTensor->getChannels(); 
mkldnn::primitive_attr attr; mkldnn::post_ops ops; float scale = 1.0f; float 
alpha = 0.0f; float beta = 1.0f;  if (numInputs == 2) { ops.append_sum(1.0f); } 
ops.append_eltwise(scale, mkldnn::algorithm::eltwise_relu, alpha, beta); 
attr.set_post_ops(ops); conv_src_md = std::unique_ptr<mkldnn::memory::desc>(new 
mkldnn::memory::desc( {n, c, h, w}, mkldnn::memory::data_type::f32, 
mkldnn::memory::format_tag::any)); conv_dst_md = 
std::unique_ptr<mkldnn::memory::desc>( new mkldnn::memory::desc({n, num_filts, 
opTensor->getHeight(), opTensor->getWidth()}, mkldnn::memory::data_type::f32, 
mkldnn::memory::format_tag::any)); conv_d = with_bias ? 
std::unique_ptr<mkldnn::convolution_forward::desc>( new 
mkldnn::convolution_forward::desc( mkldnn::prop_kind::forward_inference, 
mkldnn::algorithm::convolution_direct, *conv_src_md, *conv_weights_md, 
*conv_bias_md, *conv_dst_md, {JwxFdqOKggeawILBfGgg, KCudOrFMfgCzUPMcdePX}, 
{AIXLuRgdeiqpaCehGSYD - 1, ATEikvMQPqBefhJzjzhc - 1}, 
{ECTnqgWHyHCHCLBZlffd, GnxRkpzrPZimKtYYHSuG}, {DqxLTLaJwwgQqmrtCDuu, 
GsZlHFuhbvjLtRMDjXnW})) : std::unique_ptr<mkldnn::convolution_forward::desc>( 
new mkldnn::convolution_forward::desc( mkldnn::prop_kind::forward_inference, 
mkldnn::algorithm::convolution_direct, *conv_src_md, *conv_weights_md, 
*conv_dst_md, {JwxFdqOKggeawILBfGgg, KCudOrFMfgCzUPMcdePX}, 
{AIXLuRgdeiqpaCehGSYD - 1, ATEikvMQPqBefhJzjzhc - 1}, 
{ECTnqgWHyHCHCLBZlffd, GnxRkpzrPZimKtYYHSuG}, {DqxLTLaJwwgQqmrtCDuu, 
GsZlHFuhbvjLtRMDjXnW})); conv_pd = 
std::unique_ptr<mkldnn::convolution_forward::primitive_desc>( new 
mkldnn::convolution_forward::primitive_desc(*conv_d, attr, 
*euppfEoiaoCTcVgRPVhA->eng)); conv_src_memory = 
MWMkldnnUtils::getLayerMemoryPrimitive(ipTensor, euppfEoiaoCTcVgRPVhA); if 
(mkldnn::memory::desc(conv_pd->src_desc()) != 
MWMkldnnUtils::getLayerMemoryPrimitive(ipTensor, 
euppfEoiaoCTcVgRPVhA)->get_desc()) { conv_src_memory = 
std::make_shared<mkldnn::memory>(conv_pd->src_desc(), 
*euppfEoiaoCTcVgRPVhA->eng); conv_reorder_src = 
std::unique_ptr<mkldnn::reorder>(new mkldnn::reorder( 
*MWMkldnnUtils::getLayerMemoryPrimitive(ipTensor, euppfEoiaoCTcVgRPVhA), 
*conv_src_memory)); pipeline_memory_args.push_back({{MKLDNN_ARG_FROM, 
*MWMkldnnUtils::getLayerMemoryPrimitive( ipTensor, euppfEoiaoCTcVgRPVhA)}, 
{MKLDNN_ARG_TO, *conv_src_memory}}); pipeline.push_back(*conv_reorder_src); } 
conv_weights_memory = weights; if 
(mkldnn::memory::desc(conv_pd->weights_desc()) != weights->get_desc()) { if 
(conv_pd->weights_desc() != reorderedWeightsDesc) { conv_weights_memory = 
std::make_shared<mkldnn::memory>(conv_pd->weights_desc(), 
*euppfEoiaoCTcVgRPVhA->eng); conv_reorder_weights = 
std::unique_ptr<mkldnn::reorder>( new mkldnn::reorder(*weights, 
*conv_weights_memory)); pipeline_weights_memory_args.push_back( 
{{MKLDNN_ARG_FROM, *weights}, {MKLDNN_ARG_TO, *conv_weights_memory}}); 
pipeline_weights.push_back(*conv_reorder_weights); auto s = 
mkldnn::stream(*euppfEoiaoCTcVgRPVhA->eng); assert(pipeline_weights.size() == 
pipeline_weights_memory_args.size()); for (int i = 0; i < 
pipeline_weights.size(); i++) { pipeline_weights[i].execute(s, 
pipeline_weights_memory_args[i]); } } } setLayerMemory( 
std::make_shared<mkldnn::memory>(conv_pd->dst_desc(), 
*euppfEoiaoCTcVgRPVhA->eng)); conv = 
std::unique_ptr<mkldnn::convolution_forward>(new 
mkldnn::convolution_forward(*conv_pd)); if (numInputs == 2) { MWTensor* 
additionIpTensor = getLayer()->getInputTensor(1); additionMemPrimitive = 
MWMkldnnUtils::getLayerMemoryPrimitive(additionIpTensor, euppfEoiaoCTcVgRPVhA); 
if (MWMkldnnUtils::getLayerMemoryPrimitive(additionIpTensor, 
euppfEoiaoCTcVgRPVhA) ->get_desc() != conv_pd->dst_desc()) { 
additionMemPrimitive = std::make_shared<mkldnn::memory>(conv_pd->dst_desc(), 
*euppfEoiaoCTcVgRPVhA->eng); addition_reorder = 
std::unique_ptr<mkldnn::reorder>(new mkldnn::reorder( 
*MWMkldnnUtils::getLayerMemoryPrimitive(additionIpTensor, euppfEoiaoCTcVgRPVhA), 
*additionMemPrimitive)); reorderAdditionIpData = true; 
pipeline_memory_args.push_back( {{MKLDNN_ARG_FROM, 
*MWMkldnnUtils::getLayerMemoryPrimitive(additionIpTensor, 
euppfEoiaoCTcVgRPVhA)}, {MKLDNN_ARG_TO, *additionMemPrimitive}}); 
pipeline.push_back(*addition_reorder); } } if (with_bias) { 
pipeline_memory_args.push_back({{MKLDNN_ARG_SRC, *conv_src_memory}, 
{MKLDNN_ARG_WEIGHTS, *conv_weights_memory}, {MKLDNN_ARG_BIAS, *bias}, 
{MKLDNN_ARG_DST, *getLayerMemory()}}); } else { 
pipeline_memory_args.push_back({{MKLDNN_ARG_SRC, *conv_src_memory}, 
{MKLDNN_ARG_WEIGHTS, *conv_weights_memory}, {MKLDNN_ARG_DST, 
*getLayerMemory()}}); } pipeline.push_back(*conv); return; } void 
MWFusedConvReLULayerImpl::allocateOutputData(int i) { int numInputs = 
(int)getLayer()->getNumInputs(); MWTensor* opTensor = 
getLayer()->getOutputTensor(i); if (reorderAdditionIpData) { 
opTensor->setData((float*)additionMemPrimitive->get_data_handle()); 
MWMkldnnUtils::getLayerMemoryPrimitive(opTensor, euppfEoiaoCTcVgRPVhA) 
->set_data_handle(opTensor->getData<float>()); } else if 
(opTensor->getopBufIndex() < 0 && numInputs == 2) { MWTensor* ipTensor = 
getLayer()->getInputTensor(1); opTensor->setData(ipTensor->getData<float>()); 
MWMkldnnUtils::getLayerMemoryPrimitive(opTensor, euppfEoiaoCTcVgRPVhA) 
->set_data_handle(opTensor->getData<float>()); } else { 
MWCNNLayerImpl::allocateOutputData(i); } } void 
MWFusedConvReLULayerImpl::predict() { auto s = 
mkldnn::stream(*euppfEoiaoCTcVgRPVhA->eng); assert(pipeline.size() == 
pipeline_memory_args.size()); for (int i = 0; i < pipeline.size(); i++) { 
pipeline[i].execute(s, pipeline_memory_args[i]); }
#if MW_CONV_TAP
 reorderedLayerOutputTap(0);
#endif
 return; } MWFusedConvReLULayerImpl::~MWFusedConvReLULayerImpl() { } void 
MWFusedConvReLULayerImpl::cleanup() { if (vIWQzNvYZSuxmOTVDFhU) { free(vIWQzNvYZSuxmOTVDFhU); 
vIWQzNvYZSuxmOTVDFhU = NULL; } if (PmFfARVzoHVAYkfpuvqK) { free(PmFfARVzoHVAYkfpuvqK); PmFfARVzoHVAYkfpuvqK = 
NULL; } } void MWFusedConvReLULayerImpl::loadWeights(const char* 
RqCYCrGsNvzKYrRMXbsI, int eybNKlJCSDUvsznWynwK) { FILE* SGsAudmgjmvcUXzzrUtf = 
MWCNNLayer::openBinaryFile(RqCYCrGsNvzKYrRMXbsI); call_fread(vIWQzNvYZSuxmOTVDFhU, 
sizeof(float), eybNKlJCSDUvsznWynwK, SGsAudmgjmvcUXzzrUtf, RqCYCrGsNvzKYrRMXbsI); 
fclose(SGsAudmgjmvcUXzzrUtf); return; } void MWFusedConvReLULayerImpl::loadBias(const 
char* RqCYCrGsNvzKYrRMXbsI, int eybNKlJCSDUvsznWynwK) { float* PtkeOkuClHzhOfpmBevf = 
PmFfARVzoHVAYkfpuvqK; FILE* SGsAudmgjmvcUXzzrUtf = 
MWCNNLayer::openBinaryFile(RqCYCrGsNvzKYrRMXbsI); call_fread(PtkeOkuClHzhOfpmBevf, 
sizeof(float), eybNKlJCSDUvsznWynwK, SGsAudmgjmvcUXzzrUtf, RqCYCrGsNvzKYrRMXbsI); 
fclose(SGsAudmgjmvcUXzzrUtf); return; }