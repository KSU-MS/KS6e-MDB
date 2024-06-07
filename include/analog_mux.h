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
            delay(1);
            readings[i] = analogRead(ANALOG_IN);
            delay(1);
            // Serial.print(i);
            // Serial.print(" ");
            // Serial.println(readings[i], HEX);
        }
    }
    mdb_data_packed_t pack_data()
    {
        mdb_data_packed_t data;
        data.channelZeroToFive = pack_10bit_data(&readings[0]);
        data.channelSixToEleven = pack_10bit_data(&readings[6]);
        return data;
    }
    uint16_t readings[12] = {0};
    uint16_t* unpack_10bit_data(uint64_t packed_data) {
        static uint16_t unpacked_data[6];
        uint64_t mask = 0x3FF; // 10 bits mask

        for (int i = 0; i < 6; i++) {
            unpacked_data[i] = (packed_data >> (i * 10)) & mask;
        }

        return unpacked_data;
    }

    void print_unpacked_data(uint64_t packed_data) {
        uint16_t* unpacked_data = unpack_10bit_data(packed_data);
        for (int i = 0; i < 6; i++) {
            Serial.print("Data[");
            Serial.print(i);
            Serial.print("]: ");
            Serial.println(unpacked_data[i]);
        }
    }
private:
    uint64_t pack_10bit_data(uint16_t *data)
    {
        uint64_t packed_data = 0;
        uint64_t mask = 0x3FF; // 10 bits mask

        for (int i = 0; i < 6; i++)
        {
            // uint64_t joe = (static_cast<uint64_t>(data[i]) << (i * 10));
            // uint32_t low = joe % 0xFFFFFFFF;
            // uint32_t high = (joe >> 32) % 0xFFFFFFFF;
            // Serial.print(data[i]);
            // Serial.print(" ");
            // Serial.println((low + high),HEX);
            uint64_t joe = 0;
            joe |= data[i];

            packed_data |= (joe << (i * 10));
        }
        print_unpacked_data(packed_data);
        uint32_t low = packed_data % 0xFFFFFFFF;
        uint32_t high = (packed_data >> 32) % 0xFFFFFFFF;
        // Serial.println((low + high),HEX);
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