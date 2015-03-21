/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "midso/layer/transpose_layer.h"

namespace midso {

TransposeLayer::TransposeLayer(const Int & i_map,
        const Int & i_row,
        const Int & i_col) {
}

TransposeLayer * TransposeLayer::load(const KeyValueTree & config) {
}

void TransposeLayer::init(const Tensor & in_tensor) {
}

void TransposeLayer::set_input(const Tensor & in_tensor) {
}

void TransposeLayer::propagate() {
}

BackwardLayerInterface & TransposeLayer::backward_layer() {
}

const Tensor & TransposeLayer::get_output() const {
}

}  // namespace midso
