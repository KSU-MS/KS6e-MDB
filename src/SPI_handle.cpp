

#include "TempSensor.h"
#include "SPI_handle.h"


// ------------------------------------------------
// Initializes the SPI pins, CAN, and CS

void init_SPI()
{

    SPI.begin();

    CAN.begin(CAN_BPS_500K);

}


// -------------------------------------------------
// Sends through SPI.

void send_SPI(uint32_t id_1, uint32_t id_2, uint8_t buf_1[], uint8_t buf_2[])
{

    CAN_Frame msg_1;
    CAN_Frame msg_2;

    msg_1.id = id_1;
    msg_2.id = id_2;

    msg_1.extended = false;
    msg_2.extended = false;

    msg_1.length = 8;
    msg_2.length = 8;


    // Load buffers with Temperature array 

    for (uint8_t INDEX = 0; INDEX < (CHANNELS - 4); INDEX++)
    {

        msg_1.data[INDEX] = buf_1[INDEX];
        msg_2.data[INDEX] = buf_2[INDEX];

    }

#if DEBUG

    for (uint8_t INDEX = 0; INDEX < (CHANNELS / 2); INDEX++)
    {

        Serial.print("Data1 ");
        Serial.print(INDEX);
        Serial.print(": ");
        Serial.print(msg_1.data[INDEX]);
        Serial.println();

    }

    Serial.print("Min 1: ");
    Serial.println(msg_1.data[6]);

    Serial.print("Max 1: ");
    Serial.println(msg_1.data[7]);

    for (uint8_t INDEX = 0; INDEX < (CHANNELS / 2); INDEX++)
    {

        Serial.print("Data2 ");
        Serial.print(INDEX);
        Serial.print(": ");
        Serial.print(msg_2.data[INDEX]);
        Serial.println();

    }

    Serial.print("Min 2: ");
    Serial.println(msg_2.data[6]);

    Serial.print("Max 2: ");
    Serial.println(msg_2.data[7]);

#endif


    // Send the messages through SPI



    CAN.write(msg_1);

    delay(10);

    CAN.write(msg_2);

}

