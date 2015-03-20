/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "midso/layer/linear_layer.h"

namespace midso {

LinearLayer::LinearLayer(const Float & mul,
        const Float & add) {
}

LinearLayer * LinearLayer::load(const KeyValueTree & config) {
}

void LinearLayer::init(const Tensor & input_node) {
}

void LinearLayer::set_input(const Tensor & input_node) {
}

void LinearLayer::propagate() {
}

BackwardLayerInterface & LinearLayer::backward_layer() {
}

const Tensor & LinearLayer::output_node() const {
}

}  // namespace midso
