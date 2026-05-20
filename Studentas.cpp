#include "Studentas.h"
#include <algorithm>
#include <numeric>

// Konstruktorius ir destruktorius
Studentas::Studentas(): egzaminas_(0), rezultatas_(0), mediana_(0) {} //funkcija priklausanti klasei Studentas, kuri inicijuoja tuščius duomenis

Studentas::Studentas(std::istream& is) { readStudent(is);} //funkcija priklausanti klasei Studentas, kuri inicijuoja duomenis iš įvesties srauto

// Skaitymo metodai
std::istream& Studentas::readStudent(std::istream& is) { //naudojamas, kad būtų galima įvesti studento duomenis iš įvesties srauto
paz_.clear(); //išvaloma pažymių vektorius, kad būtų galima įvesti naujus duomenis
is>>vardas_>>pavarde_;
int paz;
    while(is>>paz) //toliau skaitomi pažymiai, kol nebus įvestas netinkamas duomuo
paz_.push_back(paz); //kiekvienas įvestas pažymys pridedamas į pažymių vektorių
    egzaminas_ = paz_.back(); //paskutinis įvestas pažymys laikomas egzamino pažymiu
paz_.pop_back(); //paskutinis įvestas pažymys pašalinamas iš pažymių vektoriaus
    skaiciuotiRezultata(); //skaičiuojamas studento rezultatas pagal įvestus pažymius ir egzaminą
return is;
}

void Studentas::skaiciuotiRezultata() {
if(paz_.empty()) return; //jei pažymių nėra, rezultatas negali būti apskaičiuotas
double vid = std::accumulate(paz_.begin(), paz_.end(), 0.0) / paz_.size(); //accumulate funkcija naudojama, kad būtų galima apskaičiuoti pažymių vidurkį
    rezultatas_ = 0.4 * vid + 0.6 * egzaminas_;
    auto kopija = paz_; //sukuriama pažymių kopija, kad būtų galima apskaičiuoti medianą
std::sort(kopija.begin(), kopija.end());
    mediana_ = kopija[kopija.size()/2];
}

// Comparatoriai
bool comparePagalVarda(const Studentas& a,const Studentas& b) {
return a.vardas() < b.vardas();
}
bool comparePagalPavarde(const Studentas& a,const Studentas& b) {
return a.pavarde() < b.pavarde();
}
bool comparePagalRezultata(const Studentas& a,const Studentas& b) {
return a.rezultatas() < b.rezultatas();
}