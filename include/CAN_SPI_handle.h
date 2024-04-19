#ifndef CAN_SPI_HANDLE_H
#define CAN_SPI_HANDLE_H

#include "CAN_MCP2515.h"

#define CHIPSELECT 10

// ----------------------------------------------------
// Functions for SPI
void init_SPI();
void send_CAN(uint32_t id, void* buf,const size_t size);
// #define DEBUG


#endif
