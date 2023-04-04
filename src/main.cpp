
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


void setup()
{

    //Serial.begin(9600);

    init_SPI();

    //while (!Serial);
    
}


void loop()
{

    Battery_Module.updateTemp();
    
    Battery_Module.updateMinTemp();
    Battery_Module.updateMaxTemp();

    delay(50);

    send_SPI(MODULE_1_A, MODULE_1_B, Battery_Module.getTempModuleHALF1(), Battery_Module.getTempModuleHALF2());

}


