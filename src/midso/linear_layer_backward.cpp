/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "midso/linear_layer_backward.h"

namespace midso {

LinearLayerBackward::LinearLayerBackward(const Float & multiplier,
        const Float & accumulator) {
}

void LinearLayerBackward::propagate(const Tensor & input_node) {
}

const Tensor & LinearLayerBackward::output_node() const {
}

}  // namespace midso
