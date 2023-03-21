/*
CD4067BM96.cpp - Library for interfacing with CD4067BM96 multiplexer.
Created by Dreamcat4, September 29, 2017.
Released into the public domain.
*/

#include "CD4067BM96.h"

CD4067BM96::CD4067BM96(uint8_t numChannels, uint8_t address) {
  _numChannels = numChannels;
  _address = address;
}

void CD4067BM96::begin() {
  Wire.begin();
}

void CD4067BM96::setChannel(uint8_t channel) {
  if (channel >= _numChannels) {
    channel = _numChannels - 1;
  }
  _channel = channel;
  Wire.beginTransmission(_address);
  Wire.write(1 << _channel);
  Wire.endTransmission();
}

int CD4067BM96::read() {
  Wire.requestFrom(_address, 1);
  if (Wire.available()) {
    return Wire.read();
  } else {
    return -1;
  }
}
