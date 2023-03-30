

#include <Arduino.h>
#include "TempSensor.h"
#include "MDB_Labels.h"



// ------------------------------------------------
// Channel Identities in a array

int portPins[CHANNELS] = {CHANNEL1, CHANNEL2, CHANNEL3, CHANNEL4, 
                          CHANNEL5, CHANNEL6, CHANNEL7, CHANNEL8,
                          CHANNEL9, CHANNEL10, CHANNEL11, CHANNEL12};


// ----------------------------------------------------------
// Enables PORTF as an output (constructor)

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

        if (CHANNEL < (CHANNELS / 2))
        {

            PORTF |= portPins[CHANNEL];

            delay(20);

            this->Module_HALF1.senceTemp.temp[CHANNEL] = analogRead(TEMPIN);

            delay(20);

            PORTF &= 0x00;

        }
        else if (CHANNEL >= (CHANNELS / 2))
        {

            PORTF |= portPins[CHANNEL];

            delay(20);

            this->Module_HALF2.senceTemp.temp[CHANNEL - (CHANNELS / 2)] = analogRead(TEMPIN);

            delay(20);

            PORTF &= 0x00;

        }

    }

}


// ---------------------------------------------------------
// Returns the temperatures for a Module half

uint8_t *TempSensor::getTempModuleHALF1()
{

    return this->Module_HALF1.senceTemp.temp;

}

uint8_t *TempSensor::getTempModuleHALF2()
{

    return this->Module_HALF2.senceTemp.temp;

}


// ---------------------------------------------------------
// Returns the min and max temperatures for a Module half

void TempSensor::minTempModuleHALF1()
{

    uint8_t minTemp = this->Module_HALF1.senceTemp.temp[CHANNEL1];

    for (int CHANNEL = 0; CHANNEL < (CHANNELS / 2); CHANNEL++)
    {

        if (this->Module_HALF1.senceTemp.temp[CHANNEL] < minTemp)
        {

            minTemp = this->Module_HALF1.senceTemp.temp[CHANNEL];

        }

    }

    this->Module_HALF1.senceTemp.minTemp = minTemp;

}


void TempSensor::minTempModuleHALF2()
{

    uint8_t minTemp = this->Module_HALF2.senceTemp.temp[CHANNEL1];

    for (int CHANNEL = 0; CHANNEL < (CHANNELS / 2); CHANNEL++)
    {

        if (this->Module_HALF2.senceTemp.temp[CHANNEL] < minTemp)
        {

            minTemp = this->Module_HALF2.senceTemp.temp[CHANNEL];

        }

    }

    this->Module_HALF2.senceTemp.minTemp = minTemp;

}


void TempSensor::maxTempModuleHALF1()
{

    uint8_t maxTemp = this->Module_HALF1.senceTemp.temp[CHANNEL1];

    for (int CHANNEL = 0; CHANNEL < (CHANNELS / 2); CHANNEL++)
    {

        if (this->Module_HALF1.senceTemp.temp[CHANNEL] > maxTemp)
        {

            maxTemp = this->Module_HALF1.senceTemp.temp[CHANNEL];

        }

    }

    this->Module_HALF1.senceTemp.maxTemp = maxTemp;

}


void TempSensor::maxTempModuleHALF2()
{

    uint8_t maxTemp = this->Module_HALF2.senceTemp.temp[CHANNEL1];

    for (int CHANNEL = 0; CHANNEL < (CHANNELS / 2); CHANNEL++)
    {

        if (this->Module_HALF2.senceTemp.temp[CHANNEL] > maxTemp)
        {

            maxTemp = this->Module_HALF2.senceTemp.temp[CHANNEL];

        }

    }

    this->Module_HALF2.senceTemp.maxTemp = maxTemp;

}


uint8_t TempSensor::getMinTempModuleHALF1()
{

    return this->Module_HALF1.senceTemp.minTemp;

}


uint8_t TempSensor::getMinTempModuleHALF2()
{

    return this->Module_HALF2.senceTemp.minTemp;

}


uint8_t TempSensor::getMaxTempModuleHALF1()
{

    return this->Module_HALF1.senceTemp.maxTemp;

}


uint8_t TempSensor::getMaxTempModuleHALF2()
{

    return this->Module_HALF2.senceTemp.maxTemp;

}


