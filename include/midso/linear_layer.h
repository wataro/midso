/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#ifndef INCLUDE_MIDSO_LINEAR_LAYER_H_
#define INCLUDE_MIDSO_LINEAR_LAYER_H_
#include "midso/common.h"
#include "midso/layer_interface.h"

namespace midso {

class LinearLayer : LayerInterface {
 public:
    LinearLayer() {}
    ~LinearLayer() {}
     LinearLayer(const Float & multiplier = 1.0,
        const Float & accumulator = 0.0);
    virtual void propagate(const Tensor & input_node);
    virtual LayerInterface & backward_layer();
    virtual const Tensor & output_node() const;

 private:
    DISALLOW_COPY_AND_ASSIGN(LinearLayer);
};

}  // namespace midso

#endif  // INCLUDE_MIDSO_LINEAR_LAYER_H_
