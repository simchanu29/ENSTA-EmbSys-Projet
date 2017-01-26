//
// Created by tag on 03/01/17.
//

#pragma once

#include <iostream>
#include <vector>

class MorseTools
{
public:
    static std::string latin2Mors(std::string msg);
    static std::vector<int> mors2Bin(std::string morse);
    static std::string bin2Mors(std::vector<int> bin);
    static std::string mors2Latin(std::string morse);

};
