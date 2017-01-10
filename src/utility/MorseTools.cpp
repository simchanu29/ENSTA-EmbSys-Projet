
#include "MorseTools.h"

std::string MorseTools::morsiphy(std::string myString){

    std::string latin;
    char latinAlphabet[29] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','.',',',' '};
    std::string morseAlphabet[30] = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".-.-.-", "--..--" };
    std::string morse;
    
    latin=myString;

    for (unsigned i = 0; i<latin.length(); ++i)
    {
        for (int counter = 0; counter < 30; counter++)
        {
                if (latin.at(i) == latinAlphabet[counter])
                {
                    std::cout << morseAlphabet[counter] << "|";
                    break;
                }
        }
    }
        
return morse;
   }

/*
int main()
{
	std::string result=morsiphy("kaaris");
	std::cout<<result;
}*/