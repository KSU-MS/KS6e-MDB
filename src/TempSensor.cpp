

#include <Arduino.h>
#include "TempSensor.h"
#include "MDB_Labels.h"


// ---------------------------------------------------------------------
// Channel Identities in a array

uint8_t portPins[CHANNELS] = {CHANNEL1,  CHANNEL2,  CHANNEL3, CHANNEL4, 
                              CHANNEL5,  CHANNEL6,  CHANNEL7, CHANNEL8,
                              CHANNEL9, CHANNEL10, CHANNEL11, CHANNEL12};


// ---------------------------------------------------------------------
// Enables PORTF as an output (constructor)

TempSensor::TempSensor()
{

    DDRF &= ~(0x0F << 4);

}



// ------------------------------------------------------------------------
// Updates the temps from each pins into an array

void TempSensor::updateTemp()
{

    for (int CHANNEL = 0; CHANNEL < CHANNELS; CHANNEL++)
    {

        if (CHANNEL < (CHANNELS / 2))
        {

            PORTF |= (portPins[CHANNEL] << 4);

            delay(40);

            this->Module_HALF1.senceTemp.temp[CHANNEL] = analogRead(TEMPIN);

            delay(20);

            PORTF &= ~(0x0F << 4);

        }
        else if (CHANNEL >= (CHANNELS / 2))
        {

            PORTF |= (portPins[CHANNEL] << 4);

            delay(40);

            this->Module_HALF2.senceTemp.temp[CHANNEL - (CHANNELS / 2)] = analogRead(TEMPIN);

            delay(20);

            PORTF &= ~(0x0F << 4);

        }

    }

}


// -------------------------------------------------------------------
// Updates the min and max temperatures for a Module half

void TempSensor::updateMinTemp()
{

    uint8_t minTempM1 = this->Module_HALF1.senceTemp.temp[CHANNEL1];
    uint8_t minTempM2 = this->Module_HALF2.senceTemp.temp[CHANNEL1];

    for (int CHANNEL = 0; CHANNEL < (CHANNELS / 2); CHANNEL++)
    {

        if (this->Module_HALF1.senceTemp.temp[CHANNEL] < minTempM1)
        {

            minTempM1 = this->Module_HALF1.senceTemp.temp[CHANNEL];

        }

    }

    for (int CHANNEL = 0; CHANNEL < (CHANNELS / 2); CHANNEL++)
    {

        if (this->Module_HALF2.senceTemp.temp[CHANNEL] < minTempM2)
        {

            minTempM2 = this->Module_HALF2.senceTemp.temp[CHANNEL];

        }

    }

    this->Module_HALF1.senceTemp.minTemp = minTempM1;
    this->Module_HALF2.senceTemp.minTemp = minTempM2;

}


void TempSensor::updateMaxTemp()
{

    uint8_t maxTempM1 = this->Module_HALF1.senceTemp.temp[CHANNEL1];
    uint8_t maxTempM2 = this->Module_HALF2.senceTemp.temp[CHANNEL1];

    for (int CHANNEL = 0; CHANNEL < (CHANNELS / 2); CHANNEL++)
    {

        if (this->Module_HALF1.senceTemp.temp[CHANNEL] > maxTempM1)
        {

            maxTempM1 = this->Module_HALF1.senceTemp.temp[CHANNEL];

        }

    }

    for (int CHANNEL = 0; CHANNEL < (CHANNELS / 2); CHANNEL++)
    {

        if (this->Module_HALF2.senceTemp.temp[CHANNEL] > maxTempM2)
        {

            maxTempM2 = this->Module_HALF2.senceTemp.temp[CHANNEL];

        }

    }

    this->Module_HALF1.senceTemp.maxTemp = maxTempM1;
    this->Module_HALF2.senceTemp.maxTemp = maxTempM2;

}


// -----------------------------------------------------------------
// Returns the temperatures for a Module half

uint8_t *TempSensor::getTempModuleHALF1()
{

    this->Module_HALF1.senceTemp.temp[6] = this->getMinTempModuleHALF1();
    this->Module_HALF1.senceTemp.temp[7] = this->getMaxTempModuleHALF1(); 

    return this->Module_HALF1.senceTemp.temp;

}


uint8_t *TempSensor::getTempModuleHALF2()
{

    this->Module_HALF2.senceTemp.temp[6] = this->getMinTempModuleHALF1();
    this->Module_HALF2.senceTemp.temp[7] = this->getMaxTempModuleHALF2();

    return this->Module_HALF2.senceTemp.temp;

}


// ------------------------------------------------------------------
// Returns the min and max of each module half

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










