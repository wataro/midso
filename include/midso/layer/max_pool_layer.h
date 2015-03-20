/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#ifndef INCLUDE_MIDSO_LAYER_MAX_POOL_LAYER_H_
#define INCLUDE_MIDSO_LAYER_MAX_POOL_LAYER_H_
#include "midso/common.h"
#include "midso/layer/layer_interface.h"

namespace midso {

class MaxPoolLayer : public LayerInterface {
 public:
    MaxPoolLayer() {}
    ~MaxPoolLayer() {}
    MaxPoolLayer(const Size & pool_size_row = 2,
        const Size & pool_size_col = 2,
        const Size & step_size_row = 2,
        const Size & step_size_col = 2);
    static MaxPoolLayer * load(const KeyValueTree & config);
    void init(const Tensor & input_node);
    void set_input(const Tensor & input_node);
    void propagate();
    BackwardLayerInterface & backward_layer();
    const Tensor & output_node() const;

 private:
    DISALLOW_COPY_AND_ASSIGN(MaxPoolLayer);
};

}  // namespace midso

#endif  // INCLUDE_MIDSO_LAYER_MAX_POOL_LAYER_H_
