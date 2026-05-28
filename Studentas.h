#ifndef STUDENTAS_H
#define STUDENTAS_H

#include "Zmogus.h"

class Studentas : public Zmogus { // Studentas paveldi iš Žmogus, todėl jis turi visus Žmogaus duomenis ir funkcijas

private:

vector<int> paz_;
int egzaminas_;
double rezultatas_;
double mediana_;

public:

//Konsgtruktoriai ir destruktorius
Studentas(); // numatytasis konstruktorius, kuris leidžia sukurti tuščią studentą, jei reikia
Studentas(std::istream& is); // konstruktorius, kuris leidžia sukurti studentą iš įvesties srauto
~Studentas() = default; // destruktorius, kuris leidžia saugiai sunaikinti studento objektą, kai jis nebereikalingas

// Rule of Five
Studentas(const Studentas& other);
Studentas& operator=(const Studentas& other);
Studentas(Studentas&& other) noexcept;
Studentas& operator=(Studentas&& other) noexcept;

// Override iš Zmogus
void skaiciuotiRezultata() override; //override nurodo, kad ši funkcija yra perrašymas iš bazinės klasės Zmogus, ir kad ji turi būti įgyvendinta Studentas klasėje

std::istream& readStudent(std::istream& is); // funkcija, kuri leidžia nuskaityti studento duomenis iš įvesties srauto, ir grąžina tą patį srautą, kad būtų galima grandinti įvestis

friend std::istream& operator>>(std::istream& is, Studentas& s); //friend funkcija laidžia pasiekti Studentas klasės privačius duomenis
friend std::ostream& operator<<(std::ostream& os, const Studentas& s);

// Getteriai
vector<int>& paz(){ return paz_; }
const vector<int>& paz() const { return paz_; }

int& egzaminas() { return egzaminas_; }
    int egzaminas() const { return egzaminas_; }
double& rezultatas() { return rezultatas_; }
    double rezultatas() const { return rezultatas_; }
double& mediana() { return mediana_; }
    double mediana() const { return mediana_; }

// Setteriai
void addPaz(int p){ paz_.push_back(p); }
void setPaz(const vector<int>& p){ paz_ = p; }
void setPaz(vector<int>&& p){ paz_ = std::move(p); }
void setEgzaminas(int e){ egzaminas_ = e; }
void setRezultatas(double r){ rezultatas_ = r; }
void setMediana(double m){ mediana_ = m; }
};

#endif 