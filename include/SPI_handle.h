

#ifndef SPI_HANDLE_H
#define SPI_HANDLE_H

#include <SPI.h>

#define CHIPSELECT 9

// ---------------------------------------------------
// Just a more organized way of storing the messages

typedef struct SPI_message_t
{

    uint32_t id = 0;        // can identifier

    uint16_t timestamp = 0; // FlexCAN time when message arrived

    uint8_t idhit = 0;      // filter that id came from

    struct
    {

        bool extended = 0; // identifier is extended (29-bit)

        bool remote = 0;   // remote transmission request packet type

        bool overrun = 0;  // message overrun

        bool reserved = 0;

    } flags;

    uint8_t len = 8; // length of data

    uint8_t buf[8] = {0}; // data

    int8_t mb = 0; // used to identify mailbox reception

    uint8_t bus = 0; // used to identify where the message came from when events() is used.
    
    bool seq = 0;    // sequential frames

} SPI_message_t;


// ----------------------------------------------------
// Functions for SPI (Maybe they work lol)

void init_SPI();

void send_SPI(uint32_t id, uint8_t buf[]);

#endif
