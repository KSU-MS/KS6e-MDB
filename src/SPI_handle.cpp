

#include "TempSensor.h"
#include "SPI_handle.h"



// ------------------------------------------------
// Initializes the SPI pins, mode, and CS

void init_SPI()
{

    SPI.begin();

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

    for (uint8_t INDEX = 0; INDEX < (CHANNELS / 3); INDEX++)
    {

        msg.data[INDEX] = buf[INDEX];

        Serial.print("Data ");
        Serial.print(INDEX);
        Serial.print(": ");
        Serial.print(msg.data[INDEX]);
        Serial.println();

    }

    msg.data[4] = batteryTemp.getAvgTemp();

    Serial.print("AvgTemp: ");
    Serial.print(msg.data[4]);
    Serial.println();

    msg.data[5] = batteryTemp.getMinTemp();
    msg.data[6] = batteryTemp.getMaxTemp();

    digitalWrite(CHIPSELECT, LOW);

    CAN.write(msg);

    digitalWrite(CHIPSELECT, HIGH);

}

