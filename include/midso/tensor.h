/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#ifndef INCLUDE_MIDSO_TENSOR_H_
#define INCLUDE_MIDSO_TENSOR_H_
#include "midso/common.h"


class Tensor {
 public:

    Float & operator[](const Size & index0 = 0,
        const Size & index1 = 0,
        const Size & index2 = 0,
        const Size & index3 = 0,
        const Size & index4 = 0,
        const Size & index5 = 0,
        const Size & index6 = 0,
        const Size & index7 = 0);
    SharedPointer<Float> ptr();
    const Float & operator[](const Size & index0 = 0,
        const Size & index1 = 0,
        const Size & index2 = 0,
        const Size & index3 = 0,
        const Size & index4 = 0,
        const Size & index5 = 0,
        const Size & index6 = 0,
        const Size & index7 = 0) const;
    const SharedPointer<Float> ptr() const;
    void copy_to(Tensor & dst) const;

 private:
    DISALLOW_COPY_AND_ASIGN(Tensor);
};

#endif  // INCLUDE_MIDSO_TENSOR_H_
