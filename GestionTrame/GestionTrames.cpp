/* 
 * File:   gestionTrames.cpp
 * Author: nlengyel
 * 
 * Created on 17 février 2016, 11:15
 */
#include <SerialStream.h>
#include <SerialPort.h>
#include "GestionTrames.h"
#include <string>
#include <string.h>
using namespace LibSerial;

GestionTrames::GestionTrames() {}
GestionTrames::GestionTrames(SerialPort *inst){
    portS=inst;
}
GestionTrames::~GestionTrames() {
    //fermeture de la liaison
    portS->Close();
}
/*definition des attributs*/
int GestionTrames::tete[]= {0x03,0xFF,0xFF,0xFF,0x0A,0x0A};
int GestionTrames::fin={0x0D};
//getter DonneesTrame
string GestionTrames::getDonneesTrame(){
    return DonneesTrame;
}
char GestionTrames::getChecksum(){
    return checksum;
}
/*getter en hexadecimal*/
std::string GestionTrames::getIdentifiant() {
    return Identifiant;
}

std::string GestionTrames::getSoft() {
    return Soft;
}

std::string GestionTrames::getType() {
    return Type;
}

std::string GestionTrames::getCoup() {
    return Coup;
}

std::string GestionTrames::getEtat() {
    return Etat;
}

std::string GestionTrames::getTPile() {
    return TPile;
}

std::string GestionTrames::getTCapa() {
    return TCapa;
}

std::string GestionTrames::getTemp() {
    return Temp;
}

std::string GestionTrames::getDHoraire() {
    return DHoraire;
}

std::string GestionTrames::getCompInhib() {
    return CompInhib;
}

std::string GestionTrames::getCompFuite() {
    return CompFuite;
}

std::string GestionTrames::getCompAbs() {
    return CompAbs;
}

std::string GestionTrames::getIndex() {
    return Index;
}

/*setter en hexadecimal*/
void GestionTrames::setIdentifiant(string id) {
    Identifiant = id;
}

void GestionTrames::setSoft(string soft) {
    Soft = soft;
}

void GestionTrames::setType(string type) {
    Type = type;
}

void GestionTrames::setCoup(string coup) {
    Coup = coup;
}

void GestionTrames::setEtat(string etat) {
    Etat = etat;
}

void GestionTrames::setTPile(string tensionPile) {
    TPile = tensionPile;
}

void GestionTrames::setTCapa(string tensionCapa) {
    TCapa = tensionCapa;
}

void GestionTrames::setTemp(string temperature) {
    Temp = temperature;
}

void GestionTrames::setDHoraire(string debitHoraire) {
    DHoraire = debitHoraire;
}

void GestionTrames::setCompInhib(string compteurInhibition) {
    CompInhib = compteurInhibition;
}

void GestionTrames::setCompFuite(string compteurFuite) {
    CompFuite = compteurFuite;
}

void GestionTrames::setCompAbs(string compteurAbsent) {
    CompAbs = compteurAbsent;
}

void GestionTrames::setIndex(string index) {
    Index = index;
}

void GestionTrames::configuration(){
    portS->Open();
    //setup bauds
    portS->SetBaudRate(SerialPort::BAUD_19200);
    //setup taille
    portS->SetCharSize(SerialPort::CHAR_SIZE_8);
    //setup parité
    portS->SetParity(SerialPort::PARITY_NONE);
    //setup bit de stop
    portS->SetNumOfStopBits(SerialPort::STOP_BITS_1);
    //setup controle d'echange
    portS->SetFlowControl(SerialPort::FLOW_CONTROL_NONE);
}
/*calcule du checksum*/
char GestionTrames::calChecksum(string donnees) {
    //tmp prend valeur parametre 
    string tmp = donnees;
    char data[40];
    // strcpy() copie tmp dans data sous forme de char  tab[]
    strcpy(data, tmp.c_str());
    checksum = 0x80;
    /* for de la taille de chmp data */
    for (int i = 0; i < 40; i++) {
        // recep prend le contenue data[]
        char recep = data[i];
        // on fait un ou exclusif entre checksum et recep puis on additionne
        checksum ^= recep;
    }
    return checksum;
}
/*creation des données de la trame*/
std::string GestionTrames::creerDonnees() {
    /*creation des données dans une meme string*/
    DonneesTrame = Identifiant + Soft + Type + Coup + Etat + TPile + TCapa + Temp + DHoraire + CompInhib + CompFuite + CompAbs + Index;
    return DonneesTrame;
}
/*envoyer des trames*/
int GestionTrames::envoyerTrames(string donnees) {
    calChecksum(donnees);
    
    for(int i =0;i<=5;i++){
        this->portS->WriteByte(tete[i]);
    }
    sleep(2);
    //ecriture données de trame
    portS->Write(donnees);
    sleep(2);
    //ecriture checksum
    portS->WriteByte(checksum);
    sleep(2);
    //ecriture du caractere de fin 
    portS->WriteByte(fin);
    return EXIT_SUCCESS ;    
}


