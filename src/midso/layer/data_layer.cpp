/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "midso/layer/data_layer.h"

namespace midso {

DataLayer::DataLayer(const String & file_name,
        const String & data_name) {
}

DataLayer * DataLayer::load(const KeyValueTree & config) {
}

void DataLayer::init(const Tensor & in_tensor) {
}

void DataLayer::set_input(const Tensor & in_tensor) {
}

void DataLayer::propagate() {
}

BackwardLayerInterface & DataLayer::backward_layer() {
}

const Tensor & DataLayer::get_output() const {
}

}  // namespace midso
