/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "midso/layer/relu_layer.h"

namespace midso {

static ReluLayer * ReluLayer::load(const Yaml & config) {
}

void ReluLayer::init(const Tensor & input_node) {
}

void ReluLayer::set_input(const Tensor & input_node) {
}

void ReluLayer::propagate() {
}

LayerInterface & ReluLayer::backward_layer() {
}

const Tensor & ReluLayer::output_node() const {
}

}  // namespace midso
