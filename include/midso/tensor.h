/**
    Copyright (c) 2015 <Taro WATASUE>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#ifndef INCLUDE_MIDSO_TENSOR_H_
#define INCLUDE_MIDSO_TENSOR_H_

class Tensor {
 public:
    Tensor();

    ~Tensor();

    const Float & const operator[](const Size & index0 = 0
        const Size & index1 = 0
        const Size & index2 = 0
        const Size & index3 = 0
        const Size & index4 = 0
        const Size & index5 = 0
        const Size & index6 = 0
        const Size & index7 = 0);
    Float & operator[](const Size & index0 = 0
        const Size & index1 = 0
        const Size & index2 = 0
        const Size & index3 = 0
        const Size & index4 = 0
        const Size & index5 = 0
        const Size & index6 = 0
        const Size & index7 = 0);
    const SharedPointer<Float> const ptr();
    SharedPointer<Float> ptr();
    void const copy_to(Tensor & dst);

 private:
    DISALLOW_COPY_AND_ASIGN(Tensor);
};

#endif  // INCLUDE_MIDSO_TENSOR_H_
