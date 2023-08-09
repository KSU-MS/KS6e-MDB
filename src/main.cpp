/*
    Code for the MDB. Updated proper MUX function
    as well as getting the temperature of each cell
    sent through CAN. Hope you enjoy! :)

    - pieshower
*/
 

#include "TempSensor.h"
#include "CAN_SPI_handle.h"
#include "MDB_labels.h"
#include <Metro.h>

Metro sendSPI = Metro(200);
Metro updateTemps = Metro(50);

void setup()
{
    Serial.begin(9600);
    init_SPI();
    pinMode(A7, INPUT);
    pinMode(MUXAPIN, OUTPUT);
    pinMode(MUXBPIN, OUTPUT);
    pinMode(MUXCPIN, OUTPUT);
    pinMode(MUXDPIN, OUTPUT);
    //while (!Serial);
}

void loop()
{
    if(updateTemps.check())
    {   
        Serial.println("updated temp");
        Battery_Module.updateTemp();
        Battery_Module.updateMinTemp();
        Battery_Module.updateMaxTemp();
    }
    if(sendSPI.check())
    {
        Serial.println("sendSPI");
        send_SPI(MODULE_4_A, MODULE_4_B, Battery_Module.getTempModuleHALF1(), Battery_Module.getTempModuleHALF2());
    }
}