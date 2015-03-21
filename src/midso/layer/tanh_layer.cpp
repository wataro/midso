/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "midso/layer/tanh_layer.h"

namespace midso {

TanhLayer * TanhLayer::load(const KeyValueTree & config) {
}

void TanhLayer::init(const Tensor & in_tensor) {
}

void TanhLayer::set_input(const Tensor & in_tensor) {
}

void TanhLayer::propagate() {
}

BackwardLayerInterface & TanhLayer::backward_layer() {
}

const Tensor & TanhLayer::get_output() const {
}

}  // namespace midso
