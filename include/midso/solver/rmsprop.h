/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#ifndef INCLUDE_MIDSO_SOLVER_RMSPROP_H_
#define INCLUDE_MIDSO_SOLVER_RMSPROP_H_
#include "midso/common.h"


namespace midso {

class Rmsprop {
 public:
    Rmsprop() {}
    ~Rmsprop() {}
    Rmsprop(Network & network);
    static Rmsprop * load(const Yaml & config);
    void solve();

 private:
    DISALLOW_COPY_AND_ASSIGN(Rmsprop);
};

}  // namespace midso

#endif  // INCLUDE_MIDSO_SOLVER_RMSPROP_H_
