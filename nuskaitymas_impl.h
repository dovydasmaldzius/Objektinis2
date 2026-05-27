#ifndef NUSKAITYMAS_IMPL_H
#define NUSKAITYMAS_IMPL_H

#include "Studentas.h"
#include "includes.h"

template<typename Container>
void NuskaitymasIsFailo(const std::string& failas, Container& grupe) {

ifstream fd(failas);
if(!fd) {
    cout<<"FAILAS NERASTAS: "<<failas<<endl;
return; }

string temp;
getline(fd, temp);

while(getline(fd, temp)) {
Studentas A;
    std::stringstream ss(temp);
    string vardas,pavarde;
ss>>vardas>>pavarde;

A.setVardas(vardas);
A.setPavarde(pavarde);
vector<int> pazymiai;
int pazymys;
int sum = 0;

    while(ss>>pazymys)
pazymiai.push_back(pazymys);
    A.setEgzaminas(pazymiai.back());
pazymiai.pop_back();
    A.setPaz(pazymiai);
for(int p : A.paz())
    sum += p;

vector<int> tempPaz = A.paz();
std::sort(tempPaz.begin(), tempPaz.end());
int kiekis = tempPaz.size();
    double mediana;
if(kiekis % 2 == 0)
    mediana = (tempPaz[kiekis/2-1] + tempPaz[kiekis/2]) / 2.0;
else
    mediana = tempPaz[kiekis/2];

A.setMediana(mediana);

    double rez = (sum * 1.0 / A.paz().size()) * 0.4 + A.egzaminas() * 0.6;
A.setRezultatas(rez);
    grupe.push_back(A);
}
fd.close();
}

#endif // NUSKAITYMAS_IMPL_H
