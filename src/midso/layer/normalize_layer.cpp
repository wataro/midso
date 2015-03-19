/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "midso/layer/normalize_layer.h"

namespace midso {

static NormalizeLayer * NormalizeLayer::load(const KeyValue & config) {
}

void NormalizeLayer::init(const Tensor & input_node) {
}

void NormalizeLayer::propagate(const Tensor & input_node) {
}

void NormalizeLayer::set_input(const Tensor & input_node) {
}

void NormalizeLayer::propagate() {
}

BackwardLayerInterface & NormalizeLayer::backward_layer() {
}

const Tensor & NormalizeLayer::output_node() const {
}

}  // namespace midso
