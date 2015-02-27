/**
    Copyright 2015- <Taro WATASUE>
*/
#ifndef INCLUDE_MIDSO_TYPE_H_
#define INCLUDE_MIDSO_TYPE_H_
#include <memory>
#include <vector>

namespace midso {

template<typename T>
using Vector = std::vector<T>;

template<typename T>
using Pointer = std::unique_ptr<T>;

typedef std::size_t Size;
typedef int Int;
typedef float Float;

}  // namespace midso

#endif  // INCLUDE_MIDSO_TYPE_H_

