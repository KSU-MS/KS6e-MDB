#include <Wire.h>
#include <CD4067BM96.h>

const int ANALOG_PIN = A0; // The analog pin where the temperature sensor is connected
const int NUM_CHANNELS = 16; // The number of channels on the CD4067BM96 multiplexer
const int MUX_ADDRESS = 0x20; // The I2C address of the CD4067BM96 multiplexer

CD4067BM96 mux(NUM_CHANNELS, MUX_ADDRESS);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mux.begin();
}

void loop() {
  // Read the analog temperature value from the sensor
  int analogValue = analogRead(ANALOG_PIN);
  
  // Select the channel on the multiplexer based on the analog value
  int channel = analogValue / (1024 / NUM_CHANNELS);
  mux.setChannel(channel);
  
  // Read the digital value from the selected channel
  int digitalValue = mux.read();
  
  // Print the analog and digital values
  Serial.print("Analog Value: ");
  Serial.print(analogValue);
  Serial.print(", Digital Value: ");
  Serial.println(digitalValue);

  delay(1000);
}
