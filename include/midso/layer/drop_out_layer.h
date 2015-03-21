/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#ifndef INCLUDE_MIDSO_LAYER_DROP_OUT_LAYER_H_
#define INCLUDE_MIDSO_LAYER_DROP_OUT_LAYER_H_
#include "midso/common.h"
#include "midso/layer/layer_interface.h"

namespace midso {

class DropOutLayer : public LayerInterface {
 public:
    DropOutLayer() {}
    ~DropOutLayer() {}
    DropOutLayer(const Float & drop_rate = 0.5);
    static DropOutLayer * load(const KeyValueTree & config);
    void init(const Tensor & in_tensor);
    void set_input(const Tensor & in_tensor);
    void propagate();
    BackwardLayerInterface & backward_layer();
    const Tensor & get_output() const;

 private:
    DISALLOW_COPY_AND_ASSIGN(DropOutLayer);
};

}  // namespace midso

#endif  // INCLUDE_MIDSO_LAYER_DROP_OUT_LAYER_H_
