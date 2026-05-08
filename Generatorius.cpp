#include "structure.h"
#include "funkcions.h"
#include "includes.h"

void GeneruotiFaila(const string& failas, int kiekis) {

ofstream fr(failas);
    fr<<left<<setw(20)<<"Vardas"<<setw(20)<<"Pavarde";
for(int i = 1; i <= 5; i++)
    fr<<setw(5)<<("ND"+to_string(i));
    fr<<setw(5)<<"Egz."<<"\n";

    random_device rd; //atsitiktinkių skaičių generatoriaus šaltinis, kuris naudoja atsitiktinius duomenis iš OS
    mt19937 gen(rd()); //atsitiktinkių skaičių generatorius, naudojant Mersenne Twister algoritmą
    uniform_int_distribution<> paz(1,10); //vienoda tikimybe pazymiu nuo 1 iki 10 generavimui

for(int i=1;i<=kiekis;i++) {
    fr<<left<<setw(20)<<("Vardas" + to_string(i))<<setw(20)<<("Pavarde" + to_string(i));

for(int j = 0; j < 5; j++)
    fr<<setw(5)<<paz(gen);
    fr<<setw(5)<<paz(gen)<<"\n";
}
    fr.close();
}