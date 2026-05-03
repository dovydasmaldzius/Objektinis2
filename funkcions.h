#ifndef FUNKCIONS_H //apsauga nuo kelių įtraukimų
#define FUNKCIONS_H //apsauga nuo kelių įtraukimų

#include "structure.h"
#include "includes.h"

template<typename Container>
void RankinisIvedimas(Container& grupe);

template<typename Container>
void RandomPazymiai(Container& grupe);

template<typename Container>
void RandomStudentai(Container& grupe);

template<typename Container>
void Nuskaitymas(Container& grupe, int &rusiavimas);

template<typename Container>
void NuskaitymasIsFailo(const std::string& failas, Container& grupe);

template<typename Container>
void Isvedimas(Container& grupe, int pasirinkimas, int rusiavimas);

template<typename Container>
void IsvestiIFaila(const Container& grupe, const std::string& failas);

template <typename Container>
void TestuotiGreiti(const string& failas);

void GeneruotiFaila(const std::string& failas, int kiekis);
void LaikoMatavimas();

#include "output.cpp"
#include "input.cpp"
#include "InputByHand.cpp"
#include "PazymiaiRandom.cpp"
#include "StudentaiRandom.cpp"
#include "VisuFailuNuskaitymas.cpp"
#include "Generatorius.cpp"
#include "LaikoMatavimas.cpp"
#include "testasv1.0.cpp"

#endif //apsauga nuo kelių įtraukimų
