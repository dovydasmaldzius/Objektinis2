#include "Funkcijos.h"
#include "struktura.h"
#include "include.h"

void RankinisIvedimas(vector<Studentas>& grupe){

Studentas A;

char testistud='t';
while(testistud=='t' || testistud=='T') {

while(true) {
    cout<<"Iveskite varda ir pavarde: \n";
try { //programos vieta, kurioje gali įvykti klaida
cin>>A.vardas>>A.pavarde;
bool hasDigit = std::any_of(A.vardas.begin(), A.vardas.end(), [](unsigned char c){ return std::isdigit(c); }) || std::any_of(A.pavarde.begin(), A.pavarde.end(), [](unsigned char c){ return std::isdigit(c); });
if(hasDigit) {
    throw std::runtime_error("Prasome ivesti tik raides!");
    continue; }
    break;
}
catch(const std::exception& e) { //gaudoma bet kokia išimtis, kuri gali įvykti įvedant duomenis
    cout << e.what() << endl; //išvedamas klaidos pranešimas
cin.clear(); //klaida išvaloma, kad būtų galima vėl įvesti duomenis
cin.ignore(numeric_limits<streamsize>::max(), '\n'); //pašalinami netinkami įvesties duomenys, kad būtų galima vėl įvesti duomenis
}
}
        
char testipaz = 't';
int temp; //laikinas pažymys
int sum=0;
cout<<"Iveskite visus pazymius\n";

while(testipaz=='t' || testipaz=='T') {
while(true) {
    cout<<"iveskite pazymi: \n";
try { //programos vieta, kurioje gali įvykti klaida
cin >> temp;
if(cin.fail()) {
    throw std::runtime_error("Prasome ivesti tik skaicius!");
}
if(temp < 1 || temp > 10) {
    throw std::out_of_range("Prasome ivesti skaiciu nuo 1 iki 10!");
}
A.paz.push_back(temp);
sum += temp;
break;
}
catch(const std::exception& e) { //gaudoma bet kokia išimtis, kuri gali įvykti įvedant duomenis
    cout << e.what() << endl; //išvedamas klaidos pranešimas
cin.clear(); //klaida išvaloma, kad būtų galima vėl įvesti duomenis
cin.ignore(numeric_limits<streamsize>::max(), '\n'); //pašalinami netinkami įvesties duomenys, kad būtų galima vėl įvesti duomenis
}
}

    cout<<"Spauskite t, jei norite ivesti dar viena pazymi "<<endl;
    cout<<"Jei baigete pazymiu ivedima, spauskite bet koki (ne t) simboli"<<endl;
cin>>testipaz;
}

while(true) {
    cout<<"iveskite egzamino pazymi: \n";
    try { //programos vieta, kurioje gali įvykti klaida
cin>>A.egzaminas;
if(cin.fail()) {
    throw std::runtime_error("Prasome ivesti tik skaicius!");
}
if(A.egzaminas < 1 || A.egzaminas > 10) {
    throw std::out_of_range("Prasome ivesti skaiciu nuo 1 iki 10!");
}
break;
}
catch(const std::exception& e) { //gaudoma bet kokia išimtis, kuri gali įvykti įvedant duomenis
    cout << e.what() << endl; //išvedamas klaidos pranešimas
cin.clear(); //klaida išvaloma, kad būtų galima vėl įvesti duomenis
cin.ignore(numeric_limits<streamsize>::max(), '\n'); //pašalinami netinkami įvesties duomenys, kad būtų galima vėl įvesti duomenis
}
}

A.paz.push_back(A.egzaminas); //laikinai įdedame egzamino pažymį į pažymių vektoriu, tam, kad galėtume teisingai apskaičiuoti medianą

sort(A.paz.begin(), A.paz.end()); //pažymiai surikiuojami, kad būtų galima apskaičiuoti medianą

int kiekis = A.paz.size(); //skaičiuojama, kiek yra pažymių

if(kiekis == 0) A.mediana = 0; //jei pažymių nėra - mediana lygi 0
else if(kiekis % 2 == 0) A.mediana = (A.paz[kiekis/2 - 1] + A.paz[kiekis/2]) / 2.0; //jei pažymių skaičius yra lyginis - skaičiuojama mediana kaip dviejų vidurinių skaičių vidurkis
else A.mediana = A.paz[kiekis/2]; //jei pažymių skaičius yra nelyginis - medana yra vidurinis skaičius
A.paz.pop_back(); //pašalinamas egzamino pažymys iš pažymių vektoraus, nes jo reikėjo tik medianos skaičiavimui

A.rezultatas=sum*1.0/(A.paz.size()*1.0)*0.4+A.egzaminas*0.6;
grupe.push_back(A);
A.paz.clear(); //išvalomi pažymiai, kad juos būtų galima įvesti kitam studentui
    cout<<"Spauskite t, jei norite ivesti kita studenta "<<endl;
    cout<<"Jei baigete studentu ivedima, spauskite bet koki (ne t) simboli"<<endl;
cin>>testistud;
}
}