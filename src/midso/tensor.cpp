/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "midso/tensor.h"

namespace midso {

Float & Tensor::at(const Size & index0,
        const Size & index1,
        const Size & index2,
        const Size & index3,
        const Size & index4,
        const Size & index5,
        const Size & index6,
        const Size & index7) {
}

Pointer<Float> Tensor::ptr() {
}

const Float & Tensor::at(const Size & index0,
        const Size & index1,
        const Size & index2,
        const Size & index3,
        const Size & index4,
        const Size & index5,
        const Size & index6,
        const Size & index7) const {
}

const Pointer<Float> Tensor::ptr() const {
}

void Tensor::copy_to(Tensor & dst) const {
}

}  // namespace midso
