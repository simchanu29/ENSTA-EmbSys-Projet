#include <iostream>
#include <iterator>
#include <cstring>

std::string cryptCesar (std::string msg, int decalage)
{
    int compt = 0;
    std::string sig;
    char lettre = msg[compt];
    int let;
    while(lettre)
    {
        if(lettre!=' ')
        {
            let = lettre;
            let = (let + decalage - 'a') % 26 + 'a';
            sig[compt] = let;
        } else
            sig[compt] = lettre;


        compt++;
        lettre = msg[compt];
    }
    return sig;
}


int* char2morse(char let)
{
    int* m;
    switch (let)
        case 'a' : m =0;

}


int main(int argc, char *argv[])
{
    std::string txt = "test morse";
    std::string msg = cryptCesar(txt,13);
    printf("%s\n",txt.c_str());
    printf("%s\n",msg.c_str());
    fflush(stdout);
}