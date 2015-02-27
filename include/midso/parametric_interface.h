/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#ifndef INCLUDE_MIDSO_PARAMETRIC_INTERFACE_H_
#define INCLUDE_MIDSO_PARAMETRIC_INTERFACE_H_
#include "midso/common.h"


class ParametricInterface {
 public:
    virtual ~ParametricInterface();

    virtual const Tensor & parameter() const = 0;

};

#endif  // INCLUDE_MIDSO_PARAMETRIC_INTERFACE_H_
