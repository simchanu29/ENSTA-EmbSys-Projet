//
// Created by tag on 03/01/17.
//

#pragma once

#include <string>

class GpioTools
{
public:
    /**
     * Constructeur basique de GpioTools
     */
    GpioTools();  // create a GPIO object that controls GPIO4 (default

    GpioTools(std::string x); // create a GPIO object that controls GPIOx, where x is passed to this constructor


    /**
     * Set a gpio pin output or input
     * @param dir
     * @return
     */
    int export_gpio(); // exports GPIO


    int unexport_gpio(); // unexport GPIO
    int setdir_gpio(std::string dir); // Set GPIO Direction

    /**
     * Set the value of a gpio pin
     * @param val
     * @return
     */
    int setval_gpio(std::string val); // Set GPIO Value (putput pins)

    /**
     * Get the value of a gpio pin
     * @param val
     * @return
     */
    int getval_gpio(std::string& val); // Get GPIO Value (input/ output pins)

    /**
     * Getter for active gpio pin
     * @return
     */
    std::string get_gpionum(); // return the GPIO number associated with the instance of an object
private:
    std::string gpionum; // GPIO number associated with the instance of an object
};