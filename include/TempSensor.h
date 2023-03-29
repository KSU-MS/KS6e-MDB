

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

#define   CHANNEL1    B00000000
#define   CHANNEL2    B00000001
#define   CHANNEL3    B00000010
#define   CHANNEL4    B00000011
#define   CHANNEL5    B00000100
#define   CHANNEL6    B00000101
#define   CHANNEL7    B00000110
#define   CHANNEL8    B00000111
#define   CHANNEL9    B00001000
#define  CHANNEL10    B00001001
#define  CHANNEL11    B00001010
#define  CHANNEL12    B00001011

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

