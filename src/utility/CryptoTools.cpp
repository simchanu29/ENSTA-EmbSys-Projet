//
// Created by tag on 03/01/17.
//

#include "CryptoTools.h"
#include <stdio.h>

std::string CryptoTools::cryptCesar(std::string msg, int decalage)
{
    int compt = 0;
    std::string sig;
    char lettre = msg[compt];
    int let;
    while(lettre )
    {
        if(lettre!=' ')
        {
            let = lettre;
            let = (let + decalage - 'a') % 26 + 'a';
            sig += (char) let;
        } else
            sig += lettre;


        compt++;
        lettre = msg[compt];
    }
    return sig;
}