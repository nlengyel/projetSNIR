#include <SerialStream.h>
#include <SerialPort.h>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <stdio.h>
#include <string>
#include "GestionTrames.h"


using namespace std ;



int main(int argc, char** argv)
{
    SerialPort *toto = new SerialPort("/dev/ttyUSB0");
    GestionTrames* elem1= new GestionTrames(toto);
    string donnees1 ="00128B550100242913000000000010E00004D1";
    elem1->configuration();
    elem1->envoyerTrames(donnees1);

return 0;
}

    