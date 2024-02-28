

#include "TempSensor.h"
#include "MDB_labels.h"

int delaySettle = 40;
int delaySelect = 20;


// ---------------------------------------------------------------------
// Channel Identities in a array

uint8_t portPins[CHANNELS] = {CHANNEL0,  CHANNEL1,  CHANNEL2, CHANNEL3,
                              CHANNEL4,  CHANNEL5,  CHANNEL6, CHANNEL7,
                              CHANNEL8, CHANNEL9, CHANNEL10, CHANNEL11};

// ---------------------------------------------------------------------
// Enables PORTF as an output (constructor)

TempSensor::TempSensor(uint16_t _SHT3_Temperature_ = 0, uint16_t _SHT3_Humidity_ = 0)
{
    this->SHT3_Temperature = _SHT3_Temperature_;
       this->SHT3_Humidity =    _SHT3_Humidity_;
}

// ------------------------------------------------------------------------
// Updates the temps from each pins into an array

void TempSensor::updateTemp()
{
    // Starting
    #ifdef DEBUG
    Serial.println("lol starting update temp");
    #endif

    // Channel 0
    digitalWrite(MUXAPIN,0);
    digitalWrite(MUXBPIN,0);              
    digitalWrite(MUXCPIN,0);
    digitalWrite(MUXDPIN,0);    
    delay(delaySettle);
    this->Module_HALF1.senceTemp.temp[0] = map(analogRead(A7), 0, 1023, 0,255);
    #ifdef DEBUG
    Serial.print("1  :");
    Serial.println(map(analogRead(A7), 0, 1023, 0,255));
    #endif
    delay(delaySelect);
    
    // Channel 1
    digitalWrite(MUXAPIN,1);
    digitalWrite(MUXBPIN,0);              
    digitalWrite(MUXCPIN,0);
    digitalWrite(MUXDPIN,0);    
    delay(delaySettle);
    this->Module_HALF1.senceTemp.temp[1] = map(analogRead(A7), 0, 1023, 0,255);
    #ifdef DEBUG
    Serial.print("2  :");
    Serial.println(map(analogRead(A7), 0, 1023, 0,255));
    #endif
    delay(delaySelect);

    // Channel 2
    digitalWrite(MUXAPIN,0);
    digitalWrite(MUXBPIN,1);              
    digitalWrite(MUXCPIN,0);
    digitalWrite(MUXDPIN,0);    
    delay(delaySettle);
    this->Module_HALF1.senceTemp.temp[2] = map(analogRead(A7), 0, 1023, 0,255);
    #ifdef DEBUG
    Serial.print("3  :");
    Serial.println(map(analogRead(A7), 0, 1023, 0,255));
    #endif
    delay(delaySelect);    
    
    // Channel 3
    digitalWrite(MUXAPIN,1);
    digitalWrite(MUXBPIN,1);              
    digitalWrite(MUXCPIN,0);
    digitalWrite(MUXDPIN,0);    
    delay(delaySettle);
    this->Module_HALF1.senceTemp.temp[3] = map(analogRead(A7), 0, 1023, 0,255);
    #ifdef DEBUG
    Serial.print("4  :");
    Serial.println(map(analogRead(A7), 0, 1023, 0,255));
    #endif
    delay(delaySelect);    
    
    // Channel 4
    digitalWrite(MUXAPIN,0);
    digitalWrite(MUXBPIN,0);              
    digitalWrite(MUXCPIN,1);
    digitalWrite(MUXDPIN,0);    
    delay(delaySettle);
    this->Module_HALF1.senceTemp.temp[4] = map(analogRead(A7), 0, 1023, 0,255);
    #ifdef DEBUG
    Serial.print("5  :");
    Serial.println(map(analogRead(A7), 0, 1023, 0,255));
    #endif
    delay(delaySelect);

    // Channel 5
    digitalWrite(MUXAPIN,1);
    digitalWrite(MUXBPIN,0);              
    digitalWrite(MUXCPIN,1);
    digitalWrite(MUXDPIN,0);    
    delay(delaySettle);
    this->Module_HALF1.senceTemp.temp[5] = map(analogRead(A7), 0, 1023, 0,255);
    #ifdef DEBUG
    Serial.print("6  :");
    Serial.println(map(analogRead(A7), 0, 1023, 0,255));
    #endif
    delay(delaySelect);

    // Channel 6
    digitalWrite(MUXAPIN,0);
    digitalWrite(MUXBPIN,1);              
    digitalWrite(MUXCPIN,1);
    digitalWrite(MUXDPIN,0);    
    delay(delaySettle);
    this->Module_HALF2.senceTemp.temp[0] = map(analogRead(A7), 0, 1023, 0,255);
    #ifdef DEBUG
    Serial.print("7  :");
    Serial.println(map(analogRead(A7), 0, 1023, 0,255));
    #endif
    delay(delaySelect);

    // Channel 7
    digitalWrite(MUXAPIN,1);
    digitalWrite(MUXBPIN,1);              
    digitalWrite(MUXCPIN,1);
    digitalWrite(MUXDPIN,0);    
    delay(delaySettle);
    this->Module_HALF2.senceTemp.temp[1] = map(analogRead(A7), 0, 1023, 0,255);
    #ifdef DEBUG
    Serial.print("8  :");
    Serial.println(Module_HALF2.senceTemp.temp[7]);
    #endif
    delay(delaySelect);            

    // Channel 8
    digitalWrite(MUXAPIN,0);
    digitalWrite(MUXBPIN,0);              
    digitalWrite(MUXCPIN,0);
    digitalWrite(MUXDPIN,1);    
    delay(delaySettle);
    this->Module_HALF2.senceTemp.temp[2] = map(analogRead(A7), 0, 1023, 0,255);
    #ifdef DEBUG
    Serial.print("9  :");
    Serial.println(map(analogRead(A7), 0, 1023, 0,255));
    #endif
    delay(delaySelect);

    // Channel 9
    digitalWrite(MUXAPIN,1);
    digitalWrite(MUXBPIN,0);              
    digitalWrite(MUXCPIN,0);
    digitalWrite(MUXDPIN,1);    
    delay(delaySettle);
    this->Module_HALF2.senceTemp.temp[3] = map(analogRead(A7), 0, 1023, 0,255);
    #ifdef DEBUG
    Serial.print("10 :");
    Serial.println(map(analogRead(A7), 0, 1023, 0,255));
    #endif
    delay(delaySelect);

    // Channel 10
    digitalWrite(MUXAPIN,0);
    digitalWrite(MUXBPIN,1);              
    digitalWrite(MUXCPIN,0);
    digitalWrite(MUXDPIN,1);    
    delay(delaySettle);
    this->Module_HALF2.senceTemp.temp[4] = map(analogRead(A7), 0, 1023, 0,255);
    #ifdef DEBUG
    Serial.print("11 :");
    Serial.println(map(analogRead(A7), 0, 1023, 0,255));
    #endif
    delay(delaySelect);

    // Channel 11
    digitalWrite(MUXAPIN,1);
    digitalWrite(MUXBPIN,1);              
    digitalWrite(MUXCPIN,0);
    digitalWrite(MUXDPIN,1);    
    delay(delaySettle);
    this->Module_HALF2.senceTemp.temp[5] = map(analogRead(A7), 0, 1023, 0,255);
    #ifdef DEBUG
    Serial.print("12 :");
    Serial.println(map(analogRead(A7), 0, 1023, 0,255));
    #endif
    delay(delaySelect);

    // for (int CHANNEL = 0; CHANNEL < CHANNELS; CHANNEL++)
    // {
    //     if (CHANNEL < (CHANNELS / 2))
    //     {
    //         digitalWrite(MUXAPIN,CHANNEL1);
            
    //         digitalWrite(MUXAPIN,1);
    //         digitalWrite(MUXBPIN,1);              
    //         digitalWrite(MUXCPIN,1);
    //         digitalWrite(MUXDPIN,0);    

    //         delay(40);
    //         this->Module_HALF1.senceTemp.temp[CHANNEL] = map(analogRead(A7), 0, 1023, 0,255);
    //         delay(20);

    //         Serial.println(Module_HALF1.senceTemp.temp[CHANNEL]);
            
    //     }
    // }

    // for (int CHANNEL = 0; CHANNEL < CHANNELS; CHANNEL++)
    // {
    //     if (CHANNEL < (CHANNELS / 2))
    //     {
    //         PORTF |= (portPins[CHANNEL] << 4);
    //         delay(40);
    //         this->Module_HALF1.senceTemp.temp[CHANNEL] = analogRead(TEMPIN);
    //         delay(20);
    //         Serial.println(Module_HALF1.senceTemp.temp[CHANNEL]);
    //         PORTF &= ~(0x0F << 4);
    //     }
    //     else if (CHANNEL >= (CHANNELS / 2))
    //     {
    //         PORTF |= (portPins[CHANNEL] << 4);
    //         delay(40);
    //         this->Module_HALF2.senceTemp.temp[CHANNEL - (CHANNELS / 2)] = analogRead(TEMPIN);
    //         delay(20);
    //         Serial.println(this->Module_HALF2.senceTemp.temp[CHANNEL - (CHANNELS / 2)]);
    //         PORTF &= ~(0x0F << 4);
    //     }
        
    // }
}

