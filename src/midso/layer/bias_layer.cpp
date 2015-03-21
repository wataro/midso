/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "midso/layer/bias_layer.h"

namespace midso {

BiasLayer * BiasLayer::load(const KeyValueTree & config) {
}

void BiasLayer::init(const Tensor & in_tensor) {
}

void BiasLayer::propagate(const Tensor & in_tensor) {
}

void BiasLayer::set_input(const Tensor & in_tensor) {
}

void BiasLayer::propagate() {
}

BackwardLayerInterface & BiasLayer::backward_layer() {
}

void BiasLayer::update_parameter(const Tensor & diff) {
}

const Tensor & BiasLayer::parameter() const {
}

const Tensor & BiasLayer::get_output() const {
}

}  // namespace midso
