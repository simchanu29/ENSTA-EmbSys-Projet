//
// Created by tag on 03/01/17.
//

#pragma once

#include <string>

/**
 * Toolbox for GPIO handling for Raspberry Pi
 */
class GpioTools
{
public:
    /**
     * FR : Constructeur basique de GpioTools
     * EN : Create a GPIO object that controls GPIO4 (default)
     */
    GpioTools();

    /**
     * Create a GPIO object that controls GPIOx, where x is passed to this constructor
     * @param x
     */
    GpioTools(std::string x);


    /**
     * Exports GPIO
     * @param dir
     * @return
     */
    int export_gpio();

    /**
     * unexport GPIO
     * @return
     */
    int unexport_gpio();

    /**
     * Set GPIO Direction
     * @param dir
     * @return
     */
    int setdir_gpio(std::string dir);

    /**
     * Set GPIO Value (output pins)
     * @param val
     * @return
     */
    int setval_gpio(std::string val);

    /**
     * Get GPIO Value (input/ output pins)
     * @param val
     * @return
     */
    int getval_gpio(std::string& val);

    /**
     * Getter for active gpio pin
     * Return the GPIO number associated with the instance of an object
     * @return
     */
    std::string get_gpionum(); //
private:
    /**
     * GPIO number associated with the instance of an object
     */
    std::string gpionum;
};