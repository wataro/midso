/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "midso/layer/fully_connected_layer.h"

namespace midso {

FullyConnectedLayer::FullyConnectedLayer(const Size & n_outs) {
}

FullyConnectedLayer * FullyConnectedLayer::load(const KeyValue & config) {
}

void FullyConnectedLayer::init(const Tensor & input_node) {
}

void FullyConnectedLayer::set_input(const Tensor & input_node) {
}

void FullyConnectedLayer::propagate() {
}

BackwardLayerInterface & FullyConnectedLayer::backward_layer() {
}

void FullyConnectedLayer::update_parameter(const Tensor & diff) {
}

const Tensor & FullyConnectedLayer::parameter() const {
}

const Tensor & FullyConnectedLayer::output_node() const {
}

}  // namespace midso
