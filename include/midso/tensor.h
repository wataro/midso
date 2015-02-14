/**
    Copyright 2015- <Taro WATASUE>
*/
#ifndef INCLUDE_MIDSO_TENSOR_H_
#define INCLUDE_MIDSO_TENSOR_H_

namespace midso {

class Tensor {
 public:
    enum class CONST {
        MAX_N_DIMENSIONS = 8,
        MAX_N_STRIDES = MAX_N_DIMENSIONS - 1,
    };
    Tensor(
        const Size & d0 = 1,
        const Size & d1 = 1,
        const Size & d2 = 1,
        const Size & d3 = 1,
        const Size & d4 = 1,
        const Size & d5 = 1,
        const Size & d6 = 1,
        const Size & d7 = 1);

    const Size n_dimensions(void) const {
        return this->dimensions_.size();
    }

    const SizeVector & dimensions(void) const {
        return this->dimensions_;
    }

    const Float & operator[](
        const Int & i0 = 0,
        const Int & i1 = 0,
        const Int & i2 = 0,
        const Int & i3 = 0,
        const Int & i4 = 0,
        const Int & i5 = 0,
        const Int & i6 = 0,
        const Int & i7 = 0) {
        const Int index =
            i0 * this->strides_[0] +
            i1 * this->strides_[1] +
            i2 * this->strides_[2] +
            i3 * this->strides_[3] +
            i4 * this->strides_[4] +
            i5 * this->strides_[5] +
            i6 * this->strides_[6] +
            i7;
        MIDSO_ASSERT(index < this->values_.size());
        return this->values_[index];
    }

 private:
    Array<Size, MAX_N_DIMENSIONS>   dimensions_;
    Array<Size, MAX_N_STRIDES>      strides_;
    FloatVector                     values_;
    CudaMemory *                    cuda_values_;

    DISALLOW_COPY_AND_ASSIGN(Tensor);
};

}  // namespace midso

#endif  // INCLUDE_MIDSO_TENSOR_H_

