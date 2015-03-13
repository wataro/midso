/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#ifndef INCLUDE_MIDSO_LAYER_FULLY_CONNECTED_LAYER_H_
#define INCLUDE_MIDSO_LAYER_FULLY_CONNECTED_LAYER_H_
#include "midso/common.h"
#include "midso/layer/layer_interface.h"
#include "midso/layer/parametric_interface.h"

namespace midso {

class FullyConnectedLayer : public LayerInterface, public ParametricInterface {
 public:
    FullyConnectedLayer() {}
    ~FullyConnectedLayer() {}
    FullyConnectedLayer(const Size & n_outs);
    static FullyConnectedLayer * load(const Yaml & config);
    void init(const Tensor & input_node);
    void set_input(const Tensor & input_node);
    void propagate();
    LayerInterface & backward_layer();
    void update_parameter(const Tensor & diff);
    const Tensor & parameter() const;
    const Tensor & output_node() const;

 private:
    DISALLOW_COPY_AND_ASSIGN(FullyConnectedLayer);
};

}  // namespace midso

#endif  // INCLUDE_MIDSO_LAYER_FULLY_CONNECTED_LAYER_H_
