/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#ifndef INCLUDE_MIDSO_LAYER_BACKWARD_DROPOUT_LAYER_BACKWARD_H_
#define INCLUDE_MIDSO_LAYER_BACKWARD_DROPOUT_LAYER_BACKWARD_H_
#include "midso/common.h"


namespace midso {

class DropoutLayerBackward {
 public:
    DropoutLayerBackward() {}
    ~DropoutLayerBackward() {}


 private:
    DISALLOW_COPY_AND_ASSIGN(DropoutLayerBackward);
};

}  // namespace midso

#endif  // INCLUDE_MIDSO_LAYER_BACKWARD_DROPOUT_LAYER_BACKWARD_H_
