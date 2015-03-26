/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "midso/runner/runner_factory.h"
#include <memory>
#include "midso/runner/train_runner.h"
#include "midso/core/key_value_tree.h"

namespace midso {

SharedPointer<RunnerInterface> RunnerFactory::create(const Vector<String> args)
{
    KeyValueTree kvt(args);
    return std::make_shared<TrainRunner>();
}

}  // namespace midso
