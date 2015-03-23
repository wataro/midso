/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#ifndef INCLUDE_MIDSO_NETWORK_NETWORK_H_
#define INCLUDE_MIDSO_NETWORK_NETWORK_H_
#include "midso/common.h"


namespace midso {

class Network {
 public:
    Network() {}
    ~Network() {}
    static Network * load(const KeyValueTree & config);
    void init();
    void propagate(const Size & n_samples);
    void build_backward_network();
    Network & get_backward_network();
    Vector<Tensor> & get_parameters();
    const Tensor & get_output() const;

 private:
    DISALLOW_COPY_AND_ASSIGN(Network);
};

}  // namespace midso

#endif  // INCLUDE_MIDSO_NETWORK_NETWORK_H_
