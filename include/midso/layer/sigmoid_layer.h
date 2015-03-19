/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#ifndef INCLUDE_MIDSO_LAYER_SIGMOID_LAYER_H_
#define INCLUDE_MIDSO_LAYER_SIGMOID_LAYER_H_
#include "midso/common.h"
#include "midso/layer/layer_interface.h"

namespace midso {

class SigmoidLayer : public LayerInterface {
 public:
    SigmoidLayer() {}
    ~SigmoidLayer() {}
    static SigmoidLayer * load(const KeyValue & config);
    void init(const Tensor & input_node);
    void set_input(const Tensor & input_node);
    void propagate();
    BackwardLayerInterface & backward_layer();
    const Tensor & output_node() const;

 private:
    DISALLOW_COPY_AND_ASSIGN(SigmoidLayer);
};

}  // namespace midso

#endif  // INCLUDE_MIDSO_LAYER_SIGMOID_LAYER_H_
