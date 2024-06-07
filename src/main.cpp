/*
    Code for the MDB. Updated proper MUX function
    as well as getting the temperature of each cell
    sent through CAN. Hope you enjoy! :)

    - pieshower
*/
 

#include "CAN_SPI_handle.h"
#include "MDB_labels.h"
#include <Metro.h>
#include <sht_sensor.h>
#include "analog_mux.h"
sht_s joe = sht_s(A8,A9);
analog_mux mux;
Metro sendSPI = Metro(200);
Metro updateTemps = Metro(50);

void setup()
{
    // Serial.begin(9600);
    init_SPI();
    pinMode(A7, INPUT);
    pinMode(A8, INPUT);
    pinMode(A9, INPUT);
    pinMode(MUXAPIN, OUTPUT);
    pinMode(MUXBPIN, OUTPUT);
    pinMode(MUXCPIN, OUTPUT);
    pinMode(MUXDPIN, OUTPUT);
    // pinMode(LED_BUILTIN,OUTPUT);
    // while (!Serial);
}

void loop()
{
    if(updateTemps.check())
    {   
        // Serial.println("Updated Module #1 temps");
        // Battery_Module.updateTemp();
        // Battery_Module.updateMinTemp();
        // Battery_Module.updateMaxTemp();
        mux.read_all_channels();
        joe.update();
    }
    if(sendSPI.check())
    {
        // Serial.println("sendSPI");
        // send_SPI(MODULE_1_A, MODULE_1_B, Battery_Module.getTempModuleHALF1(), Battery_Module.getTempModuleHALF2());
        digitalWrite(LED_BUILTIN,!(digitalRead(LED_BUILTIN)));
        mdb_data_packed_t data = mux.pack_data();
        send_CAN(MODULE_6_A,&data.channelZeroToFive,sizeof(data.channelZeroToFive));
        send_CAN(MODULE_6_B,&data.channelSixToEleven,sizeof(data.channelSixToEleven));
        send_CAN(MODULE_6_B+1,&joe.sht_data,sizeof(joe.sht_data));
    }   
}