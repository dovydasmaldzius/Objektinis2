#include "structure.h"
#include "funkcions.h"
#include "includes.h"

template <typename Container>
void TestuotiGreiti(const string& failas) {

Container studentai;

auto t1 = std::chrono::high_resolution_clock::now();
NuskaitymasIsFailo(failas, studentai);

auto t2 = std::chrono::high_resolution_clock::now();

auto t3 = std::chrono::high_resolution_clock::now();

if constexpr (std::is_same<Container, std::list<Studentas>>::value) {
studentai.sort([](const Studentas& a, const Studentas& b) {
return a.rezultatas < b.rezultatas; });
} 
else {
std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
return a.rezultatas < b.rezultatas; });
}

auto t4 = std::chrono::high_resolution_clock::now();

Container vargsiukai;
Container kietiakai;

auto t5 = std::chrono::high_resolution_clock::now();

for(const auto& s : studentai){
if(s.rezultatas < 5)
    vargsiukai.push_back(s);
else
kietiakai.push_back(s);
}

auto t6 = std::chrono::high_resolution_clock::now();

    cout<<failas<<endl;
    cout<<"Nuskaitymas: "<<std::chrono::duration<double>(t2-t1).count()<<" s\n";
    cout<<"Rusiavimas: "<<std::chrono::duration<double>(t4-t3).count()<<" s\n";
    cout<<"Skirstymas: "<<std::chrono::duration<double>(t6-t5).count()<<" s\n\n";
}