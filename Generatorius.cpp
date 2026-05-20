#include "Studentas.h"
#include "funkcions.h"
#include "includes.h"

void GeneruotiFaila(const string& failas, int kiekis) {

ofstream fr(failas);
    fr<<left<<setw(20)<<"Vardas"<<setw(20)<<"Pavarde";
for(int i = 1; i <= 5; i++)
    fr<<setw(5)<<("ND"+to_string(i));
    fr<<setw(5)<<"Egz."<<"\n";

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> paz(1,10);

for(int i=1;i<=kiekis;i++) {
    fr<<left<<setw(20)<<("Vardas" + to_string(i))<<setw(20)<<("Pavarde" + to_string(i));

for(int j = 0; j < 5; j++)
    fr<<setw(5)<<paz(gen);
    fr<<setw(5)<<paz(gen)<<"\n";
}
    fr.close();
}