/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#ifndef INCLUDE_MIDSO_LAYER_BIAS_LAYER_H_
#define INCLUDE_MIDSO_LAYER_BIAS_LAYER_H_
#include "midso/common.h"
#include "midso/layer/layer_interface.h"
#include "midso/layer/parametric_interface.h"

namespace midso {

class BiasLayer : public LayerInterface, public ParametricInterface {
 public:
    BiasLayer() {}
    ~BiasLayer() {}
    static BiasLayer * load(const Yaml & config);
    void propagate(const Tensor & input_node);
    LayerInterface & backward_layer();
    const Tensor & parameter();
    const Tensor & parameter() const;
    const Tensor & output_node() const;

 private:
    DISALLOW_COPY_AND_ASSIGN(BiasLayer);
};

}  // namespace midso

#endif  // INCLUDE_MIDSO_LAYER_BIAS_LAYER_H_
