/**
    Copyright (c) 2015 <wataro>
    
    This software is released under the MIT License.

    http://opensource.org/licenses/mit-license.php
*/
#include "easylogging/easylogging++.h"

INITIALIZE_EASYLOGGINGPP

int main(const int argc, const char ** argv)
{
    LOG(INFO) << "Make It Deep, Simple, Open!";
    return 0;
}

