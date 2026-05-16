#include "Studentas.h"
#include <algorithm>
#include <numeric>

// Konstruktorius ir destruktorius
Studentas::Studentas(): egzaminas_(0), rezultatas_(0), mediana_(0) {}

Studentas::Studentas(std::istream& is) { readStudent(is);}

// Skaitymo metodai
std::istream& Studentas::readStudent(std::istream& is) {
paz_.clear();
is>>vardas_>>pavarde_;
int paz;
    while(is>>paz)
paz_.push_back(paz);
    egzaminas_ = paz_.back();
paz_.pop_back();
    skaiciuotiRezultata();
return is;
}

void Studentas::skaiciuotiRezultata() {
if(paz_.empty()) return;
double vid = std::accumulate(paz_.begin(), paz_.end(), 0.0) / paz_.size();
    rezultatas_ = 0.4 * vid + 0.6 * egzaminas_;
    auto kopija = paz_;
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