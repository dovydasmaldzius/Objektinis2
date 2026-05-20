#ifndef STUDENTAS_H //apsauga nuo kelių įtraukimų
#define STUDENTAS_H //apsauga nuo kelių įtraukimų

#include "includes.h"

class Studentas {

private:
string vardas_;
string pavarde_;
vector<int> paz_;
int egzaminas_;
double rezultatas_;
double mediana_;

public:
// Konstruktorius ir destruktorius
Studentas(); //numatytasis konstruktorius, kuris inicijuoja tuščius duomenis
Studentas(std::istream& is); //konstruktorius, kuris inicijuoja duomenis iš įvesties srauto
~Studentas() = default; //destruktorius, kuris naudoja numatytąją reikšmę

// Skaitymo metodai
std::istream& readStudent(std::istream& is); //metodas, kuris skaito studento duomenis iš įvesties srauto
void skaiciuotiRezultata(); //metodas, kuris skaičiuoja studento rezultatą pagal pažymius ir egzaminą

// Getteriai, leidžiantys pasiekti privačius duomenis
string& vardas() { return vardas_; }
    const string& vardas() const { return vardas_; }
string& pavarde() { return pavarde_; }
    const string& pavarde() const { return pavarde_; }
vector<int>& paz() { return paz_; }
    const vector<int>& paz() const { return paz_; }
int& egzaminas() { return egzaminas_; } //leidžia keisti duomenis, jei reikia
    int egzaminas() const { return egzaminas_; } //leidžia pasiekti duomenis, bet neleidžia jų keisti
double& rezultatas() { return rezultatas_; }
    double rezultatas() const { return rezultatas_; }
double& mediana() { return mediana_; }
    double mediana() const { return mediana_; }

// Setteriai, leidžiantys keisti privačius duomenis
    void setVardas(const string& v){ vardas_ = v; }
void setPavarde(const string& p){ pavarde_ = p; }
    void setPaz(const vector<int>& p){ paz_ = p; }
void addPaz(int p){ paz_.push_back(p); }
    void clearPaz(){ paz_.clear(); }
void setEgzaminas(int e){ egzaminas_ = e; }
    void setRezultatas(double r){ rezultatas_ = r; }
void setMediana(double m){ mediana_ = m; }
};

#endif //apsauga nuo kelių įtraukimų