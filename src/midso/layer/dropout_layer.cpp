/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "midso/layer/dropout_layer.h"

namespace midso {

DropoutLayer::DropoutLayer(const Float & drop_rate) {
}

static DropoutLayer * DropoutLayer::load(const Yaml & config) {
}

void DropoutLayer::init(const Tensor & input_node) {
}

void DropoutLayer::set_input(const Tensor & input_node) {
}

void DropoutLayer::propagate() {
}

LayerInterface & DropoutLayer::backward_layer() {
}

const Tensor & DropoutLayer::output_node() const {
}

}  // namespace midso
