/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "midso/layer/average_pool_layer.h"

namespace midso {

AveragePoolLayer::AveragePoolLayer(const Size & n_maps,
        const Size & n_rows,
        const Size & n_cols,
        const Size & n_steps_map,
        const Size & n_steps_row,
        const Size & n_steps_col) {
}

AveragePoolLayer * AveragePoolLayer::load(const KeyValue & config) {
}

void AveragePoolLayer::init(const Tensor & input_node) {
}

void AveragePoolLayer::set_input(const Tensor & input_node) {
}

void AveragePoolLayer::propagate() {
}

BackwardLayerInterface & AveragePoolLayer::backward_layer() {
}

const Tensor & AveragePoolLayer::output_node() const {
}

}  // namespace midso
