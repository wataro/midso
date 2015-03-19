/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#ifndef INCLUDE_MIDSO_LAYER_BACKWARD_BACKWARD_LAYER_INTERFACE_H_
#define INCLUDE_MIDSO_LAYER_BACKWARD_BACKWARD_LAYER_INTERFACE_H_
#include "midso/common.h"


namespace midso {

class BackwardLayerInterface {
 public:
    virtual ~BackwardLayerInterface() {}

    virtual void init(const Tensor & input_node) = 0;
    virtual void set_input(const Tensor & input_node) = 0;
    virtual void propagate() = 0;
    virtual const Tensor &  output_node() const = 0;
};

}  // namespace midso

#endif  // INCLUDE_MIDSO_LAYER_BACKWARD_BACKWARD_LAYER_INTERFACE_H_
