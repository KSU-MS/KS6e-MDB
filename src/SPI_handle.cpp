

#include "TempSensor.h"
#include "SPI_handle.h"
#include "CAN_MCP2515.h"





// ------------------------------------------------
// Initializes the SPI pins, mode, and CS


void init_SPI()
{

    // pinMode(MUXMODE, OUTPUT);

    // CAN_MCP2515(CHIPSELECT);

    // CAN.begin(500000);

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

        // Serial.print("Data ");
        // Serial.print(INDEX);
        // Serial.print(": ");
        // Serial.println(msg.data[INDEX]);

    }

    CAN.write(msg);

}

