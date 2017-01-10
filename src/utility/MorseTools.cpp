
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
    int c = myString.length();
    int c1 = morseAlphabet.size();
    int c2 = sizeof(latinAlphabet);
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







/*
int main()
{
	std::string result=morsiphy("kaaris");
	std::cout<<result;
}*/