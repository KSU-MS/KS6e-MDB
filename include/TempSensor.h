

/*

    ABCD corresponds to the average TEMP of 3 cells
    per letter, or input. Each pin is an analog voltage
    representation of the average temperature of 3 cells.

    Am I correct on this?

*/


#ifndef TEMPSENSOR_H
#define TEMPSENSOR_H

#include <Arduino.h>

// -------------------------------------------------
// Number of total channels

#define  CHANNELS  4

// --------------------------------------------------
// Each channel is the average temp of
// 3 packs

#define  CHANNEL1  0
#define  CHANNEL2  1
#define  CHANNEL3  2
#define  CHANNEL4  3

// --------------------------------------------------
// Just a more organized way of storing the temps

typedef struct temperature
{

    uint8_t temp[CHANNELS] = { 0 };

    uint8_t avgTemp = 0;

    uint8_t minTemp = 0;

    uint8_t maxTemp = 0;

} temperature;

// -------------------------------------
// Handles the temperature sensing

class TempSensor
{

private:

    temperature tempSensor;

public:

    TempSensor() {};

    ~TempSensor() {};

    void updateTemp();

    uint8_t *getTemp();

    void AvgTemp();

    uint8_t getAvgTemp();

    uint8_t getMinTemp();

    uint8_t getMaxTemp();

};


static TempSensor batteryTemp;


#endif

