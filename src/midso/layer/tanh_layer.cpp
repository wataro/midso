/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "midso/layer/tanh_layer.h"

namespace midso {

static TanhLayer * TanhLayer::load(const KeyValue & config) {
}

void TanhLayer::init(const Tensor & input_node) {
}

void TanhLayer::set_input(const Tensor & input_node) {
}

void TanhLayer::propagate() {
}

BackwardLayerInterface & TanhLayer::backward_layer() {
}

const Tensor & TanhLayer::output_node() const {
}

}  // namespace midso
