#ifndef FUNKCIONS_H //apsauga nuo kelių įtraukimų
#define FUNKCIONS_H //apsauga nuo kelių įtraukimų

#include "Studentas.h"
#include "includes.h"
#include "Strategijos.h"

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

template<typename Container>
void TestuotiGreiti(const string& failas);

void GeneruotiFaila(const std::string& failas, int kiekis);
void LaikoMatavimas();

// Include template implementations
#include "input_impl.h"
#include "inputbyhand_impl.h"
#include "pazymiairandom_impl.h"
#include "studentairandom_impl.h"
#include "nuskaitymas_impl.h"
#include "output_impl.h"
#include "testuoti_impl.h"

#endif //apsauga nuo kelių įtraukimų
