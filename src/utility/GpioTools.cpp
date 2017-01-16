//
// Created by tag on 03/01/17.
//


#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include "GpioTools.h"


GpioTools::GpioTools()
{
    this->gpionum = "4"; //GPIO4 is default
}

GpioTools::GpioTools(std::string gnum)
{
    this->gpionum = gnum;  //Instatiate GpioTools object for GPIO pin number "gnum"
}

int GpioTools::export_gpio()
{
    std::string export_str = "/sys/class/gpio/export";
    std::ofstream exportgpio(export_str.c_str()); // Open "export" file. Convert C++ string to C string. Required for all Linux pathnames
    /*if (exportgpio < 0){
        std::cout << " OPERATION FAILED: Unable to export GPIO"<< this->gpionum <<" ."<< std::endl;
        return -1;
    }*/

    exportgpio << this->gpionum ; //write GPIO number to export
    exportgpio.close(); //close export file
    return 0;
}

int GpioTools::unexport_gpio()
{
    std::string unexport_str = "/sys/class/gpio/unexport";
    std::ofstream unexportgpio(unexport_str.c_str()); //Open unexport file
    /*if (unexportgpio < 0){
        std::cout << " OPERATION FAILED: Unable to unexport GPIO"<< this->gpionum <<" ."<< std::endl;
        return -1;
    }*/

    unexportgpio << this->gpionum ; //write GPIO number to unexport
    unexportgpio.close(); //close unexport file
    return 0;
}

int GpioTools::setdir_gpio(std::string dir)
{

    std::string setdir_str ="/sys/class/gpio/gpio" + this->gpionum + "/direction";
    std::ofstream setdirgpio(setdir_str.c_str()); // open direction file for gpio
    /*if (setdirgpio < 0){
        std::cout << " OPERATION FAILED: Unable to set direction of GPIO"<< this->gpionum <<" ."<< std::endl;
        return -1;
    }*/

    setdirgpio << dir; //write direction to direction file
    setdirgpio.close(); // close direction file
    return 0;
}

int GpioTools::setval_gpio(std::string val)
{

    std::string setval_str = "/sys/class/gpio/gpio" + this->gpionum + "/value";
    std::ofstream setvalgpio(setval_str.c_str()); // open value file for gpio
    /*if (setvalgpio < 0){
        std::cout << " OPERATION FAILED: Unable to set the value of GPIO"<< this->gpionum <<" ."<< std::endl;
        return -1;
    }*/

    setvalgpio << val ;//write value to value file
    setvalgpio.close();// close value file
    return 0;
}

int GpioTools::getval_gpio(std::string& val){

    std::string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "/value";
    std::ifstream getvalgpio(getval_str.c_str());// open value file for gpio
    /*if (getvalgpio < 0){
        std::cout << " OPERATION FAILED: Unable to get value of GPIO"<< this->gpionum <<" ."<< std::endl;
        return -1;
    }*/

    getvalgpio >> val ;  //read gpio value

    if(val != "0")
        val = "1";
    else
        val = "0";

    getvalgpio.close(); //close the value file
    return 0;
}

std::string GpioTools::get_gpionum(){

    return this->gpionum;

}