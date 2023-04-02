

#ifndef SPI_HANDLE_H
#define SPI_HANDLE_H


#include "CAN_MCP2515.h"


#define CHIPSELECT 10


// ----------------------------------------------------
// Functions for SPI

void init_SPI();

void send_SPI(uint32_t id_1, uint32_t id_2, uint8_t buf_1[], uint8_t buf_2[]);

#define DEBUG 0


#endif
