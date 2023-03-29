

#include "TempSensor.h"
#include "SPI_handle.h"



// ------------------------------------------------
// Initializes the SPI pins, mode, and CS

void init_SPI()
{


    SPI.begin();

    //SPI.beginTransaction(SPISettings(18000000, LSBFIRST, SPI_MODE0));

    //CAN_MCP2515(CHIPSELECT);

    CAN.begin(CAN_BPS_500K);


    pinMode(CHIPSELECT, OUTPUT);

    digitalWrite(CHIPSELECT, HIGH);

}


// -------------------------------------------------
// Sends through SPI. Maybe this works?

void send_SPI(uint32_t id, uint8_t buf[])
{

    CAN_Frame msg;

    msg.id = id;

    msg.extended = false;

    msg.length = 8;

    // Load buffer with Temperature array 

    for (uint8_t INDEX = 0; INDEX < CHANNELS; INDEX++)
    {

        msg.data[INDEX] = buf[INDEX];

    }

    msg.data[4] = batteryTemp.getAvgTemp();
    msg.data[5] = batteryTemp.getMinTemp();
    msg.data[6] = batteryTemp.getMaxTemp();

    digitalWrite(CHIPSELECT, LOW);

    CAN.write(msg);

    digitalWrite(CHIPSELECT, HIGH);

}

