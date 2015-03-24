#include "gtest/gtest.h"
#include <memory>
#include <vector>

template<typename T>
using Vector = std::vector<T>;

template<typename T>
using Pointer = std::unique_ptr<T>;

template<typename T>
using WeakPointer = std::weak_ptr<T>;

TEST(SANDBOX, PTR)
{
    Pointer<Vector<int>> p_int(new Vector<int>(10));
    (*p_int)[0] = 2;
    Pointer<Vector<int>> p2_int(new Vector<int>(10));
    (*p2_int) = (*p_int);
    ASSERT_EQ(2, (*p2_int)[0]);

    std::shared_ptr<Vector<int>> s_int = std::make_shared<Vector<int>>(10);
    (*s_int)[0] = 3;
    WeakPointer<Vector<int>> w_int = s_int;
    auto ptr = w_int.lock();
    ASSERT_EQ(3, (*ptr)[0]);
}

