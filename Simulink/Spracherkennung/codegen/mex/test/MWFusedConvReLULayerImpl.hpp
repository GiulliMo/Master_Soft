/* Copyright 2018-2019 The MathWorks, Inc. */

#ifndef __FUSED_CONV_RELU_LAYER_IMPL_HPP
#define __FUSED_CONV_RELU_LAYER_IMPL_HPP

#include "MWCNNLayerImpl.hpp"
#include "MWTargetNetworkImpl.hpp"
#include "MWMkldnnUtils.hpp"

class MWTensor;
class MWCNNLayer;
class MWTargetNetworkImpl;

class MWFusedConvReLULayerImpl : public MWCNNLayerImpl {
  private:
    float* vIWQzNvYZSuxmOTVDFhU;
    float* PmFfARVzoHVAYkfpuvqK;
    int AwZQzUhuWVLGrWgLHRuM; // Filter height for CONV and FC
    int AzTsxYcYjIEJsGQbeYHm;  // Filter width for CONV and FC
    int CZNYmBcNFSZWvaCklqeM;
    int BRSPqxNffoBYKqpSVHne;
    int CGbFsczkgkhjcHoCKzBx;

    int JwxFdqOKggeawILBfGgg;
    int KCudOrFMfgCzUPMcdePX;
    int ECTnqgWHyHCHCLBZlffd;
    int DqxLTLaJwwgQqmrtCDuu;
    int GnxRkpzrPZimKtYYHSuG;
    int GsZlHFuhbvjLtRMDjXnW;
    int AIXLuRgdeiqpaCehGSYD;
    int ATEikvMQPqBefhJzjzhc;
    bool with_bias = true;

  public:
    MWFusedConvReLULayerImpl(MWCNNLayer*,
                             MWTargetNetworkImpl*,
                             int,
                             int,
                             int,
                             int,
                             int,
                             int,
                             int,
                             int,
                             int,
                             int,
                             int,
                             int,
                             int,
                             int,
                             const char*,
                             const char*);
    ~MWFusedConvReLULayerImpl();


    void predict();
    void propagateSize();
    void cleanup();
    void allocateOutputData(int);

  private:
    void loadWeights(const char*, int);
    void loadBias(const char*, int);

    // ConvLayer related config params
    std::shared_ptr<mkldnn::memory> weights;
    std::shared_ptr<mkldnn::memory> bias;

	mkldnn::memory::desc reorderedWeightsDesc;
	std::shared_ptr<mkldnn::memory> additionMemPrimitive;
	std::unique_ptr<mkldnn::reorder> addition_reorder; //to handle the reorder

    std::unique_ptr<mkldnn::memory::desc> conv_src_md;
    std::unique_ptr<mkldnn::memory::desc> conv_weights_md;
    std::unique_ptr<mkldnn::memory::desc> conv_bias_md;
    std::unique_ptr<mkldnn::memory::desc> conv_dst_md;

    /*reorder related settings*/

    std::shared_ptr<mkldnn::memory> conv_src_memory;
    std::shared_ptr<mkldnn::memory> conv_weights_memory;

    std::unique_ptr<mkldnn::reorder> conv_reorder_src;
    std::unique_ptr<mkldnn::reorder> conv_reorder_weights;

    std::unique_ptr<mkldnn::convolution_forward::desc> conv_d;
    std::unique_ptr<mkldnn::convolution_forward::primitive_desc> conv_pd;
    std::unique_ptr<mkldnn::convolution_forward::primitive> conv;
    
    bool reorderAdditionIpData;

};

#endif
