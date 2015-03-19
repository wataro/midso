#include "gtest/gtest.h"
#include <memory>
#include <vector>

template<typename T>
using Vector = std::vector<T>;

template<typename T>
using Pointer = std::unique_ptr<T>;

typedef int Int;
typedef unsigned char Byte;
typedef float Float;

namespace{
}   // namespace

class Tensor
{
    public:
    Tensor(const Int size): dimensions_(1), values_(size, 0)
    {
        this->dimensions_[0] = size;
    }
    Tensor(const Int size0, const Int size1): dimensions_(2), values_(size0 * size1, 0)
    {
        this->dimensions_[0] = size0;
        this->dimensions_[1] = size1;
    }
    const Float & at(const Int i)
    {
        return this->values_[i];
    }
    const Float & at(const Int i0, const Int i1)
    {
        const Int index = this->dimensions_[1] * i0 + i1;
        return this->values_[index];
    }
#if 0
    Float operator[](const Int i0, const Int i1) { return 0; }  // compile error
    Float operator[](const Int i0, const Int i1, const Int i2) { return 0; }    // compile error
#endif  // 0
    private:
    Vector<Int> dimensions_;
    Vector<Float> values_;
};

TEST(SANDBOX, TENSOR)
{
    Tensor tensor(7, 9);
    Int v00 = tensor.at(2);
    Int v01 = tensor.at(3, 5);
#if 0
    Int v1 = tensor[2, 5];       // compile error
    Int v2 = tensor[3, 7, 11];   // compile error
#endif  // 0
}