// -------------------------------------------------------------------
// Updates the min and max temperatures for a Module half

void TempSensor::updateMinTemp()
{
    uint8_t minTempM1 = this->Module_HALF1.senceTemp.temp[CHANNEL0];
    uint8_t minTempM2 = this->Module_HALF2.senceTemp.temp[CHANNEL0];
    
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
    uint8_t maxTempM1 = this->Module_HALF1.senceTemp.temp[CHANNEL0];
    uint8_t maxTempM2 = this->Module_HALF2.senceTemp.temp[CHANNEL0];
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


void TempSensor::readSHT3()
{
    this->SHT3_Temperature = analogRead(SHT3_TEMPERATURE_PIN);
    this->SHT3_Humidity = analogRead(SHT3_HUMIDITY_PIN);

    this->convertSHT3data(this->SHT3_Temperature, this->SHT3_Humidity);
}


void TempSensor::convertSHT3data(uint16_t _SHT3_Temperature_, uint16_t _SHT3_Humidity_)
{
    // This gonna be cringe but yolo

    const double temperatureProportionalityFactor   = -66.875;
    const double HumidityProportionalityFacotFactor = -12.5; 

    double temperatureMeasured = (double)((double)(_SHT3_Temperature_ * 218.75) / 5);
    double humidityMeasured = (double)((double)(_SHT3_Humidity_ * 125) / 5);

    temperatureMeasured += temperatureProportionalityFactor;
    humidityMeasured += HumidityProportionalityFacotFactor;

    this->SHT3data[SHT3_TEMPERATURE] = temperatureMeasured;
    this->SHT3data[SHT3_HUMIDITY] = humidityMeasured;
}

uint64_t* TempSensor::getSHT3data()
{
    return this->SHT3data;
}