/* 
 * File:   gestionTrames.cpp
 * Author: eleve
 * 
 * Created on 17 février 2016, 11:15
 */
#include <SerialStream.h>
#include <SerialPort.h>
#include "gestionTrames.h"
#include <string>
#include <string.h>
using namespace LibSerial;

gestionTrames::gestionTrames() {}
gestionTrames::gestionTrames(SerialPort *inst){
    portS=inst;
}
gestionTrames::~gestionTrames() {
    //fermeture de la liaison
    portS->Close();
}
/*definition des */
int gestionTrames::tete[]= {0x03,0xFF,0xFF,0xFF,0x0A,0x0A};
int gestionTrames::fin={0x0D};
/*getter en hexadecimal*/
std::string gestionTrames::getIdentifiant() {
    return Identifiant;
}

std::string gestionTrames::getSoft() {
    return Soft;
}

std::string gestionTrames::getType() {
    return Type;
}

std::string gestionTrames::getCoup() {
    return Coup;
}

std::string gestionTrames::getEtat() {
    return Etat;
}

std::string gestionTrames::getTPile() {
    return TPile;
}

std::string gestionTrames::getTCapa() {
    return TCapa;
}

std::string gestionTrames::getTemp() {
    return Temp;
}

std::string gestionTrames::getDHoraire() {
    return DHoraire;
}

std::string gestionTrames::getCompInhib() {
    return CompInhib;
}

std::string gestionTrames::getCompFuite() {
    return CompFuite;
}

std::string gestionTrames::getCompAbs() {
    return CompAbs;
}

std::string gestionTrames::getIndex() {
    return Index;
}

/*setter en hexadecimal*/
void gestionTrames::setIdentifiant(string id) {
    Identifiant = id;
}

void gestionTrames::setSoft(string soft) {
    Soft = soft;
}

void gestionTrames::setType(string type) {
    Type = type;
}

void gestionTrames::setCoup(string coup) {
    Coup = coup;
}

void gestionTrames::setEtat(string etat) {
    Etat = etat;
}

void gestionTrames::setTPile(string tensionPile) {
    TPile = tensionPile;
}

void gestionTrames::setTCapa(string tensionCapa) {
    TCapa = tensionCapa;
}

void gestionTrames::setTemp(string temperature) {
    Temp = temperature;
}

void gestionTrames::setDHoraire(string debitHoraire) {
    DHoraire = debitHoraire;
}

void gestionTrames::setCompInhib(string compteurInhibition) {
    CompInhib = compteurInhibition;
}

void gestionTrames::setCompFuite(string compteurFuite) {
    CompFuite = compteurFuite;
}

void gestionTrames::setCompAbs(string compteurAbsent) {
    CompAbs = compteurAbsent;
}

void gestionTrames::setIndex(string index) {
    Index = index;
}

void gestionTrames::configuration(){
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
char gestionTrames::calChecksum(string donnees) {
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
    //printf(" %02X \n", checksum);
    //std::cout << std::hex << checksum;
    return checksum;
}
/*creation des données de la trame*/
std::string gestionTrames::creerDonnees() {
    /*creationdes données dans une meme string*/
    std::string resultatDonnee = Identifiant + Soft + Type + Coup + Etat + TPile + TCapa + Temp + DHoraire + CompInhib + CompFuite + CompAbs + Index;
    return resultatDonnee;
}
/*envoyer des trames*/
int gestionTrames::envoyerTrames(string donnees) {
    
    
    for(int i =0;i<=5;i++){
        this->portS->WriteByte(tete[i]);
    }
    //ecriture données de trame
    portS->Write(donnees);
    //ecriture checksum
    portS->WriteByte(checksum);
    //ecriture du caractere de fin 
    portS->WriteByte(fin);
    
    return EXIT_SUCCESS ;    
}
void gestionTrames::test(){
    char resul;
    resul =calChecksum("00128B550100242913000000000010E00004D1");
    printf("%02X",resul);
    envoyerTrames("00128B550100242913000000000010E00004D1");
}

