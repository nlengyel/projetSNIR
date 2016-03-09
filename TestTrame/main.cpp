#include <SerialStream.h>
#include <SerialPort.h>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include "gestionTrames.h"


using namespace std ;



int main( int argc,char** argv  )
{
    SerialPort *toto = new SerialPort("/dev/ttyUSB0");
    gestionTrames *elem1= new gestionTrames(toto);
    elem1->configuration();
    elem1->test();

return 0;
}

    