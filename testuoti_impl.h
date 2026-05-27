#ifndef TESTUOTI_IMPL_H
#define TESTUOTI_IMPL_H

#include "Studentas.h"
#include "funkcions.h"
#include "includes.h"
#include "Strategijos.h"

template <typename Container>
void TestuotiGreiti(const string& failas) {

    Container studentai;
auto pr = std::chrono::high_resolution_clock::now();
    NuskaitymasIsFailo(failas, studentai);
auto pa = std::chrono::high_resolution_clock::now();

    cout<<failas<<"\n";
    cout<<"Nuskaitymas: "<<duration<double>(pa-pr).count()<<" s\n";

    Container rusiuoti = studentai;
auto prad = std::chrono::high_resolution_clock::now();
if constexpr (std::is_same_v<Container, list<Studentas>>) {
    rusiuoti.sort([](const Studentas& a, const Studentas& b) {
return a.rezultatas() < b.rezultatas(); });
}
else {
    sort(rusiuoti.begin(), rusiuoti.end(), [](const Studentas& a, const Studentas& b) {
return a.rezultatas() < b.rezultatas(); });
}
    auto pab = std::chrono::high_resolution_clock::now();
    cout<<"Rusiavimas: "<<duration<double>(pab-prad).count()<<" s\n\n";

// 1 Strategija
{
    Container kopija = rusiuoti;
    Container vargsiukai, kietiakai;
auto b = std::chrono::high_resolution_clock::now();
    Strategija1(kopija, vargsiukai, kietiakai);
auto e = std::chrono::high_resolution_clock::now();
    cout<<"Strategija 1: "<<duration<double>(e-b).count()<<" s\n";
IsvestiIFaila(vargsiukai, "vargsiukai_" + failas);
IsvestiIFaila(kietiakai, "kietiakai_" + failas);
}

// 2 Strategija
{
    Container kopija = rusiuoti;
    Container vargsiukai;
auto b = std::chrono::high_resolution_clock::now();
    Strategija2(kopija, vargsiukai);
auto e = std::chrono::high_resolution_clock::now();
    cout<<"Strategija 2: "<< duration<double>(e-b).count()<<" s\n";
IsvestiIFaila(vargsiukai, "vargsiukai_" + failas);
IsvestiIFaila(kopija, "kietiakai_" + failas);
}

// 3 Strategija
{
    Container kopija = rusiuoti;
    Container vargsiukai, kietiakai;
auto b = std::chrono::high_resolution_clock::now();
    Strategija3(kopija, vargsiukai, kietiakai);
auto e = std::chrono::high_resolution_clock::now();
    cout<<"Strategija 3: "<<duration<double>(e-b).count()<<" s\n\n";
IsvestiIFaila(vargsiukai, "vargsiukai_" + failas);
IsvestiIFaila(kietiakai, "kietiakai_" + failas);
}
}

#endif // TESTUOTI_IMPL_H
