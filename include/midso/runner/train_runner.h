/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#ifndef INCLUDE_MIDSO_RUNNER_TRAIN_RUNNER_H_
#define INCLUDE_MIDSO_RUNNER_TRAIN_RUNNER_H_
#include "midso/common.h"
#include "midso/runner/runner_interface.h"

namespace midso {

class TrainRunner : public RunnerInterface {
 public:
    TrainRunner() {}
    ~TrainRunner() {}
    TrainRunner(const SolverInterface & solver,
        const Network & network);
    void run();

 private:
    DISALLOW_COPY_AND_ASSIGN(TrainRunner);
};

}  // namespace midso

#endif  // INCLUDE_MIDSO_RUNNER_TRAIN_RUNNER_H_
