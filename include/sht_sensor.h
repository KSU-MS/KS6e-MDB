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
            sht_data.temperature = tempConversion(vt);
            sht_data.humidity = humidConversion(vrh);
        }
        sht_data_t sht_data;
    private:
        const int tempPin;
        const int humidPin;
        uint16_t tempReading;
        uint16_t humidReading;
        int16_t tempConversion(const float voltage)
        {
            float tempCelsius = -66.875+218.75*voltage/5.0;
            return static_cast<int16_t>(tempCelsius*100);
        }
        int16_t humidConversion(const float voltage){
            float humid = -12.5+125*voltage/5.0;
            return static_cast<int16_t>(humid*100);
        }
};
#endif