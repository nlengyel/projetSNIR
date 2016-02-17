#include <SerialStream.h>
#include <SerialPort.h>
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <stdio.h>
#include <string>


using namespace std ;


int main( int argc,char** argv  )
{
char  data[]={"00128B550100242913000000000010E00004D1"};
int checksum=0;
for(int i=0;i<40;i++){
    int recep=data[i];
    checksum+=0x80 ^ recep;
    //checksum+=checksum;
}
    cout<<checksum;
    return 0;
}
    
    