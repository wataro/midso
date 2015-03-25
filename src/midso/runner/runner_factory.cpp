/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "midso/runner/runner_factory.h"
#include <memory>
#include "midso/runner/train_runner.h"

namespace midso {

SharedPointer<RunnerInterface>
RunnerFactory::create(
    const int argc,
    const char ** argv)
{
    return std::make_shared<TrainRunner>();
}

}  // namespace midso
