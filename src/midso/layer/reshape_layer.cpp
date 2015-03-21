/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "midso/layer/reshape_layer.h"

namespace midso {

ReshapeLayer::ReshapeLayer(const Size & n_maps,
        const Size & n_rows,
        const Size & n_cols) {
}

ReshapeLayer * ReshapeLayer::load(const KeyValueTree & config) {
}

void ReshapeLayer::init(const Tensor & in_tensor) {
}

void ReshapeLayer::propagate(const Tensor & in_tensor) {
}

void ReshapeLayer::set_input(const Tensor & in_tensor) {
}

void ReshapeLayer::propagate() {
}

BackwardLayerInterface & ReshapeLayer::backward_layer() {
}

const Tensor & ReshapeLayer::get_output() const {
}

}  // namespace midso
