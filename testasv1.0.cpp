#include "structure.h"
#include "funkcions.h"
#include "includes.h"
#include "Strategijos.h"

template <typename Container>
void TestuotiGreiti(const string& failas) {
Container studentai;

auto pr = std::chrono::high_resolution_clock::now(); //fuksuojamas laikas prieš studentų nuskaitymą
NuskaitymasIsFailo(failas, studentai);
auto pa = std::chrono::high_resolution_clock::now(); //fiksuojamas laikas po studentų nuskaitymo

cout<<failas<<"\n";
cout<<"Nuskaitymas: "<< duration<double>(pa-pr).count()<<" s\n";


Container rusiuoti = studentai; //kopija, kuri bus rikiuojama, kad originalus studentų sąrašas liktų nepakitęs
auto prad = std::chrono::high_resolution_clock::now(); //fiksuojamas laikas prieš rikiavimą

if constexpr (std::is_same_v<Container, std::list<Studentas>>) { //tikrina, ar konteineris yra list, jei taip - naudojamas list sort metodas
    rusiuoti.sort([](const Studentas& a, const Studentas& b) {
return a.rezultatas < b.rezultatas; });
}
else {
std::sort(rusiuoti.begin(), rusiuoti.end(), [](const Studentas& a, const Studentas& b) {
return a.rezultatas < b.rezultatas; });
}

auto pab = std::chrono::high_resolution_clock::now(); //fiksuojamas laikas po rikiavimo

cout<<"Rusiavimas: "<<duration<double>(pab-prad).count()<<" s\n";

{ //Strategija nr. 1
Container kopija = rusiuoti; //kopija, kuri bus naudojama strategijoms, kad originalus rikiuotas sąrašas liktų nepakitęs
Container vargsiukai, kietiakai;

auto b = std::chrono::high_resolution_clock::now(); //fiksuojamas laikas prieš 1-osstrategijos vykdymą
Strategija1(kopija, vargsiukai, kietiakai);
auto e = std::chrono::high_resolution_clock::now(); //fiksuojamas laikas po 1-os strategijos vykdymo

cout<<"Strategija 1: "<<duration<double>(e-b).count()<<" s\n";
}

{ //Strategija nr. 2
Container kopija = rusiuoti; //kopija, kuri bus naudojama strategijoms, kad originalus rikiuotas sąrašas liktų nepakitęs
Container vargsiukai;

auto b = std::chrono::high_resolution_clock::now(); //fiksuojamas laikas prieš 2-os strategijos vykdymą
Strategija2(kopija, vargsiukai);
auto e = std::chrono::high_resolution_clock::now(); //fiksuojamas laikas po 2-os strategijos vykdymo

cout<<"Strategija 2: "<<duration<double>(e-b).count()<<" s\n";
}

{ //Strategija nr. 3
Container kopija = rusiuoti; //kopija, kuri bus naudojama strategijoms, kad originalus rikiuotas sąrašas liktų nepakitęs    
Container vargsiukai, kietiakai;

auto b = std::chrono::high_resolution_clock::now(); //fiksuojamas laikas prieš 3-os strategijos vykdymą
Strategija3(kopija, vargsiukai, kietiakai);
auto e = std::chrono::high_resolution_clock::now(); //fiksuojamas laikas po 3-os strategijos vykdymo

cout<<"Strategija 3: "<<duration<double>(e-b).count()<<" s\n\n"; }
}