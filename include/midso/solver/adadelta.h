/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#ifndef INCLUDE_MIDSO_SOLVER_ADADELTA_H_
#define INCLUDE_MIDSO_SOLVER_ADADELTA_H_
#include "midso/common.h"
#include "midso/solver/solver_interface.h"

namespace midso {

class Adadelta : public SolverInterface {
 public:
    Adadelta() {}
    ~Adadelta() {}
    Adadelta(Network & network);
    static Adadelta * load(const KeyValueTree & config);
    bool need_update();
    void update_once();

 private:
    DISALLOW_COPY_AND_ASSIGN(Adadelta);
};

}  // namespace midso

#endif  // INCLUDE_MIDSO_SOLVER_ADADELTA_H_
