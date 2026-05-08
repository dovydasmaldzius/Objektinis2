#ifndef STRATEGIJOS_H //apsauga nuo kelių įtraukimų
#define STRATEGIJOS_H //apsauga nuo kelių įtraukimų

#include "structure.h"
#include "funkcions.h"
#include "includes.h"

template<typename Container>
void Strategija1(Container& studentai, Container& vargsiukai, Container& kietiakai) { 
    for(const auto& s : studentai) {
if(s.rezultatas < 5)
    vargsiukai.push_back(s);
else
    kietiakai.push_back(s); }
}

template<typename Container>
void Strategija2(Container& studentai, Container& vargsiukai) {
    std::remove_copy_if (studentai.begin(), studentai.end(), std::back_inserter(vargsiukai), [](const Studentas& s) {
return s.rezultatas >= 5; });

auto it = std::remove_if( studentai.begin(), studentai.end(), [](const Studentas& s) {
return s.rezultatas < 5; });

studentai.erase(it, studentai.end());
}

template<typename Container>
void Strategija3(Container& studentai, Container& vargsiukai, Container& kietiakai) {
auto it = std::partition (studentai.begin(), studentai.end(), [](const Studentas& s) {
return s.rezultatas < 5; });

vargsiukai.insert(vargsiukai.end(), studentai.begin(), it); //vargsiukai konteineris užpildomas vargšiukais
kietiakai.insert(kietiakai.end(), it, studentai.end()); //kietiakai konteineris užpildomas kietiakais
}

#endif //apsauga nuo kelių įtraukimų