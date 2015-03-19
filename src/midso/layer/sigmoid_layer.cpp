/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "midso/layer/sigmoid_layer.h"

namespace midso {

SigmoidLayer * SigmoidLayer::load(const KeyValue & config) {
}

void SigmoidLayer::init(const Tensor & input_node) {
}

void SigmoidLayer::set_input(const Tensor & input_node) {
}

void SigmoidLayer::propagate() {
}

BackwardLayerInterface & SigmoidLayer::backward_layer() {
}

const Tensor & SigmoidLayer::output_node() const {
}

}  // namespace midso
