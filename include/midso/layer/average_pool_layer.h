/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#ifndef INCLUDE_MIDSO_LAYER_AVERAGE_POOL_LAYER_H_
#define INCLUDE_MIDSO_LAYER_AVERAGE_POOL_LAYER_H_
#include "midso/common.h"
#include "midso/layer/layer_interface.h"

namespace midso {

class AveragePoolLayer : public LayerInterface {
 public:
    AveragePoolLayer() {}
    ~AveragePoolLayer() {}
    AveragePoolLayer(const Size & n_maps,
        const Size & n_rows,
        const Size & n_cols,
        const Size & n_steps_map = 1,
        const Size & n_steps_row = 1,
        const Size & n_steps_col = 1);
    static AveragePoolLayer * load(const KeyValueTree & config);
    void init(const Tensor & in_tensor);
    void set_input(const Tensor & in_tensor);
    void propagate();
    BackwardLayerInterface & backward_layer();
    const Tensor & get_output() const;

 private:
    DISALLOW_COPY_AND_ASSIGN(AveragePoolLayer);
};

}  // namespace midso

#endif  // INCLUDE_MIDSO_LAYER_AVERAGE_POOL_LAYER_H_
