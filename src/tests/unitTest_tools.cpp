//
// Created by tag on 03/01/17.
//

#include "../config.h"

#include <stdio.h>

int main(int argc, char *argv[])
{
    std::string txt = "test morse";
    std::string msg = CryptoTools::cryptCesar(txt,13);
    printf("%s\n",txt.c_str());
    printf("%s\n",msg.c_str());
    fflush(stdout);
}