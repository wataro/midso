/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include <cuda.h>

void * allocate_cuda_memory(size_t size)
{
    void * p;
    cudaMalloc(&p, size);
    return p;
}

void delete_cuda_memory(void * p)
{
    cudaFree(p);
}

