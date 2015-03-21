/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "midso/layer/sigmoid_layer.h"

namespace midso {

SigmoidLayer * SigmoidLayer::load(const KeyValueTree & config) {
}

void SigmoidLayer::init(const Tensor & in_tensor) {
}

void SigmoidLayer::set_input(const Tensor & in_tensor) {
}

void SigmoidLayer::propagate() {
}

BackwardLayerInterface & SigmoidLayer::backward_layer() {
}

const Tensor & SigmoidLayer::get_output() const {
}

}  // namespace midso
