#ifndef ANALOG_MUX_H
#define ANALOG_MUX_H
#include <Arduino.h>
#include <pindefs.h>
struct mdb_data_packed_t
{
    uint64_t channelZeroToFive;
    uint64_t channelSixToEleven;
};
class analog_mux
{
public:
    void read_all_channels()
    {
        for (int i = 0; i < sizeof(readings) / sizeof(readings[0]); i++)
        {
            set_channel(i);
            readings[i] = analogRead(ANALOG_IN);
        }
    }
    mdb_data_packed_t pack_data()
    {
        mdb_data_packed_t data;
        data.channelZeroToFive = pack_10bit_data(&readings[0]);
        data.channelZeroToFive = pack_10bit_data(&readings[6]);
        return data;
    }
    uint16_t readings[12] = {0};

private:
    uint64_t pack_10bit_data(uint16_t *data)
    {
        uint64_t packed_data = 0;
        uint64_t mask = 0x3FF; // 10 bits mask

        for (int i = 0; i < 6; ++i)
        {
            packed_data |= (static_cast<uint64_t>(data[i] & mask) << (i * 10));
        }

        return packed_data;
    }
    void set_channel(uint8_t channel)
    {
        bool led_a_high = channel & 0b0001;
        bool led_b_high = channel & 0b0010;
        bool led_c_high = channel & 0b0100;
        bool led_d_high = channel & 0b1000;
#if DEBUG
        Serial.printf("SEVEN SEGMENT INPUT: %d A: %d B: %d C: %d D: %d\n", channel, led_a_high, led_b_high, led_c_high, led_d_high);
#endif
        digitalWrite(MUXAPIN, led_a_high);
        digitalWrite(MUXBPIN, led_b_high);
        digitalWrite(MUXCPIN, led_c_high);
        digitalWrite(MUXDPIN, led_d_high);
        delayMicroseconds(200);
        // settle time
    }
};

#endif