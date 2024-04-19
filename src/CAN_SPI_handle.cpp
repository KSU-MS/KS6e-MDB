#ifndef CAN_SPI_HANDLE
#define CAN_SPI_HANDLE
#include "CAN_SPI_handle.h"
#include <stdint.h>
// ------------------------------------------------
// Initializes the SPI pins, CAN, and CS
void init_SPI()
{
    SPI.begin();
    CAN.begin(CAN_BPS_500K);
}

// -------------------------------------------------

void send_CAN(uint32_t id, void* buf,const size_t size)
{
    CAN_Frame msg;
    msg.id = id;
    msg.length = size;
    memcpy(msg.data,buf,size);
    CAN.write(msg);
}
#endif