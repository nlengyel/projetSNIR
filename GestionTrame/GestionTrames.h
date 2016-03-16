/* 
 * File:   GestionTrames.h
 * Author: nlengyel
 *
 * Created on 17 février 2016, 11:15
 */

#ifndef GESTIONTRAMES_H
#define	GESTIONTRAMES_H

#include <string>
#include <SerialPort.h>
using namespace std; 
class GestionTrames {
public:
    GestionTrames();
    GestionTrames(SerialPort*);
    ~GestionTrames();
    int envoyerTrames(string donnees);
    string creerDonnees();
    void configuration();
    //getter checksum
    char getChecksum();
    //getter DonneesTrame
    string getDonneesTrame();
    //getter en hexadecimal
    string getIdentifiant();
    string getSoft();
    string getType();
    string getCoup();
    string getEtat();
    string getTPile();
    string getTCapa();
    string getTemp();
    string getDHoraire();
    string getCompInhib();
    string getCompFuite();
    string getCompAbs();
    string getIndex();
    //getter decimal
    
    //setter en hexadecimal
    void setIdentifiant(string id);
    void setSoft(string soft);
    void setType(string type);
    void setCoup(string coup);
    void setEtat(string etat);
    void setTPile(string tensionPile);
    void setTCapa(string tensionCapa);
    void setTemp(string temperature);
    void setDHoraire(string debitHoraire);
    void setCompInhib(string compteurInhibition);
    void setCompFuite(string compteurFuite);
    void setCompAbs(string compteurAbsence);
    void setIndex(string index);
    
    SerialPort *portS; 
private:
    /*methode privé*/
    char calChecksum(string donnees);

    /*attributs static*/
    static int tete[6];
    static int fin ;
/*---------attributs--------*/
    char checksum;
    std::string DonneesTrame;
    
    //identifiant
    std::string Identifiant;
    //soft
    std::string Soft;
    //type de fonction
    std::string Type;
    //etat de coupure
    std::string Coup;
    // etat d'activité
    std::string Etat;
    //tension pile
    std::string TPile;
    //tension capacité
    std::string TCapa;
    //temperature
    std::string Temp;
    //debit horaire
    std::string DHoraire;
    //compteur inhibition
    std::string CompInhib;
    //compteur fuite
    std::string CompFuite;
    //compteur d'absence
    std::string CompAbs;
    //index
    std::string Index;    
};

#endif	/* GESTIONTRAMES_H */

