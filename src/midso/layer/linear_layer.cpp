/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "midso/layer/linear_layer.h"

namespace midso {

LinearLayer::LinearLayer(const Float & multiplier,
        const Float & accumulator) {
}

static LinearLayer * LinearLayer::load(const Yaml & config) {
}

void LinearLayer::propagate(const Tensor & input_node) {
}

LayerInterface & LinearLayer::backward_layer() {
}

const Tensor & LinearLayer::output_node() const {
}

}  // namespace midso
