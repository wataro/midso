/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#ifndef SRC_MIDSO_CORE_MEMORY_H_
#define SRC_MIDSO_CORE_MEMORY_H_
#include "midso/common.h"


namespace midso {

class Memory {
 public:
    Memory() {}
    ~Memory() {}
    void reserve(const Size & n_bytes);
    SharedPointer<Byte> allocate();

 private:
    DISALLOW_COPY_AND_ASSIGN(Memory);
};

}  // namespace midso

#endif  // SRC_MIDSO_CORE_MEMORY_H_
