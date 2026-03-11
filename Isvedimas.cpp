#include "include.h"
#include "using.h"
#include "RankinisIvedimas.h"
#include "RandomPazymiai.h"
#include "RandomStudentai.h"
#include "Nuskaitymas.h"
#include "Isvedimas.h"

void Isvedimas(vector<Studentas>& grupe, int pasirinkimas, int rusiavimas){
Studentas A;
int m;
if(pasirinkimas==4) {
    if(rusiavimas==1) {
    sort(grupe.begin(), grupe.end(), [](const Studentas &a, const Studentas &b) {
return a.rezultatas>b.rezultatas;
});
}
else if(rusiavimas==2) {
    sort(grupe.begin(), grupe.end(), [](const Studentas &a, const Studentas &b) {
return a.mediana>b.mediana;
});
}
else {
    cout<<"Prasome pasirinkti tik 1 arba 2!\n"; }
}

int isvedimas;
while(true) {
    cout<<"Kur norite matyti rezultatus? \n";
    cout<<"1 - ekrane \n";
    cout<<"2 - faile rezultatai.txt \n";
cin>>isvedimas;
if(cin.fail() || (isvedimas!=1 && isvedimas!=2)) {
    cout<<"Prasome pasirinkti tik skaiciu 1 arba 2! \n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
else break;
}

auto start = std::chrono::high_resolution_clock::now(); //fiksuojamas tikslus laikas prieš operacijos atlikimą, kad būtų galima apskaičiuoti, kiek laiko užtrunka duomenų išvedimas

if(isvedimas==1) {
    cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
if(pasirinkimas==4) {
if(rusiavimas==1)
    cout << setw(20) << "Galutinis";
else
    cout << setw(20) << "Mediana"; 
}
else {
    cout << setw(20) << "Galutinis" << setw(20) << "Mediana";
}
    cout<<"\n";

for(const auto &A:grupe) { //naudojama esamo objekto grupe tik adresas, kad būtų galima išvengti nereikalingo kopijavimo
    cout << left << setw(20) << A.vardas << setw(20) << A.pavarde;
if(pasirinkimas==4) {
if(rusiavimas==1)
    cout << setw(20) << fixed << setprecision(2) << A.rezultatas;
else
    cout << setw(20) << A.mediana;
}
else {
    cout << setw(20) << fixed << setprecision(2) << A.rezultatas << setw(20) << A.mediana;
}
    cout<<"\n";
}
}

else if(isvedimas==2){
ofstream fr("rezultatai.txt");
fr<<left<<setw(20)<<"Vardas"<<setw(20)<<"Pavarde";

if(pasirinkimas==4) {
if(rusiavimas==1)
    fr<<setw(20)<<"Galutinis";
else
    fr<<setw(20)<<"Mediana";
}
else {
    fr<<setw(20)<<"Galutinis"<<setw(20)<<"Mediana";
}
    fr<<"\n";

for(const auto &A:grupe) { //naudojama esamo objekto grupe tik adresas, kad būtų galima išvengti nereikalingo kopijavimo
    fr<<left<<setw(20)<<A.vardas<<setw(20)<<A.pavarde;

if(pasirinkimas==4) {
if(rusiavimas==1)
    fr<<setw(20)<<fixed<<setprecision(2)<<A.rezultatas;
else
    fr<<setw(20)<<A.mediana;
}
else {
    fr<<setw(20)<<fixed<<setprecision(2)<<A.rezultatas<<setw(20)<<A.mediana;
}
    fr<<"\n";
}

fr.close();
    cout<<"Prasome patikrinti faila rezultatai.txt \n";
}

auto end = std::chrono::high_resolution_clock::now(); //fiksuojamas tikslus laikas PO operacijos atlikimo
std::chrono::duration<double> diff = end - start; //parodo, kad laikas bus gražintas sekundėmis, nes naudojama double tipo kintamasis

cout<<"Duomenu isvedimo laikas: "<< diff.count()<<" s \n"; //gražina skirtumą tarp pradžios ir pabaigos laiko sekundėmis
}