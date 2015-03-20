/**
    Copyright 2015- <Taro WATASUE>
*/
#ifndef INCLUDE_MIDSO_TYPE_H_
#define INCLUDE_MIDSO_TYPE_H_
#include <memory>
#include <vector>
#include <string>

namespace midso {

template<typename T>
using Vector = std::vector<T>;

template<typename T>
using Pointer = std::unique_ptr<T>;

typedef std::size_t Size;
typedef std::string String;
typedef int Int;
typedef float Float;

class BackwardLayerInterface;
class KeyValueTree;
class Network;
class SolverInterface;
class Tensor;
class Yaml;

}  // namespace midso

#endif  // INCLUDE_MIDSO_TYPE_H_

