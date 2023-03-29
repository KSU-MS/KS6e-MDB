
#include <Arduino.h>
#include "TempSensor.h"
#include "MDB_Labels.h"



// ------------------------------------------------
// Input pins for the NANO

//                 A   B   C   D
 int tempPins[] = {A0, A1, A2, A3};




// ----------------------------------------------------
// Updates the temps from each pins into an array

void TempSensor::updateTemp()
{

    for (uint8_t CHANNEL = 0; CHANNEL < CHANNELS; CHANNEL++)
    {

        this->tempSensor.temp[CHANNEL] = analogRead(tempPins[CHANNEL]);

        Serial.print("Data ");
        Serial.print(CHANNEL);
        Serial.print(": ");
        Serial.println(this->tempSensor.temp[CHANNEL]);

    }

}


// ----------------------------------------------------
// Returns the temperture of a channel (A B C D)

uint8_t *TempSensor::getTemp()
{

    return this->tempSensor.temp;

}


// ------------------------------------------------------
// Averages all channels into one temperature reading

void TempSensor::AvgTemp()
{

    uint8_t avgerageTemperature = 0;

    for (int CHANNEL = 0; CHANNEL < CHANNELS; CHANNEL++)
    {

        avgerageTemperature += this->tempSensor.temp[CHANNEL];

    }

    this->tempSensor.avgTemp = avgerageTemperature / CHANNELS;

}


// ------------------------------------------------------
// Returns an array of average temperatures

uint8_t TempSensor::getAvgTemp()
{

    return this->tempSensor.avgTemp;

}



uint8_t TempSensor::getMinTemp()
{

    return 0;

}



uint8_t TempSensor::getMaxTemp()
{

    return 0;

}
