/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#ifndef INCLUDE_MIDSO_LAYER_BACKWARD_LINEAR_LAYER_BACKWARD_H_
#define INCLUDE_MIDSO_LAYER_BACKWARD_LINEAR_LAYER_BACKWARD_H_
#include "midso/common.h"
#include "midso/backward_layer_interface.h"

namespace midso {

class LinearLayerBackward : BackwardLayerInterface {
 public:
    LinearLayerBackward() {}
    ~LinearLayerBackward() {}
     LinearLayerBackward(const Float & multiplier = 1.0,
        const Float & accumulator = 0.0);
    virtual void propagate(const Tensor & input_node);
    virtual const Tensor & output_node() const;

 private:
    DISALLOW_COPY_AND_ASSIGN(LinearLayerBackward);
};

}  // namespace midso

#endif  // INCLUDE_MIDSO_LAYER_BACKWARD_LINEAR_LAYER_BACKWARD_H_
