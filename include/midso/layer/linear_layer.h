/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#ifndef INCLUDE_MIDSO_LAYER_LINEAR_LAYER_H_
#define INCLUDE_MIDSO_LAYER_LINEAR_LAYER_H_
#include "midso/common.h"
#include "midso/layer/layer_interface.h"

namespace midso {

class LinearLayer : public LayerInterface {
 public:
    LinearLayer() {}
    ~LinearLayer() {}
    LinearLayer(const Float & multiplier = 1.0,
        const Float & accumulator = 0.0);
    static LinearLayer * load(const Yaml & config);
    void propagate(const Tensor & input_node);
    LayerInterface & backward_layer();
    const Tensor & output_node() const;

 private:
    DISALLOW_COPY_AND_ASSIGN(LinearLayer);
};

}  // namespace midso

#endif  // INCLUDE_MIDSO_LAYER_LINEAR_LAYER_H_
