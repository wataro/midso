/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "midso/layer/relu_layer.h"

namespace midso {

ReluLayer * ReluLayer::load(const KeyValueTree & config) {
}

void ReluLayer::init(const Tensor & in_tensor) {
}

void ReluLayer::set_input(const Tensor & in_tensor) {
}

void ReluLayer::propagate() {
}

BackwardLayerInterface & ReluLayer::backward_layer() {
}

const Tensor & ReluLayer::get_output() const {
}

}  // namespace midso
