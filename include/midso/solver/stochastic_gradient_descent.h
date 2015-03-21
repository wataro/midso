/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#ifndef INCLUDE_MIDSO_SOLVER_STOCHASTIC_GRADIENT_DESCENT_H_
#define INCLUDE_MIDSO_SOLVER_STOCHASTIC_GRADIENT_DESCENT_H_
#include "midso/common.h"
#include "midso/solver/solver_interface.h"

namespace midso {

class StochasticGradientDescent : public SolverInterface {
 public:
    StochasticGradientDescent() {}
    ~StochasticGradientDescent() {}
    StochasticGradientDescent(Network & network);
    static StochasticGradientDescent * load(const KeyValueTree & config);
    bool need_update();
    void update_once();

 private:
    DISALLOW_COPY_AND_ASSIGN(StochasticGradientDescent);
};

}  // namespace midso

#endif  // INCLUDE_MIDSO_SOLVER_STOCHASTIC_GRADIENT_DESCENT_H_
