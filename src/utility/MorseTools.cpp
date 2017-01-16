
#include <tuple>
#include "MorseTools.h"

template<typename T, size_t N>
T * end(T (&ra)[N]) {
    return ra + N;
}

std::string MorseTools::morsiphy(std::string myString){

    std::string latin;
    const char* a[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".-.-.-",".-.-", "_" };
    char latinAlphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','.',',',' '};
    std::vector<std::string> morseAlphabet(a, end(a));
    std::string mrs;
    latin = "";
    for (unsigned i = 0; i<myString.length(); ++i)
    {
        for (int counter = 0; counter < morseAlphabet.size(); counter++)
        {
                if (myString.at(i) == latinAlphabet[counter])
                {
                    latin += morseAlphabet[counter];
                    latin += "|";
                    break;
                }
        }
    }
return latin;
   }


std::vector<int> MorseTools::mors2Bin(std::string morse)
{
    std::vector<int> code;
    char c;
    code.push_back(0);
    for (unsigned i=0; i<morse.length(); i++) {
        c = morse.at(i);
        switch (c)
        {
        case '.' :
            code.push_back(1);
                break;
        case '-' :
            code.push_back(1);
            code.push_back(1);
            code.push_back(1);
                break;
        case '|' :
            code.push_back(0);
                break;
        case '_' :
            code.push_back(0);
                break;
        default:
            code.push_back(-1);
                break;

        }

        code.push_back(0);
    }
    return code;
}


std::string MorseTools::bin2Morse(std::vector<int> bin)
{
    std::string morse;
    int last;
    int compteur = 0;
    int nb;
    int current;
    last = 1;
    while(bin.at(compteur)==0)
    {
        compteur++;
    }
    for (int i = compteur;  i <bin.size() ; i++)
    {
        current = bin.at(i);
        if(current==-1)
            break;
        if(current==last)
        {
            nb++;
        }
        else
        {
            if(last ==1 && nb == 1)
            {
                morse+=".";
            }
            else if(last ==1 && nb == 3)
            {
                morse+="-";
            }
            else if(last ==0 && nb == 3)
            {
                morse+="|";
            }
            else if (last ==0 && nb == 7)
            {
                morse+="|_|";
            }
            nb = 1;
        }
        last = current;

    }
    morse+="|";
    return morse;
}



/*
int main()
{
	std::string result=morsiphy("kaaris");
	std::cout<<result;
}*/