/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#ifndef INCLUDE_MIDSO_LAYER_BACKWARD_RELU_LAYER_BACKWARD_H_
#define INCLUDE_MIDSO_LAYER_BACKWARD_RELU_LAYER_BACKWARD_H_
#include "midso/common.h"


namespace midso {

class ReluLayerBackward {
 public:
    ReluLayerBackward() {}
    ~ReluLayerBackward() {}


 private:
    DISALLOW_COPY_AND_ASSIGN(ReluLayerBackward);
};

}  // namespace midso

#endif  // INCLUDE_MIDSO_LAYER_BACKWARD_RELU_LAYER_BACKWARD_H_
