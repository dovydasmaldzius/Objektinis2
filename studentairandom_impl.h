#ifndef STUDENTAIRANDOM_IMPL_H
#define STUDENTAIRANDOM_IMPL_H

#include "Studentas.h"
#include "includes.h"

template<typename Container>
void RandomStudentai(Container& grupe) {

Studentas A;

vector<string> firstNames={"Jonas","Petras","Ona","Lina","Mantas","Egle","Darius","Ruta","Tomas","Ieva"};
vector<string> lastNames={"Petraitis","Kazlauskas","Jankauskas","Stankevicius","Vilkas","Daugela","Miskinis","Jankauskiene","Zalys","Baranauskas"};

char testi='t';
int ii=1;

while(testi=='t' || testi=='T') {
A.vardas() = firstNames[rand() % firstNames.size()];
A.pavarde() = lastNames[rand() % lastNames.size()];

int n = rand()%10 + 1;
int sum = 0;

cout<<"Sugeneruotas "<<ii<<" studentas: "<<A.vardas()<<" "<<A.pavarde()<<"\n";
cout<<"Random namu darbu pazymiai:\n";

for(int i=0;i<n;i++) {
int temp = rand()%10 + 1;
    A.paz().push_back(temp);
sum += temp;
    cout<<temp<<" ";
}
    cout<<endl;

A.egzaminas() = (rand() % 10) + 1;
    cout<<"Random egzamino pazymys: "<<A.egzaminas()<<endl;

A.paz().push_back(A.egzaminas());

std::sort(A.paz().begin(), A.paz().end());

int kiekis = A.paz().size();
if(kiekis == 0) A.mediana() = 0;
    else if(kiekis % 2 == 0) A.mediana() = (A.paz()[kiekis/2 - 1] + A.paz()[kiekis/2]) / 2.0;
    else A.mediana() = A.paz()[kiekis/2];

A.paz().pop_back();

A.rezultatas() = sum*1.0/(n*1.0)*0.4 + A.egzaminas()*0.6;
    grupe.push_back(A);
A.paz().clear(); 
    cout<<"Spauskite t, jei norite sugeneruoti kita studenta "<<endl;
    cout<<"Jei baigete studentu generavima, spauskite bet koki (ne t) simboli"<<endl;
    cin>>testi;
    ii++;
}
}

#endif // STUDENTAIRANDOM_IMPL_H
