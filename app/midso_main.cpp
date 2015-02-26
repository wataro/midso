/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "easylogging/easylogging++.h"
#include "midso/type.h"

INITIALIZE_EASYLOGGINGPP

using namespace midso;

int main(const int argc, const char ** argv)
{
    LOG(INFO) << "Make It Deep, Simple, Open!";
    Pointer<Vector<Int>> p_values;
    return 0;
}

