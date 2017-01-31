//
// Created by tag on 03/01/17.
//

#pragma once

#include <iostream>
#include <vector>

/**
 * Boite à outil concernant le morse
 */
class MorseTools
{
public:
    /**
     * Traduit un message en lettres latines en morse d'après les conventions internationales
     * @param msg : message en lettres latines
     * @return message en morse
     */
    static std::string latin2Mors(std::string msg);

    /**
     * Transforme le morse en binaire
     * @param morse : message en morse (. et -)
     * @return message en binaire
     */
    static std::vector<int> mors2Bin(std::string morse);

    /**
     * Transforme le binaire en morse sachant que un chiffre vaut 1/4 de temps dans les conventions internationales
     * @param bin
     * @return std::vector<int> : un vecteur de 0 ou de 1
     */
    static std::string bin2Mors(std::vector<int> bin);

    /**
     * Transforme le morse en caractère latins
     * @param morse : message en morse (. et -)
     * @return message en caractères latins
     */
    static std::string mors2Latin(std::string morse);

};
