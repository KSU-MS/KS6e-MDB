
/*
    Code for the MDB. Updated proper MUX function
    as well as getting the temperature of each cell
    sent through CAN. Hope you enjoy! :)

    - pieshower
*/
 
#include <Arduino.h>
#include "TempSensor.h"
#include "SPI_handle.h"
#include "MDB_Labels.h"
#include <Metro.h>

Metro sendSPI = Metro(20);
Metro updateTemps = Metro(10);

void setup()
{
    //Serial.begin(9600);
    init_SPI();
    //while (!Serial);

    DDRF &= ~(0x0F << 4);

}

void loop()
{
    // if(updateTemps.check()){
    //     Battery_Module.updateTemp();
    //     Battery_Module.updateMinTemp();
    //     Battery_Module.updateMaxTemp();
    // }
    // if(sendSPI.check()){
    //     send_SPI(MODULE_5_A, MODULE_5_B, Battery_Module.getTempModuleHALF1(), Battery_Module.getTempModuleHALF2());
    // }

    PORTF |= (CHANNEL6 << 4);

    int voltgeDawg = analogRead(TEMPIN);

    Serial.println(voltgeDawg);

    delay(1000);

}