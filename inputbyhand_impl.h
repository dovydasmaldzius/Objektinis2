#ifndef INPUTBYHAND_IMPL_H
#define INPUTBYHAND_IMPL_H

#include "funkcions.h"
#include "Studentas.h"
#include "includes.h"

template<typename Container>
void RankinisIvedimas(Container& grupe){

Studentas A;

char testistud='t';
while(testistud=='t' || testistud=='T') {

while(true) {
    cout<<"Iveskite varda ir pavarde: \n";
    try {
cin>>A.vardas()>>A.pavarde();
bool hasDigit = std::any_of(A.vardas().begin(), A.vardas().end(), [](unsigned char c){ return std::isdigit(c); }) || std::any_of(A.pavarde().begin(), A.pavarde().end(), [](unsigned char c){ return std::isdigit(c); });
if(hasDigit) {
    throw std::runtime_error("Prasome ivesti tik raides!");
continue; }
break;
}
    catch(const std::exception& e) {
    cout << e.what() << endl;
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
}
        
char testipaz = 't';
int temp; //laikinas pažymys
int sum=0;
    cout<<"Iveskite visus pazymius\n";

while(testipaz=='t' || testipaz=='T') {
    while(true) {
    cout<<"iveskite pazymi: \n";
    try {
cin >> temp;
if(cin.fail()) {
    throw std::runtime_error("Prasome ivesti tik skaicius!");
}
if(temp < 1 || temp > 10) {
    throw std::out_of_range("Prasome ivesti skaiciu nuo 1 iki 10!");
}
A.paz().push_back(temp);
sum += temp;
break;
}
    catch(const std::exception& e) {
    cout << e.what() << endl;
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
}

    cout<<"Spauskite t, jei norite ivesti dar viena pazymi "<<endl;
    cout<<"Jei baigete pazymiu ivedima, spauskite bet koki (ne t) simboli"<<endl;
cin>>testipaz;
}

    while(true) {
    cout<<"iveskite egzamino pazymi: \n";
    try {
cin>>A.egzaminas();
if(cin.fail()) {
    throw std::runtime_error("Prasome ivesti tik skaicius!");
}
if(A.egzaminas() < 1 || A.egzaminas() > 10) {
    throw std::out_of_range("Prasome ivesti skaiciu nuo 1 iki 10!");
}
break;
}
    catch(const std::exception& e) {
    cout << e.what() << endl;
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
}

A.paz().push_back(A.egzaminas());
std::sort(A.paz().begin(), A.paz().end());

int kiekis = A.paz().size();
if(kiekis == 0) A.mediana() = 0;
    else if(kiekis % 2 == 0) A.mediana() = (A.paz()[kiekis/2 - 1] + A.paz()[kiekis/2]) / 2.0;
    else A.mediana() = A.paz()[kiekis/2];
A.paz().pop_back();

A.rezultatas()=sum*1.0/(A.paz().size()*1.0)*0.4+A.egzaminas()*0.6;
grupe.push_back(A);
A.paz().clear();
    cout<<"Spauskite t, jei norite ivesti kita studenta "<<endl;
    cout<<"Jei baigete studentu ivedima, spauskite bet koki (ne t) simboli"<<endl;
cin>>testistud;
}
}

#endif // INPUTBYHAND_IMPL_H
