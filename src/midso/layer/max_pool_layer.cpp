/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "midso/layer/max_pool_layer.h"

namespace midso {

MaxPoolLayer::MaxPoolLayer(const Size & pool_size_row,
        const Size & pool_size_col,
        const Size & step_size_row,
        const Size & step_size_col) {
}

MaxPoolLayer * MaxPoolLayer::load(const KeyValueTree & config) {
}

void MaxPoolLayer::init(const Tensor & in_tensor) {
}

void MaxPoolLayer::set_input(const Tensor & in_tensor) {
}

void MaxPoolLayer::propagate() {
}

BackwardLayerInterface & MaxPoolLayer::backward_layer() {
}

const Tensor & MaxPoolLayer::get_output() const {
}

}  // namespace midso
