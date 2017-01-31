//
// Created by tag on 03/01/17.
//

#include "config.h"
#include <stdio.h>
#include <unistd.h>
#include <csignal>

/**
 * Flag pour la boucle while du main
 */
volatile sig_atomic_t flag = 1;

/**
 * Interrution pour interrompre le while du main
 * @param sig
 */
void interrupt(int sig){
	flag = 0; // set flag
}



/**
 * Server. Il reçoit le signal du client et le code pour le renvoyer au GPIO.
 *
 * USAGE
 * ./main-server.out [port]
 *
 * EXEMPLE
 * ./main-server.out
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    // Register signals
    signal(SIGINT, interrupt);
    signal(SIGTERM,interrupt);

    NetworkTools::initServer(argc, argv);
    std::string txt = "test morse";
    
    while(flag){

        // Reception de la phrase du client
    	txt = (std::string) NetworkTools::wait_connection();

        // Cryptage césar
    	int key = 13;
    	std::string msg = CryptoTools::cryptCesar(txt,key);
        printf("texte a lorigine : %s\n",txt.c_str());
        printf("apres cryptage : %s\n",msg.c_str());

        // Transcription en morse
        std::string m=MorseTools::latin2Mors(msg);
        printf("code morse : %s\n",m.c_str());

        // Transcription en binaire
        std::vector<int> res;
    	res = MorseTools::mors2Bin(m);
    	for(unsigned i=1;i<=res.size();i++)
        {
            std::cout<<res[i];
        }

            // DEBUG
            printf("\net on retourne a la case depart ! \n");
            std::string m2 = MorseTools::bin2Mors(res);
            printf("code morse : %s\n",m2.c_str());
            std::string cod = MorseTools::mors2Latin(m2);
            printf("texte codee : %s\n",cod.c_str());
            std::string fin = CryptoTools::cryptCesar(cod,26-key);
            printf("texte retrouve : %s\n",fin.c_str());

        // Ecriture sur les GPIO
    	std::string inputstate;
    	GpioTools* gpio4 = new GpioTools("4"); //create new GPIO object to be attached to  GPIO4

    	gpio4->export_gpio(); //export GPIO4
    	std::cout << " GPIO pins exported" << std::endl;

    	gpio4->setdir_gpio("out"); // GPIO17 set to input
    	std::cout << " Set GPIO pin directions" << std::endl;

    	for(int i : res)
    	{
        	gpio4->setval_gpio("0"); // turn LED ON
        	if(i == 1)
        	{
            	gpio4->setval_gpio("1"); // turn LED ON
            	std::cout << "LED ON..... 1" << std::endl;
            	usleep(250000);  // wait for 0.25 seconds
        	}
        	else if (i == 0)
        	{
            	gpio4->setval_gpio("0"); // turn LED ON
            	std::cout << "LED OFF..... 0" << std::endl;
            	usleep(250000);  // wait for 0.25 seconds
        	}

    	}
    	gpio4->setval_gpio("0"); // turn LED ON

    	std::cout << "Exiting....." << std::endl;

        // Affichage du texte
    	fflush(stdout);
    
    }
    NetworkTools::close_connection();
}