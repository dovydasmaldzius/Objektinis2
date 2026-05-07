#include "structure.h"
#include "funkcions.h"
#include "includes.h"

template<typename Container>
void NuskaitymasIsFailo(const std::string& failas, Container& grupe) {
    
ifstream fd(failas);
if(!fd) {
cout<<"FAILAS NERASTAS: "<<failas<<endl;
return;
}

string temp;
getline(fd, temp);
Studentas A;

while(getline(fd, temp)) {

std::stringstream ss(temp);

ss>>A.vardas>>A.pavarde;
vector<int> pazymiai;
int pazymys;
int sum=0;
while(ss >> pazymys)
pazymiai.push_back(pazymys);

A.egzaminas = pazymiai.back();
pazymiai.pop_back();
A.paz = pazymiai;

for(int p:A.paz)
sum += p;

sort(A.paz.begin(), A.paz.end());
int kiekis = A.paz.size();
    if(kiekis % 2 == 0)
A.mediana = (A.paz[kiekis/2-1]+A.paz[kiekis/2])/2.0;
    else A.mediana = A.paz[kiekis/2];
A.rezultatas = (sum*1.0/A.paz.size())*0.4 + A.egzaminas*0.6;
grupe.push_back(A);
}
fd.close();
}