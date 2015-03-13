/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#ifndef INCLUDE_MIDSO_LAYER_LOCALLY_CONNECTED_LAYER_H_
#define INCLUDE_MIDSO_LAYER_LOCALLY_CONNECTED_LAYER_H_
#include "midso/common.h"
#include "midso/layer/layer_interface.h"
#include "midso/layer/parametric_interface.h"

namespace midso {

class LocallyConnectedLayer : public LayerInterface, public ParametricInterface {
 public:
    LocallyConnectedLayer() {}
    ~LocallyConnectedLayer() {}
    LocallyConnectedLayer(const Size & n_maps,
        const Size & n_rows,
        const Size & n_cols,
        const Size & n_steps_map = 1,
        const Size & n_steps_row = 1,
        const Size & n_steps_col = 1);
    static LocallyConnectedLayer * load(const Yaml & config);
    void init(const Tensor & input_node);
    void set_input(const Tensor & input_node);
    void propagate();
    LayerInterface & backward_layer();
    void update_parameter(const Tensor & diff);
    const Tensor & parameter() const;
    const Tensor & output_node() const;

 private:
    DISALLOW_COPY_AND_ASSIGN(LocallyConnectedLayer);
};

}  // namespace midso

#endif  // INCLUDE_MIDSO_LAYER_LOCALLY_CONNECTED_LAYER_H_
