/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "easylogging/easylogging++.h"
#include "midso/midso.h"

INITIALIZE_EASYLOGGINGPP

using namespace midso;

int main(const int argc, const char ** argv)
{
    LOG(INFO) << "Make It Deep, Simple, Open!";
    SharedPointer<Vector<Int>> p_values;
    const Vector<String> args(argv, argv + argc);
    LOG(INFO) << args[0];
    auto runner = RunnerFactory::create(args);
    runner->run();

    return 0;
}

