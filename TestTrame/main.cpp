#include <SerialStream.h>
#include <SerialPort.h>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <stdio.h>
using namespace LibSerial;

int main( int argc,char** argv  )
{
    //overture port serie 
    //SerialStream transTrame1;
    SerialPort transTrame1("/dev/ttyUSB0");
    //transTrame1.Open("/dev/ttyUSB0");
    //setup bauds
    transTrame1.SetBaudRate(SerialPort::BAUD_19200);
    //setup taille
    transTrame1.SetCharSize(SerialPort::CHAR_SIZE_8);
    //setup parité
    transTrame1.SetParity(SerialPort::PARITY_NONE);
    //setup bit de stop
    transTrame1.SetNumOfStopBits(SerialPort::STOP_BITS_1);
    //setup controle d'echange
    transTrame1.SetFlowControl(SerialPort::FLOW_CONTROL_NONE);
    //std::cout<<"config ok"<<std::endl;
    //std::cout<<"envoie de trame test"<<std::endl;
    //transTrame1.w <<0x03 << 0xFF<<0xFF<<0xFF<<0x0A<<0x0A;
    transTrame1.Write("00128B550100242913000000000010E00004D1\r\n");
   // transTrame1<<0xF2<<0x0D;
    transTrame1.Close();
    return EXIT_SUCCESS ;
}