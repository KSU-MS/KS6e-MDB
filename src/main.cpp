#include <Wire.h>
#include <CD4067BM96.h>

const int ANALOG_PIN = A0; // The analog pin where the temperature sensor is connected
const int NUM_CHANNELS = 16; // The number of channels on the CD4067BM96 multiplexer
const int MUX_ADDRESS = 0x20; // The I2C address of the CD4067BM96 multiplexer

<<<<<<< Updated upstream
CD4067BM96 mux(NUM_CHANNELS, MUX_ADDRESS);
=======
    Code for MDB. Not sure if it works lol.
    If I understand how the mux works then
    it should give a four pin analog output
    that is read and stored by the arduino

    Wrote something to output to SPI but I 
    cannot test any further at home other then
    just look at the output through a scope.

    Wrote my own Analog Read class because stupid
    Arduino would not let me call analogRead() 
    outside of the loop() function and I wanted
    my main() to look a certain way. 

    GET REKT ;)

*/


/*

    Found a possible SPI to CAN mega library.
    This is not mine.

    Need to implement and test. :)

*/


 

#include <Arduino.h>


#include "TempSensor.h"
#include "SPI_handle.h"
#include "MDB_Labels.h"




void setup()
{

    Serial.begin(9600);

    init_SPI();
>>>>>>> Stashed changes

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

<<<<<<< Updated upstream
  delay(1000);
=======

void loop()
{

    Battery_Module.updateTemp();

    send_SPI(MODULE_1_A, MODULE_1_B, Battery_Module.getTempModuleHALF1(), Battery_Module.getTempModuleHALF2());

    //delay(1000);

>>>>>>> Stashed changes
}
