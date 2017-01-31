//
// Created by tag on 03/01/17.
//

#pragma once

#include <iostream>

/**
 * Toolbox for handling cryptography
 */
class CryptoTools
{
public:
    /**
     * Cryptage césar
     * @param msg : message à coder
     * @param decalage
     * @return message crypté
     */
    static std::string cryptCesar(std::string msg, int decalage);
};
