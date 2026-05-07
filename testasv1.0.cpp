#include "structure.h"
#include "funkcions.h"
#include "includes.h"
#include "Strategijos.h"

template <typename Container>
void TestuotiGreiti(const string& failas) {
Container studentai;

auto ns = std::chrono::high_resolution_clock::now();
NuskaitymasIsFailo(failas, studentai);
auto ne = std::chrono::high_resolution_clock::now();

cout<<failas<<"\n";
cout<<"Nuskaitymas: "<< duration<double>(ne-ns).count()<<" s\n";


Container rusiuoti = studentai;
auto rs = std::chrono::high_resolution_clock::now();

if constexpr (std::is_same_v<Container, std::list<Studentas>>) { //tikrina, ar konteineris yra list, jei taip - naudojamas list sort metodas
    rusiuoti.sort([](const Studentas& a, const Studentas& b) {
return a.rezultatas < b.rezultatas; });
}
else {
std::sort(rusiuoti.begin(), rusiuoti.end(), [](const Studentas& a, const Studentas& b) {
return a.rezultatas < b.rezultatas; });
}

auto re = std::chrono::high_resolution_clock::now();
cout<<"Rusiavimas: "<<duration<double>(re-rs).count()<<" s\n";


{ //Strategija nr. 1
Container kopija = rusiuoti;
Container vargsiukai, kietiakai;

auto s = std::chrono::high_resolution_clock::now();
Strategija1(kopija, vargsiukai, kietiakai);
auto e = std::chrono::high_resolution_clock::now();

cout<<"Strategija 1: "<<duration<double>(e-s).count()<<" s\n";
}

{ //Strategija nr. 2
Container kopija = rusiuoti;
Container vargsiukai;

auto s = std::chrono::high_resolution_clock::now();
Strategija2(kopija, vargsiukai);
auto e = std::chrono::high_resolution_clock::now();

cout<<"Strategija 2: "<<duration<double>(e-s).count()<<" s\n";
}

{ //Strategija nr. 3
Container kopija = rusiuoti;
Container vargsiukai, kietiakai;

auto s = std::chrono::high_resolution_clock::now();
Strategija3(kopija, vargsiukai, kietiakai);
auto e = std::chrono::high_resolution_clock::now();

cout<<"Strategija 3: "<<duration<double>(e-s).count()<<" s\n\n"; }
}