/*
CD4067BM96.h - Library for interfacing with CD4067BM96 multiplexer.
Created by Dreamcat4, September 29, 2017.
Released into the public domain.
*/

#ifndef CD4067BM96_h
#define CD4067BM96_h

#include <Wire.h>
#include <Arduino.h>

class CD4067BM96 {
  public:
    CD4067BM96(uint8_t numChannels, uint8_t address);
    void begin();
    void setChannel(uint8_t channel);
    int read();
  private:
    uint8_t _numChannels;
    uint8_t _address;
    uint8_t _channel;
};

#endif
