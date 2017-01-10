//
// Created by tag on 03/01/17.
//

#include "../config.h"

#include <stdio.h>

int main(int argc, char *argv[])
{
    std::string txt = "test morse";
    std::string msg = CryptoTools::cryptCesar(txt,13);
    printf("texte a lorigine : %s\n",txt.c_str());
    printf("apres cryptage : %s\n",msg.c_str());
    std::string m=MorseTools::morsiphy(msg);
    printf("code morse : %s\n",m.c_str());
    std::vector<int> res;
    res = MorseTools::mors2Bin(m);
    for(unsigned i=1;i<=res.size();i++)
    {
        std::cout<<res[i];
    }
    fflush(stdout);
}