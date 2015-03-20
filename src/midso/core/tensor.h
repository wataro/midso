/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#ifndef SRC_MIDSO_CORE_TENSOR_H_
#define SRC_MIDSO_CORE_TENSOR_H_
#include "midso/common.h"


namespace midso {

class Tensor {
 public:
    Tensor() {}
    ~Tensor() {}
    Float & at(const Size & index0 = 0,
        const Size & index1 = 0,
        const Size & index2 = 0,
        const Size & index3 = 0,
        const Size & index4 = 0,
        const Size & index5 = 0,
        const Size & index6 = 0,
        const Size & index7 = 0);
    Pointer<Float> ptr();
    const Float & at(const Size & index0 = 0,
        const Size & index1 = 0,
        const Size & index2 = 0,
        const Size & index3 = 0,
        const Size & index4 = 0,
        const Size & index5 = 0,
        const Size & index6 = 0,
        const Size & index7 = 0) const;
    const Pointer<Float> ptr() const;
    void copy_to(Tensor & dst) const;

 private:
    DISALLOW_COPY_AND_ASSIGN(Tensor);
};

}  // namespace midso

#endif  // SRC_MIDSO_CORE_TENSOR_H_
