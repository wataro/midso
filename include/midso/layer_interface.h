/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#ifndef INCLUDE_MIDSO_LAYER_INTERFACE_H_
#define INCLUDE_MIDSO_LAYER_INTERFACE_H_
#include "midso/common.h"


namespace midso {

class LayerInterface {
 public:
    virtual ~LayerInterface() {}

    virtual void propagate(const Tensor & input_node) = 0;
    virtual const Tensor & output_node() = 0;
    virtual LayerInterface & backward_layer() = 0;
};

}  // namespace midso

#endif  // INCLUDE_MIDSO_LAYER_INTERFACE_H_
