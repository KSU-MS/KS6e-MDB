
/*

    Code for MDB. Not sure if it works lol.
    If I understand how the mux works then
    it should give a four pin analog output
    that is read and stored by the arduino

    Wrote something to output to SPI but I 
    cannot test any further at home other then
    just look at the output through a scope.

    Wrote my own Analog Read class because stupid
    Arduino would not let me call analogRead() 
    outside of the loop() function and I wanted
    my main() to look a certain way. 

    GET REKT ;)

*/


/*

    Found a possible SPI to CAN mega library.
    This is not mine.

    Need to implement and test. :)

*/




#include <Arduino.h>

#include "TempSensor.h"
#include "SPI_handle.h"
#include "MDB_Labels.h"


TempSensor batteryTemp;


int main(void)
{

    Serial.begin(9600);

    init_SPI();

    while(true)
    {

        batteryTemp.updateTemp();
        batteryTemp.AvgTemp();

        send_SPI(CELL_1, batteryTemp.getAvgTemp());

    }

}



