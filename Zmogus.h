#ifndef ZMOGUS_H
#define ZMOGUS_H

#include "includes.h"

class Zmogus { // abstrakti bazinė klasė, objektų joje negalime kurti

protected: // Žmogaus duomenys (vardas, pavardė)turi būti pasiekiami tik Studentas klasei, todėl protected
std::string vardas_;
std::string pavarde_;

public: //Konstruktoriai ir destruktorius
Zmogus() = default; // numatytasis konstruktorius, kuris leidžia sukurti tuščią žmogų, jei reikia
Zmogus(const std::string& v, const std::string& p) : vardas_(v), pavarde_(p) {} // konstruktorius, kuris leidžia sukurti žmogų su vardu ir pavarde

virtual ~Zmogus() = default; //objekto naukinimas per virtualų destruktorių

// Getteriai
std::string& vardas() { return vardas_; } // leidžia keisti vardą
const std::string& vardas() const { return vardas_; } // leidžia gauti vardą, bet neleidžia jo keisti (const)

std::string& pavarde() { return pavarde_; } // leidžia keisti pavardę
const std::string& pavarde() const { return pavarde_; } // leidžia gauti pavardę, bet neleidžia jos keisti (const)

void setVardas(const std::string& v){ vardas_ = v; } 
void setPavarde(const std::string& p){ pavarde_ = p; }

virtual void skaiciuotiRezultata() = 0; //Klasė Žmogus tampa abstrakti, pačioje joje negalima kurti objekto
};

#endif