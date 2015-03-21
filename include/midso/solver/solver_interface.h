/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#ifndef INCLUDE_MIDSO_SOLVER_SOLVER_INTERFACE_H_
#define INCLUDE_MIDSO_SOLVER_SOLVER_INTERFACE_H_
#include "midso/common.h"


namespace midso {

class SolverInterface {
 public:
    virtual ~SolverInterface() {}

    virtual bool need_update() = 0;
    virtual void update_once() = 0;
};

}  // namespace midso

#endif  // INCLUDE_MIDSO_SOLVER_SOLVER_INTERFACE_H_
