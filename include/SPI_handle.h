

#ifndef SPI_HANDLE_H
#define SPI_HANDLE_H


#include "CAN_MCP2515.h"


#define CHIPSELECT 10


// ----------------------------------------------------
// Functions for SPI (Maybe they work lol)


void init_SPI();

void send_SPI(uint32_t id, uint8_t buf[]);

#endif
