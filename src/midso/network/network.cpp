/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "midso/network/network.h"

namespace midso {

Network * Network::load(const KeyValueTree & config) {
}

void Network::init() {
}

void Network::propagate() {
}

void Network::build_backward_network() {
}

Network & Network::get_backward_network() {
}

Vector<Tensor> & Network::get_parameters() {
}

const Tensor & Network::get_output() const {
}

}  // namespace midso
