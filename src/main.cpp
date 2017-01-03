//
// Created by tag on 03/01/17.
//

#include "config.h"

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <iostream>

volatile sig_atomic_t flag = 1;
void interrupt(int sig){
    flag = 0; // set flag
}

int main(){
    // Register signals
    signal(SIGINT, interrupt);
    signal(SIGTERM,interrupt);

    // Creation du serveur

    while(flag) {
        // Reception des string

        // Cryptage
        CryptoTools::exampleFunction();

        // Transformation en morse

        // Envoi au GPIO
        // Envoi cadencé
    }

    // Fermeture du serveur
    std::cout << "Hello World! ";
}