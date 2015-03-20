/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#ifndef INCLUDE_MIDSO_RUNNER_TEST_RUNNER_H_
#define INCLUDE_MIDSO_RUNNER_TEST_RUNNER_H_
#include "midso/common.h"
#include "midso/runner/runner_interface.h"

namespace midso {

class TestRunner : public RunnerInterface {
 public:
    TestRunner() {}
    ~TestRunner() {}
    TestRunner(const Network & network);
    void run();

 private:
    DISALLOW_COPY_AND_ASSIGN(TestRunner);
};

}  // namespace midso

#endif  // INCLUDE_MIDSO_RUNNER_TEST_RUNNER_H_
