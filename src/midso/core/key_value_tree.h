/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#ifndef SRC_MIDSO_CORE_KEY_VALUE_TREE_H_
#define SRC_MIDSO_CORE_KEY_VALUE_TREE_H_
#include "midso/common.h"


namespace midso {

class KeyValueTree {
 public:
    KeyValueTree() {}
    ~KeyValueTree() {}
    KeyValueTree(const Vector<String> & args);

 private:
    DISALLOW_COPY_AND_ASSIGN(KeyValueTree);
};

}  // namespace midso

#endif  // SRC_MIDSO_CORE_KEY_VALUE_TREE_H_
