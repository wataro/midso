/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "midso/layer/max_out_layer.h"

namespace midso {

MaxOutLayer::MaxOutLayer(const Size & pool_size,
        const Size & step_size) {
}

MaxOutLayer * MaxOutLayer::load(const KeyValueTree & config) {
}

void MaxOutLayer::init(const Tensor & in_tensor) {
}

void MaxOutLayer::set_input(const Tensor & in_tensor) {
}

void MaxOutLayer::propagate() {
}

BackwardLayerInterface & MaxOutLayer::backward_layer() {
}

const Tensor & MaxOutLayer::get_output() const {
}

}  // namespace midso
