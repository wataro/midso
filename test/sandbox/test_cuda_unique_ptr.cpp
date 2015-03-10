/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "gtest/gtest.h"
#include <memory>
#include <functional>

extern void * allocate_cuda_memory(size_t size);
extern void delete_cuda_memory(void *);

class CudaMemoryDeleter {
    public:
    void operator() (void * p)
    {
        delete_cuda_memory(p);
    }
};

TEST(SANDBOX, CUDA_unique_ptr)
{
    void * p = allocate_cuda_memory(100);
    delete_cuda_memory(p);

    std::unique_ptr<void, CudaMemoryDeleter> pp(allocate_cuda_memory(100));
}

