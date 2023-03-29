

/*

    The MUX takes in 12 analog voltages and
    and outputs 1 analog voltage depending 
    on which channel you have selected.

*/


#ifndef TEMPSENSOR_H
#define TEMPSENSOR_H

#include <Arduino.h>

// -------------------------------------------------
// Number of total channels

#define  CHANNELS  12

// --------------------------------------------------
// Channels for each CELL in a MODULE

#define   CHANNEL1    0
#define   CHANNEL2    1
#define   CHANNEL3    2
#define   CHANNEL4    3
#define   CHANNEL5    4
#define   CHANNEL6    5
#define   CHANNEL7    6
#define   CHANNEL8    7
#define   CHANNEL9    8
#define  CHANNEL10    9
#define  CHANNEL11   10
#define  CHANNEL12   11

#define     TEMPIN    6

// --------------------------------------------------
// Just a more organized way of storing the temps

typedef struct temperature
{

    uint8_t temp[CHANNELS / 2] = { 0 };

    uint8_t minTemp = 0;

    uint8_t maxTemp = 0;

} temperature;

typedef struct module
{

    temperature senceTemp;

} module;

// -------------------------------------
// Handles the temperature sensing

class TempSensor
{

private:

    module Module_HALF1;
    module Module_HALF2;

public:

    TempSensor();

    ~TempSensor() {};

    void updateTemp();

    uint8_t *getTempModuleHALF1();
    
    uint8_t *getTempModuleHALF2();

    uint8_t getMinTempModuleHALF1();

    uint8_t getMinTempModuleHALF2();

    uint8_t getMaxTempModuleHALF1();

    uint8_t getMaxTempModuleHALF2();

};


static TempSensor Battery_Module;


#endif

