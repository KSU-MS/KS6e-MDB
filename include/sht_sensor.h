#ifndef SHT_H
#define SHT_H
#include <Arduino.h>
struct sht_data_t
{
    int16_t temperature;
    int16_t humidity;
};
class sht_s
{
    public:
        sht_s(const int temperaturePin, const int humidityPin): tempPin(temperaturePin), humidPin(humidityPin){}
        void update()
        {
            tempReading = analogRead(tempPin);
            humidReading = analogRead(humidPin);
            // convert readings to a voltage
            float vt = 5.0 * static_cast<float>(tempReading)/1024;
            float vrh = 5.0 * static_cast<float>(humidReading)/1024;
            // convert voltages to temp/rh
            sht_data.temperature = static_cast<int16_t>(tempConversion(vt)*10);
            sht_data.humidity = static_cast<int16_t>(humidConversion(vrh)*10);
            Serial.print("temperature: ");
            Serial.println(sht_data.temperature/10);
            Serial.print("humidity: ");
            Serial.println(sht_data.humidity/10);
        }
        sht_data_t sht_data;
    private:
        const int tempPin;
        const int humidPin;
        uint16_t tempReading;
        uint16_t humidReading;
        float tempConversion(const float voltage)
        {
            float tempCelsius = -66.875+218.75*voltage/5.0;
            return tempCelsius;
        }
        float humidConversion(const float voltage){
            float humid = -12.5+125*voltage/5.0;
            return humid;
        }
};
#endif