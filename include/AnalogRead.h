

#ifndef AnalogRead_h
#define AnalogRead_h


#include <avr/io.h>


// --------------------------------------------
// Analog read class because arduino stupid

class AnalogRead
{
public:

    AnalogRead(); 

    ~AnalogRead() {};

    int read(int pin);
   
};


#endif

