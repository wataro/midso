/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "midso/layer/logistic_regression_layer.h"

namespace midso {

LogisticRegressionLayer::LogisticRegressionLayer(const Size & n_outs) {
}

LogisticRegressionLayer * LogisticRegressionLayer::load(const KeyValueTree & config) {
}

void LogisticRegressionLayer::init(const Tensor & in_tensor) {
}

void LogisticRegressionLayer::set_input(const Tensor & in_tensor) {
}

void LogisticRegressionLayer::propagate() {
}

BackwardLayerInterface & LogisticRegressionLayer::backward_layer() {
}

void LogisticRegressionLayer::update_parameter(const Tensor & diff) {
}

const Tensor & LogisticRegressionLayer::parameter() const {
}

const Tensor & LogisticRegressionLayer::get_output() const {
}

}  // namespace midso
