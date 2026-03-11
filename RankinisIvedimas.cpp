#include "RankinisIvedimas.h"
#include "include.h"
#include "using.h"

void RankinisIvedimas(vector<Studentas>& grupe){

Studentas A;
int m;
    while(true) {
    cout << "kiek yra studentu? \n";
cin>>m;
if(cin.fail() || m < 0) { 
    cout<<"Prasome ivesti tik naturaliuosius skaicius! \n";
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
    else break; }

for(int ii=0; ii<m; ii++) {
while(true) {
    cout<<"Iveskite varda ir pavarde: \n";
cin>>A.vardas>>A.pavarde;
bool hasDigit = std::any_of(A.vardas.begin(), A.vardas.end(), [](unsigned char c){ return std::isdigit(c); }) || std::any_of(A.pavarde.begin(), A.pavarde.end(), [](unsigned char c){ return std::isdigit(c); });
if(hasDigit) {
    cout << "Prasome ivesti varda ir pavarde dar karta \n";
    continue; }
    break;
}

int n;
while(true) { //ciklas, kuris veikia iki tol, kol vartotojas įves klaidingą reikšmę
    cout<<"iveskite pazymiu skaiciu: \n";
cin>>n;
if(cin.fail() || n < 0) {
    cout<<"Prasome ivesti tik naturaliuosius skaicius! \n";
cin.clear(); //klaida pašalinama
cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
    else break; } //baigiamas ciklas, jei įvestis teisinga
        
int temp; //laikinas pažymys
int sum=0;

for(int i=0;i<n;i++) {
while(true) {
    cout<<"iveskite pazymi: \n";
cin>>temp;
if(cin.fail() || temp < 1 || temp > 10) {
    cout<<"Prasome ivesti tik skaicius nuo 1 iki 10! \n";
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
    else {
A.paz.push_back(temp); //pažymys pridedamas į studento pažymių vektorių
sum+=temp; //pažymys pridedamas prie sumos
break; } //baigiasi ciklas, jei įvestis teisinga
}
}

while(true) {
    cout<<"iveskite egzamino pazymi: \n";
cin>>A.egzaminas;
if(cin.fail() || A.egzaminas < 1 || A.egzaminas > 10) {
    cout<<"Prasome ivesti tik skaicius nuo 1 iki 10! \n";
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
    else break; 
}

A.paz.push_back(A.egzaminas); //laikinai įdedame egzamino pažymį į pažymių vektoriu, tam, kad galėtume teisingai apskaičiuoti medianą

sort(A.paz.begin(), A.paz.end()); //pažymiai surikiuojami, kad būtų galima apskaičiuoti medianą

int kiekis = A.paz.size(); //skaičiuojama, kiek yra pažymių

if(kiekis == 0) A.mediana = 0; //jei pažymių nėra - mediana lygi 0
else if(kiekis % 2 == 0) A.mediana = (A.paz[kiekis/2 - 1] + A.paz[kiekis/2]) / 2.0; //jei pažymių skaičius yra lyginis - skaičiuojama mediana kaip dviejų vidurinių skaičių vidurkis
else A.mediana = A.paz[kiekis/2]; //jei pažymių skaičius yra nelyginis - medana yra vidurinis skaičius
A.paz.pop_back(); //pašalinamas egzamino pažymys iš pažymių vektoraus, nes jo reikėjo tik medianos skaičiavimui

A.rezultatas=sum*1.0/(n*1.0)*0.4+A.egzaminas*0.6;
grupe.push_back(A);
A.paz.clear(); }//išvalomi pažymiai, kad juos būtų galima įvesti kitam studentui
}
