/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "midso/layer/locally_connected_layer.h"

namespace midso {

LocallyConnectedLayer::LocallyConnectedLayer(const Size & n_maps,
        const Size & n_rows,
        const Size & n_cols,
        const Size & n_steps_map,
        const Size & n_steps_row,
        const Size & n_steps_col) {
}

LocallyConnectedLayer * LocallyConnectedLayer::load(const KeyValueTree & config) {
}

void LocallyConnectedLayer::init(const Tensor & input_node) {
}

void LocallyConnectedLayer::set_input(const Tensor & input_node) {
}

void LocallyConnectedLayer::propagate() {
}

BackwardLayerInterface & LocallyConnectedLayer::backward_layer() {
}

void LocallyConnectedLayer::update_parameter(const Tensor & diff) {
}

const Tensor & LocallyConnectedLayer::parameter() const {
}

const Tensor & LocallyConnectedLayer::output_node() const {
}

}  // namespace midso
