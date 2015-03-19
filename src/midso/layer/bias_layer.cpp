/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "midso/layer/bias_layer.h"

namespace midso {

BiasLayer * BiasLayer::load(const KeyValue & config) {
}

void BiasLayer::init(const Tensor & input_node) {
}

void BiasLayer::propagate(const Tensor & input_node) {
}

void BiasLayer::set_input(const Tensor & input_node) {
}

void BiasLayer::propagate() {
}

BackwardLayerInterface & BiasLayer::backward_layer() {
}

void BiasLayer::update_parameter(const Tensor & diff) {
}

const Tensor & BiasLayer::parameter() const {
}

const Tensor & BiasLayer::output_node() const {
}

}  // namespace midso
