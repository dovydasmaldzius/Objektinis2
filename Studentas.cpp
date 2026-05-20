#include "Studentas.h"
#include "Zmogus.h"
#include <algorithm>
#include <numeric>
#include <utility>

// Konstruktoriai
Studentas::Studentas() : Zmogus(), egzaminas_(0), rezultatas_(0), mediana_(0) {} // Numatytasis konstruktorius, kuris leidžia sukurti tuščią studentą, jei reikia

Studentas::Studentas(std::istream& is) { // Konstruktorius, kuris leidžia sukurti studentą iš įvesties srauto
readStudent(is); // Naudojama readStudent funkcija, kad būtų galima nuskaityti studento duomenis iš įvesties srauto
}

// Kopijavimo konstruktorius
Studentas::Studentas(const Studentas& other) : Zmogus(other.vardas_, other.pavarde_), // Naudojama bazinės klasės konstruktorius, kad būtų galima kopijuoti vardą ir pavardę
paz_(other.paz_), //kopijuojami rezultatai tam, kad būtų galima saugiai kopijuoti duomenis, net jei pažymiai yra saugomi dinaminiu būdu
    egzaminas_(other.egzaminas_),
rezultatas_(other.rezultatas_),
    mediana_(other.mediana_) {} 

// Kopijavimo priskyrimo operatorius
Studentas& Studentas::operator=(const Studentas& other) { //tikrina, ar objektas nėra priskiriamas sau pačiam, ir jei ne - kopijuoja duomenis iš kito objekto į šį objektą
if (this == &other) 
    return *this; // Jei objektas yra priskiriamas sau pačiam, grąžina šį objektą, kad būtų galima grandinti priskyrimus
vardas_ = other.vardas_;
pavarde_ = other.pavarde_;
paz_ = other.paz_;
egzaminas_ = other.egzaminas_;
rezultatas_ = other.rezultatas_;
mediana_ = other.mediana_;
    return *this;
}

// Perkėlimo konstruktorius
Studentas::Studentas(Studentas&& other) noexcept : Zmogus(std::move(other.vardas_), // Naudojama bazinės klasės konstruktorius, kad būtų galima perkelti vardą ir pavardę
std::move(other.pavarde_)), //perkeliami duomenys, kad būtų galima saugiai perkelti duomenis, net jei vardas ir pavardė yra saugomi dinaminiu būdu
paz_(std::move(other.paz_)),
    egzaminas_(other.egzaminas_),
rezultatas_(other.rezultatas_),
    mediana_(other.mediana_) {

other.egzaminas_ = 0; //reikšmės priskiriamos nuliui
other.rezultatas_ = 0;
other.mediana_ = 0;
}

// Perkėlimo priskyrimo operatorius
Studentas& Studentas::operator=(Studentas&& other) noexcept { //tikrina, ar objektas nėra priskiriamas sau pačiam, ir jei ne - perkelia duomenis iš kito objekto į šį objektą
if (this == &other)
    return *this;
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

// Duomenų nuskaitymas iš srauto
std::istream& Studentas::readStudent(std::istream& is) { //funkcija, kuri leidžia nuskaityti studento duomenis iš įvesties srauto, ir grąžina tą patį srautą

paz_.clear();

is>>vardas_>>pavarde_;
int paz;
    while (is >> paz)
paz_.push_back(paz);
    if (!paz_.empty()) {
egzaminas_ = paz_.back();
paz_.pop_back();
}
skaiciuotiRezultata();
    return is;
}

// Override iš Zmogus
void Studentas::skaiciuotiRezultata() {
    if (paz_.empty())
return;
double vidurkis = std::accumulate(paz_.begin(), paz_.end(), 0.0) / paz_.size(); //accumulate naudojamas vidurkiui apskaičiuoti
    rezultatas_ = 0.4 * vidurkis + 0.6 * egzaminas_;
    auto kopija = paz_;
std::sort(kopija.begin(), kopija.end());
    mediana_ = kopija[kopija.size() / 2];
}

// Srauto operatoriai
std::istream& operator>>(std::istream& is, Studentas& s) {
return s.readStudent(is);
}
std::ostream& operator<<(std::ostream& os, const Studentas& s) {
os<<s.vardas_<<' '<<s.pavarde_;
    for (const auto& g : s.paz_)
os<<' '<<g;
os<<' '<<s.egzaminas_;
    return os;
}

// Komparatoriai
bool comparePagalVarda(const Studentas& a, const Studentas& b) {
    return a.vardas() < b.vardas();
}

bool comparePagalPavarde(const Studentas& a, const Studentas& b) {
    return a.pavarde() < b.pavarde();
}

bool comparePagalRezultata(const Studentas& a, const Studentas& b) {
    return a.rezultatas() < b.rezultatas();
}