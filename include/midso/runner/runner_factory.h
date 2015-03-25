/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#ifndef INCLUDE_MIDSO_RUNNER_RUNNER_FACTORY_H_
#define INCLUDE_MIDSO_RUNNER_RUNNER_FACTORY_H_
#include "midso/common.h"


namespace midso {

class RunnerFactory {
 public:
    RunnerFactory() {}
    ~RunnerFactory() {}
    static SharedPointer<RunnerInterface> create(const int argc,
        const char ** argv);

 private:
    DISALLOW_COPY_AND_ASSIGN(RunnerFactory);
};

}  // namespace midso

#endif  // INCLUDE_MIDSO_RUNNER_RUNNER_FACTORY_H_
