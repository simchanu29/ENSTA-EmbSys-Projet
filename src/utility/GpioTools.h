//
// Created by tag on 03/01/17.
//

#pragma once

#include <string>

class GpioTools
{
public:
    /**
     * hfhgfh
     */
    GpioTools();  // create a GPIO object that controls GPIO4 (default
    GpioTools(std::string x); // create a GPIO object that controls GPIOx, where x is passed to this constructor
    int export_gpio(); // exports GPIO
    int unexport_gpio(); // unexport GPIO
    int setdir_gpio(std::string dir); // Set GPIO Direction
    int setval_gpio(std::string val); // Set GPIO Value (putput pins)
    int getval_gpio(std::string& val); // Get GPIO Value (input/ output pins)
    std::string get_gpionum(); // return the GPIO number associated with the instance of an object
private:
    std::string gpionum; // GPIO number associated with the instance of an object
};