

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

#define   CHANNELS   12

// --------------------------------------------------
// Channels for each CELL in a MODULE

#define   CHANNEL1    B0000
#define   CHANNEL2    B0001
#define   CHANNEL3    B0010
#define   CHANNEL4    B0011
#define   CHANNEL5    B0100
#define   CHANNEL6    B0101
#define   CHANNEL7    B0110
#define   CHANNEL8    B0111
#define   CHANNEL9    B1000
#define  CHANNEL10    B1001
#define  CHANNEL11    B1010
#define  CHANNEL12    B1011

#define     TEMPIN    A7

// --------------------------------------------------
// Just a more organized way of storing the temps

typedef struct temperature
{

    uint8_t temp[CHANNELS - 4] = { 0 };

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

    void updateMinTemp();

    void updateMaxTemp();



 
};


static TempSensor Battery_Module;


#endif

