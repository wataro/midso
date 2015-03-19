/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "midso/layer/softmax_layer.h"

namespace midso {

static SoftmaxLayer * SoftmaxLayer::load(const KeyValue & config) {
}

void SoftmaxLayer::init(const Tensor & input_node) {
}

void SoftmaxLayer::set_input(const Tensor & input_node) {
}

void SoftmaxLayer::propagate() {
}

BackwardLayerInterface & SoftmaxLayer::backward_layer() {
}

const Tensor & SoftmaxLayer::output_node() const {
}

}  // namespace midso
