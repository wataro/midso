/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "midso/layer/convolutional_layer.h"

namespace midso {

ConvolutionalLayer::ConvolutionalLayer(const Size & n_maps,
        const Size & n_rows,
        const Size & n_cols,
        const Size & n_steps_map,
        const Size & n_steps_row,
        const Size & n_steps_col) {
}

static ConvolutionalLayer * ConvolutionalLayer::load(const KeyValue & config) {
}

void ConvolutionalLayer::init(const Tensor & input_node) {
}

void ConvolutionalLayer::set_input(const Tensor & input_node) {
}

void ConvolutionalLayer::propagate() {
}

BackwardLayerInterface & ConvolutionalLayer::backward_layer() {
}

void ConvolutionalLayer::update_parameter(const Tensor & diff) {
}

const Tensor & ConvolutionalLayer::parameter() const {
}

const Tensor & ConvolutionalLayer::output_node() const {
}

}  // namespace midso
