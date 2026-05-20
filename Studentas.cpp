#include "Studentas.h"
#include <algorithm>
#include <numeric>
#include <utility>

// Konstruktoriai
Studentas::Studentas(): egzaminas_(0), rezultatas_(0), mediana_(0) {} //užpildomas numatytasis konstruktorius, kuris inicijuoja tuščius duomenis

Studentas::Studentas(std::istream& is) { readStudent(is);} //konstruktorius, kuris inicijuoja duomenis iš įvesties srauto

// Copy constructor
Studentas::Studentas(const Studentas& other) : vardas_(other.vardas_), pavarde_(other.pavarde_), paz_(other.paz_), egzaminas_(other.egzaminas_), rezultatas_(other.rezultatas_), mediana_(other.mediana_) {} //kuriami nauji objektai kaip kopijos, naudojant kitų objektų duomenis

// Copy assignment
Studentas& Studentas::operator=(const Studentas& other) { //priskiriamos vieno objekto reikšmės kitam objektui, naudojant kitų objektų duomenis
if (this == &other) return *this; //tikrinama, ar objektas nėra priskiriamas sau pačiam, jei taip - grąžinamas pats objektas
    vardas_ = other.vardas_; //priskiriami vieno objekto reikšmės kitam objektui
    pavarde_ = other.pavarde_;
    paz_ = other.paz_;
    egzaminas_ = other.egzaminas_;
    rezultatas_ = other.rezultatas_;
    mediana_ = other.mediana_;
return *this; //grąžinami priskirti objektai
}

// Move constructor
Studentas::Studentas(Studentas&& other) noexcept : vardas_(std::move(other.vardas_)), pavarde_(std::move(other.pavarde_)), paz_(std::move(other.paz_)), egzaminas_(other.egzaminas_), rezultatas_(other.rezultatas_), mediana_(other.mediana_) { //kuriami nauji objektai, kurie perima kitam objektui priskirtas reikšmes, o kitas objektas paliekamas tuščias
    other.egzaminas_ = 0; //paliekamos tuščios reikšmės kitiems objektams
    other.rezultatas_ = 0;
    other.mediana_ = 0;
}

// Move assignment
Studentas& Studentas::operator=(Studentas&& other) noexcept { //priskiriamos vieno objekto reikšmės kitam objektui, o kitas objektas paliekamas tuščias
if (this == &other) return *this; //tikrinama, ar objektas nėra priskiriamas sau pačiam, jei taip - grąžinamas pats objektas
    vardas_ = std::move(other.vardas_); //priskiriamos vieno objekto reikšmės kitiems objektams, naudojant kitų objektų duomenis
    pavarde_ = std::move(other.pavarde_);
    paz_ = std::move(other.paz_);
    egzaminas_ = other.egzaminas_; //priskiriamos vieno objekto reikšmės kitam objektui, o kitas objektas paliekamas tuščias
    rezultatas_ = other.rezultatas_;
    mediana_ = other.mediana_;
    other.egzaminas_ = 0;
    other.rezultatas_ = 0;
    other.mediana_ = 0;
return *this; //grąžinami priskirti objektai
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
std::istream& operator>>(std::istream& is, Studentas& s) { //apibrėžiamas įvesties operatorius, kuris leidžia įvesti duomenis į objektą
    return s.readStudent(is); //naudojamas readStudent metodas, kuris skaito studento duomenis iš įvesties srauto
}

std::ostream& operator<<(std::ostream& os, const Studentas& s) { //apibrėžiamas išvesties operatorius, kuris leidžia išvesti duomenis iš objekto
    os << s.vardas_ << ' ' << s.pavarde_;
    for (const auto& g : s.paz_) os << ' ' << g; //g - kiekvienas pažymys iš paz_ vektoriaus, kuris saugo studento pažymius
    os << ' ' << s.egzaminas_;
    return os;
} //galima naudoti private tipo operatorius, nes yra naudojamos friend funkcijos