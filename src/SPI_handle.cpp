

#include "TempSensor.h"
#include "SPI_handle.h"


// ------------------------------------------------
// Initializes the SPI pins, mode, and CS

void init_SPI()
{

    SPI.begin();

    SPI.beginTransaction(SPISettings(9600, LSBFIRST, SPI_MODE0));

    pinMode(CHIPSELECT, OUTPUT);

}


// -------------------------------------------------
// Sends through SPI. Maybe this works?

void send_SPI(uint32_t id, uint8_t buf[])
{

    SPI_message_t msg;

    uint64_t buffer;

    msg.id |= id;



    // Load buffer with Temperature array 

    for (uint8_t INDEX = 0; INDEX < sizeof(buf); INDEX++)
    {

        msg.buf[INDEX] = buf[INDEX];

    }

    for (int INDEX = msg.len; INDEX > 0; INDEX--)
    {

        buffer |= (msg.buf[INDEX] << ((INDEX * 8) - 8));

    }



    // SPI.beginTransaction(SPISettings(9600, LSBFIRST, SPI_MODE0));

    // enable CAN controller to recieve data

    digitalWrite(CHIPSELECT, LOW);

    // transfer data


    // for (int i = 0; i < msg.len; i++)
    // {

    //     Serial.print("buffer ");
    //     Serial.print(i);
    //     Serial.print(": ");
    //     Serial.println(msg.buf[i]);

    // }

    // transfer identity

    SPI.transfer(msg.buf, msg.len);

    SPI.transfer(msg.len);
    SPI.transfer(msg.id);

    SPI.endTransaction();

    digitalWrite(CHIPSELECT, HIGH);

}

