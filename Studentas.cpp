#include "Studentas.h"
#include <algorithm>
#include <numeric>
#include <utility>

// Konstruktorius ir destruktorius
Studentas::Studentas(): egzaminas_(0), rezultatas_(0), mediana_(0) {}

Studentas::Studentas(std::istream& is) { readStudent(is);}

// Copy constructor
Studentas::Studentas(const Studentas& other) : vardas_(other.vardas_), pavarde_(other.pavarde_), paz_(other.paz_), egzaminas_(other.egzaminas_), rezultatas_(other.rezultatas_), mediana_(other.mediana_) {}

// Copy assignment
Studentas& Studentas::operator=(const Studentas& other) {
if (this == &other) return *this;
    vardas_ = other.vardas_;
    pavarde_ = other.pavarde_;
    paz_ = other.paz_;
    egzaminas_ = other.egzaminas_;
    rezultatas_ = other.rezultatas_;
    mediana_ = other.mediana_;
return *this;
}

// Move constructor
Studentas::Studentas(Studentas&& other) noexcept : vardas_(std::move(other.vardas_)), pavarde_(std::move(other.pavarde_)), paz_(std::move(other.paz_)), egzaminas_(other.egzaminas_), rezultatas_(other.rezultatas_), mediana_(other.mediana_) {
    other.egzaminas_ = 0;
    other.rezultatas_ = 0;
    other.mediana_ = 0;
}

// Move assignment
Studentas& Studentas::operator=(Studentas&& other) noexcept {
if (this == &other) return *this;
    vardas_ = std::move(other.vardas_);
    pavarde_ = std::move(other.pavarde_);
    paz_ = std::move(other.paz_);
    egzaminas_ = other.egzaminas_;
    rezultatas_ = other.rezultatas_;
    mediana_ = other.mediana_;
    other.egzaminas_ = 0;
    other.rezultatas_ = 0;
    other.mediana_ = 0;
return *this;
}

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

// Stream operators
std::istream& operator>>(std::istream& is, Studentas& s) {
    return s.readStudent(is);
}

std::ostream& operator<<(std::ostream& os, const Studentas& s) {
    os << s.vardas_ << ' ' << s.pavarde_;
    for (const auto& g : s.paz_) os << ' ' << g;
    os << ' ' << s.egzaminas_;
    return os;
}