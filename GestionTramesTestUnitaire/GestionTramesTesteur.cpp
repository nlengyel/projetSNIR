/* 
 * File:   GestionTramesTesteur.cpp
 * Author: eleve
 *
 * Created on 10 mars 2016, 19:32
 */
#include "../GestionTrame/GestionTrames.h"
#include <cstdlib>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    SerialPort *testSP = new SerialPort("/dev/ttyUSB0");
    GestionTrames* test= new GestionTrames(testSP);
    test->setIdentifiant("00128B");
    test->setSoft("55");
    test->setType("01");
    test->setCoup("0");
    test->setEtat("0");
    test->setTPile("24");
    test->setTCapa("29");
    test->setTemp("13");
    test->setDHoraire("0000");
    test->setCompInhib("0000");
    test->setCompFuite("0000");
    test->setCompAbs("10E0");
    test->setIndex("0004D1");
    test->creerDonnees();
    test->configuration();
    string recepteur = test->getDonneesTrame();
    test->envoyerTrames(recepteur);
    
    return 0;
}

