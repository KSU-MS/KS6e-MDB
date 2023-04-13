/*
    The MUX takes in 12 analog voltages and
    and outputs 1 analog voltage depending 
    on which channel you have selected.
*/

#ifndef TEMPSENSOR_H
#define TEMPSENSOR_H

#define DEBUG

#include <Arduino.h>

// -------------------------------------------------
// Number of total channels
#define   CHANNELS    12

// --------------------------------------------------
// Channels for each CELL in a MODULE
#define   CHANNEL0    B0000
#define   CHANNEL1    B1000
#define   CHANNEL2    B0100
#define   CHANNEL3    B1100
#define   CHANNEL4    B0010
#define   CHANNEL5    B1010
#define   CHANNEL6    B0110
#define   CHANNEL7    B1110
#define   CHANNEL8    B0001
#define   CHANNEL9    B1001
#define  CHANNEL10    B0101
#define  CHANNEL11    B1101

#define MUXAPIN 18
#define MUXBPIN 19
#define MUXCPIN 20
#define MUXDPIN 21  


#define TEMPIN 6


// --------------------------------------------------
// Just a more organized way of storing the temps
typedef struct temperature
{
    uint8_t temp[8] = { 0 };
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
    void updateMinTemp();
    void updateMaxTemp();
    uint8_t *getTempModuleHALF1();
    uint8_t *getTempModuleHALF2();
    uint8_t getMinTempModuleHALF1();
    uint8_t getMinTempModuleHALF2();
    uint8_t getMaxTempModuleHALF1();
    uint8_t getMaxTempModuleHALF2();
};

static TempSensor Battery_Module;

#endif