//
// Created by tag on 03/01/17.
//

#include "../config.h"

#include <stdio.h>

#include <unistd.h>

int main(int argc, char *argv[])
{
    std::string txt = "test morse";
    int key = 13;
    std::string msg = CryptoTools::cryptCesar(txt,key);
    printf("texte a lorigine : %s\n",txt.c_str());
    printf("apres cryptage : %s\n",msg.c_str());
    std::string m=MorseTools::latin2Mors(msg);
    printf("code morse : %s\n",m.c_str());
    std::vector<int> res;
    res = MorseTools::mors2Bin(m);
    for(unsigned i=1;i<=res.size();i++)
    {
        std::cout<<res[i];
    }


    printf("\net on retourne a la case depart ! \n");
    std::string m2 = MorseTools::bin2Mors(res);
    printf("code morse : %s\n",m2.c_str());
    std::string cod = MorseTools::mors2Latin(m2);
    printf("texte codee : %s\n",cod.c_str());
    std::string fin = CryptoTools::cryptCesar(cod,26-key);
    printf("texte retrouve : %s\n",fin.c_str());



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


    fflush(stdout);
}




//exemple dutilisation des pins
/*
string inputstate;
GpioTools* gpio4 = new GpioTools("4"); //create new GPIO object to be attached to  GPIO4
GpioTools* gpio17 = new GpioTools("17"); //create new GPIO object to be attached to  GPIO17

gpio4->export_gpio(); //export GPIO4
gpio17->export_gpio(); //export GPIO17

cout << " GPIO pins exported" << endl;

gpio17->setdir_gpio("in"); //GPIO4 set to output
gpio4->setdir_gpio("out"); // GPIO17 set to input

cout << " Set GPIO pin directions" << endl;
int c = 0;
while(c<100)
{
    usleep(500000);  // wait for 0.5 seconds
    gpio17->getval_gpio(inputstate); //read state of GPIO17 input pin
    cout << "Current input pin state is " << inputstate  <<endl;
    if(inputstate == "0") // if input pin is at state "0" i.e. button pressed
    {
        cout << "input pin state is Pressed .n Will check input pin state again in 20ms "<<endl;
        usleep(20000);
        cout << "Checking again ....." << endl;
        gpio17->getval_gpio(inputstate); // checking again to ensure that state "0" is due to button press and not noise
        if(inputstate == "0")
        {
            cout << "input pin state is definitely Pressed. Turning LED ON" <<endl;
            gpio4->setval_gpio("1"); // turn LED ON

            cout << " Waiting until pin is unpressed....." << endl;
            while (inputstate == "0"){
                gpio17->getval_gpio(inputstate);
            };
            cout << "pin is unpressed" << endl;

        }
        else
            cout << "input pin state is definitely UnPressed . That was just noise." <<endl;

    }
    gpio4->setval_gpio("0");
c++;
}
cout << "Exiting....." << endl;
return 0;
*/


