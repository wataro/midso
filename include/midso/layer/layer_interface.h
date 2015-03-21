/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#ifndef INCLUDE_MIDSO_LAYER_LAYER_INTERFACE_H_
#define INCLUDE_MIDSO_LAYER_LAYER_INTERFACE_H_
#include "midso/common.h"


namespace midso {

class LayerInterface {
 public:
    virtual ~LayerInterface() {}

    virtual void init(const Tensor & in_tensor) = 0;
    virtual void set_input(const Tensor & in_tensor) = 0;
    virtual void propagate() = 0;
    virtual BackwardLayerInterface & backward_layer() = 0;
    virtual const Tensor &  get_output() const = 0;
};

}  // namespace midso

#endif  // INCLUDE_MIDSO_LAYER_LAYER_INTERFACE_H_
