/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "midso/layer/linear_layer.h"

namespace midso {

LinearLayer::LinearLayer(const Float & mul,
        const Float & add) {
}

LinearLayer * LinearLayer::load(const KeyValueTree & config) {
}

void LinearLayer::init(const Tensor & in_tensor) {
}

void LinearLayer::set_input(const Tensor & in_tensor) {
}

void LinearLayer::propagate() {
}

BackwardLayerInterface & LinearLayer::backward_layer() {
}

const Tensor & LinearLayer::get_output() const {
}

}  // namespace midso
