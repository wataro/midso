/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "midso/layer/fully_connected_layer.h"

namespace midso {

FullyConnectedLayer::FullyConnectedLayer(const Size & n_outs) {
}

FullyConnectedLayer * FullyConnectedLayer::load(const KeyValueTree & config) {
}

void FullyConnectedLayer::init(const Tensor & in_tensor) {
}

void FullyConnectedLayer::set_input(const Tensor & in_tensor) {
}

void FullyConnectedLayer::propagate() {
}

BackwardLayerInterface & FullyConnectedLayer::backward_layer() {
}

void FullyConnectedLayer::update_parameter(const Tensor & diff) {
}

const Tensor & FullyConnectedLayer::parameter() const {
}

const Tensor & FullyConnectedLayer::get_output() const {
}

}  // namespace midso
