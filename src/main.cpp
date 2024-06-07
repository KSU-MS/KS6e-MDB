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
#include <sht_sensor.h>

sht_s joe = sht_s(A8,A9);

Metro sendSPI = Metro(200);
Metro updateTemps = Metro(50);

void setup()
{
    Serial.begin(9600);
    init_SPI();
    pinMode(A7, INPUT);
    pinMode(A8, INPUT);
    pinMode(A9, INPUT);
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
        Serial.println("Updated Module #1 temps");
        Battery_Module.updateTemp();
        Battery_Module.updateMinTemp();
        Battery_Module.updateMaxTemp();
        joe.update();
    }
    if(sendSPI.check())
    {
        Serial.println("sendSPI");
        send_SPI(MODULE_1_A, MODULE_1_B, Battery_Module.getTempModuleHALF1(), Battery_Module.getTempModuleHALF2());
        send_CAN(MODULE_1_B+1,&joe.sht_data,sizeof(joe.sht_data));
    }   
}