/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "midso/layer/max_out_layer.h"

namespace midso {

void MaxOutLayer::MaxoutLayer(const Size & pool_size,
        const Size & step_size) {
}

static MaxoutLayer * MaxOutLayer::load(const KeyValue & config) {
}

void MaxOutLayer::init(const Tensor & input_node) {
}

void MaxOutLayer::set_input(const Tensor & input_node) {
}

void MaxOutLayer::propagate() {
}

BackwardLayerInterface & MaxOutLayer::backward_layer() {
}

const Tensor & MaxOutLayer::output_node() const {
}

}  // namespace midso
