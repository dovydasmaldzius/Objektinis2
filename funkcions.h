#ifndef FUNKCIONS_H //apsauga nuo kelių įtraukimų
#define FUNKCIONS_H //apsauga nuo kelių įtraukimų

#include "structure.h"

void RankinisIvedimas(std::vector<Studentas>& grupe);
void RandomPazymiai(vector<Studentas>& grupe);
void RandomStudentai(vector<Studentas>& grupe);
void Nuskaitymas(vector<Studentas>& grupe, int &rusiavimas);
void NuskaitymasIsFailo(const string& failas, vector<Studentas>& grupe);
void Isvedimas(vector<Studentas>& grupe, int pasirinkimas, int rusiavimas);
void GeneruotiFaila(const string& failas, int kiekis);
void LaikoMatavimas();

#endif //apsauga nuo kelių įtraukimų
