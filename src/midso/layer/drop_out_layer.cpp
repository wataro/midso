/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "midso/layer/drop_out_layer.h"

namespace midso {

DropOutLayer::DropOutLayer(const Float & drop_rate) {
}

DropOutLayer * DropOutLayer::load(const KeyValueTree & config) {
}

void DropOutLayer::init(const Tensor & input_node) {
}

void DropOutLayer::set_input(const Tensor & input_node) {
}

void DropOutLayer::propagate() {
}

BackwardLayerInterface & DropOutLayer::backward_layer() {
}

const Tensor & DropOutLayer::output_node() const {
}

}  // namespace midso
