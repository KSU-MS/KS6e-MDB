
#include <Arduino.h>
#include "TempSensor.h"
#include "MDB_Labels.h"



// ------------------------------------------------
// Channel Identities in a array

int portPins[CHANNELS] = {CHANNEL1, CHANNEL2, CHANNEL3, CHANNEL4, 
                          CHANNEL5, CHANNEL6, CHANNEL7, CHANNEL8,
                          CHANNEL9, CHANNEL10, CHANNEL11, CHANNEL12};

// ----------------------------------------------------------
// Enables PORTF as an output

TempSensor::TempSensor()
{

    DDRF = 0x00;

}


// ----------------------------------------------------
// Updates the temps from each pins into an array

void TempSensor::updateTemp()
{

    for (uint8_t CHANNEL = 0; CHANNEL < CHANNELS; CHANNEL++)
    {

        // Sets the CHANNEL select for PORTF
        PORTF |= portPins[CHANNEL];

        // Gets a temp reading 
        this->tempSensor.temp[CHANNEL] = analogRead(TEMPIN);

        Serial.print("Channel ");
        Serial.print(CHANNEL);
        Serial.print(": ");
        Serial.print(this->tempSensor.temp[CHANNEL]);
        Serial.println();
        
        // Clears PORTF with 0's
        PORTF &= 0x00;

    }

}


// ----------------------------------------------------
// Returns the temperture of a channel (A B C D)

uint8_t *TempSensor::getTemp()
{

    return this->tempSensor.avgThreeTemp;

}


// ------------------------------------------------------
// Returns an array of average temperatures

uint8_t TempSensor::getAvgTemp()
{

    return this->tempSensor.avgTemp;

}


// ------------------------------------------------------
// Averages all channels into one temperature reading

void TempSensor::AvgTemp()
{

    int averageTemperature = 0;

    this->tempSensor.avgThreeTemp[0] = 
        ((this->tempSensor.temp[CHANNEL1] + this->tempSensor.temp[CHANNEL2] + this->tempSensor.temp[CHANNEL3])) / 3;

    this->tempSensor.avgThreeTemp[1] = 
        ((this->tempSensor.temp[CHANNEL4] + this->tempSensor.temp[CHANNEL5] + this->tempSensor.temp[CHANNEL6])) / 3;

    this->tempSensor.avgThreeTemp[2] = 
        ((this->tempSensor.temp[CHANNEL7] + this->tempSensor.temp[CHANNEL8] + this->tempSensor.temp[CHANNEL9])) / 3;

    this->tempSensor.avgThreeTemp[3] = 
        ((this->tempSensor.temp[CHANNEL10] + this->tempSensor.temp[CHANNEL11] + this->tempSensor.temp[CHANNEL12])) / 3;

    // this->tempSensor.avgTemp = 
    //     (this->tempSensor.avgThreeTemp[0] + this->tempSensor.avgThreeTemp[1]
    //     + this->tempSensor.avgThreeTemp[2] + this->tempSensor.avgThreeTemp[3]) / 4;

    for (int INDEX = 0; INDEX < (CHANNELS / 3); INDEX++)
    {

        averageTemperature += this->tempSensor.avgThreeTemp[INDEX];

    }

    averageTemperature = averageTemperature / (CHANNELS / 3);

    this->tempSensor.avgTemp = averageTemperature;

    Serial.print("Average Temp 1: ");
    //Serial.print(this->tempSensor.avgTemp);
    Serial.print(this->getAvgTemp());
    Serial.println();

}

uint8_t TempSensor::getMinTemp()
{

    return 0;

}



uint8_t TempSensor::getMaxTemp()
{

    return 0;

}
