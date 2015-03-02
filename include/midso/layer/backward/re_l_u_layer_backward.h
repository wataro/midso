/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#ifndef INCLUDE_MIDSO_LAYER_BACKWARD_RE_L_U_LAYER_BACKWARD_H_
#define INCLUDE_MIDSO_LAYER_BACKWARD_RE_L_U_LAYER_BACKWARD_H_
#include "midso/common.h"


namespace midso {

class ReLULayerBackward {
 public:
    ReLULayerBackward() {}
    ~ReLULayerBackward() {}


 private:
    DISALLOW_COPY_AND_ASSIGN(ReLULayerBackward);
};

}  // namespace midso

#endif  // INCLUDE_MIDSO_LAYER_BACKWARD_RE_L_U_LAYER_BACKWARD_H_
