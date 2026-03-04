#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <ctime>
#include <fstream>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::left;
using std::right;
using std::setw;
using std::fixed;
using std::setprecision;
using std::numeric_limits;
using std::streamsize;
using std::max;
using std::ifstream;
using std::getline;


struct Studentas {
string vardas="A",pavarde="B";
vector<int>paz;
int egzaminas;
double rezultatas=0;
double mediana=0;
};

void outputas (const vector<Studentas> &grupe);

int main() {
    std::ios::sync_with_stdio(false);
int pasirinkimas;
int m;
Studentas A;
vector<Studentas>grupe; //saugomi visi studentai
cout<<"Jei norite studentus ir pazymius ivesti ranka, spauskite 1, jei tik pazymius norite generuoti atsitiktinai, spauskite 2, jei norite studentu vardus, pavardes ir pazymius generuoti atskirai, spauskite 3, jei norite duomenis nuskaityti is failo, spauskite 4"<<endl;
cin>>pasirinkimas;

if(pasirinkimas==1) {
    cout << "kiek yra studentu? " << endl;
cin>>m;
for(int ii=0; ii<m; ii++) {
while(true) {
    cout<<"Iveskite varda ir pavarde"<<endl;
cin>>A.vardas>>A.pavarde;
bool hasDigit = std::any_of(A.vardas.begin(), A.vardas.end(), [](unsigned char c){ return std::isdigit(c); }) || std::any_of(A.pavarde.begin(), A.pavarde.end(), [](unsigned char c){ return std::isdigit(c); });
if(hasDigit) {
    cout << "Prasome ivesti varda ir pavarde dar karta" << endl;
    continue; }
    break;
}

int n;
while(true) { //ciklas, kuris veikia iki tol, kol vartotojas įves klaidingą reikšmę
    cout<<"iveskite pazymiu skaiciu:"<<endl;
cin>>n;
if(cin.fail() || n < 0) { //tikrina, ar įvestas domuo yra teigiamas skaičius
    cout<<"Prasome ivesti tik skaicius nuo 1 iki 10! "<<endl;
cin.clear(); //klaida pašalinama
cin.ignore(numeric_limits<streamsize>::max(), '\n'); } //
    else break; } //baigiamas ciklas, jei įvestis teisinga
        
int temp; //laikinas pažymys
int sum=0;

for(int i=0;i<n;i++) {
while(true) {
    cout<<"iveskite pazymi: "<<endl;
cin>>temp;
if(cin.fail() || temp < 1 || temp > 10) { //tikrina, ar įvestas domuo yra skaičius nuo 1 iki 10
    cout<<"Prasome ivesti tik skaicius nuo 1 iki 10! "<<endl;
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
    else {
A.paz.push_back(temp); //pažymys pridedamas į studento pažymių vektorių
sum+=temp; //pažymys pridedamas prie sumos
break; } //baigiasi ciklas, jei įvestis teisinga
}
}

while(true) {
    cout<<"iveskite egzamino pazymi"<<endl;
cin>>A.egzaminas;
if(cin.fail() || A.egzaminas < 1 || A.egzaminas > 10) {
    cout<<"Prasome ivesti tik skaicius nuo 1 iki 10"<<endl;
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
    else break; 
}

A.paz.push_back(A.egzaminas); //laikinai įdedame egzamino pažymį į pažymių vektoriu, tam, kad galėtume teisingai apskaičiuoti medianą

sort(A.paz.begin(), A.paz.end()); //pažymiai yra surūšiuojami didėjimo tvarka

int kiekis = A.paz.size(); //skaičiuojama, kiek yra pažymių

if(kiekis == 0) A.mediana = 0; //jei pažymių nėra - mediana lygi 0
else if(kiekis % 2 == 0) A.mediana = (A.paz[kiekis/2 - 1] + A.paz[kiekis/2]) / 2.0; //jei pažymių skaičius yra lyginis - skaičiuojama mediana kaip dviejų vidurinių skaičių vidurkis
else A.mediana = A.paz[kiekis/2]; //jei pažymių skaičius yra nelyginis - medana yra vidurinis skaičius
A.paz.pop_back(); //pašalinamas egzamino pažymys iš pažymių vektoraus, nes jo reikėjo tik medianos skaičiavimui

A.rezultatas=sum*1.0/(n*1.0)*0.4+A.egzaminas*0.6;
grupe.push_back(A);
A.paz.clear(); }//išvalomi pažymiai, kad juos būtų galima įvesti kitam studentui
}




else if(pasirinkimas==2) {
    cout << "kiek yra studentu? " << endl;
cin>>m;
for(int ii=0; ii<m; ii++){
while(true) {
    cout<<"Iveskite varda ir pavarde"<<endl;
cin>>A.vardas>>A.pavarde;
bool hasDigit = std::any_of(A.vardas.begin(), A.vardas.end(), [](unsigned char c){ return std::isdigit(c); }) || std::any_of(A.pavarde.begin(), A.pavarde.end(), [](unsigned char c){ return std::isdigit(c); });
if(hasDigit) {
    cout << "Prasome ivesti varda ir pavarde dar karta" << endl;
    continue; }
    break;
}
int n;
while(true) {
    cout<<"iveskite pazymiu skaiciu:"<<endl;
cin>>n;
if(cin.fail() || n < 0) {
    cout<<"Prasome ivesti tik skaicius nuo 1 iki 10! "<<endl;
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
    else break; }
        
int sum=0;

    cout<<"Atsiktinai sugeneruoti "<<ii+1<<" - ojo studento pazymiai: "<<endl;
for(int i=0;i<n;i++) {
int temp = (rand() % 10) + 1;
A.paz.push_back(temp);
sum+=temp;
    cout<<temp<<" ";
    cout<<endl; }
        
A.egzaminas = (rand() % 10) + 1;
    cout<<"Atsitiktinai sugeneruotas "<<ii+1<<" - ojo studento egzamino pazymys: "<<A.egzaminas<<endl;

A.paz.push_back(A.egzaminas);
        
sort(A.paz.begin(), A.paz.end());
        
int kiekis = A.paz.size();
        
if(kiekis == 0) A.mediana = 0;
else if(kiekis % 2 == 0) A.mediana = (A.paz[kiekis/2 - 1] + A.paz[kiekis/2]) / 2.0;
else A.mediana = A.paz[kiekis/2];
A.paz.pop_back();
        
A.rezultatas=sum*1.0/(n*1.0)*0.4+A.egzaminas*0.6;
grupe.push_back(A);
A.paz.clear(); }
}




else if(pasirinkimas==3) {
    cout<<"kiek yra studentu? "<<endl;
cin>>m;
vector<string> firstNames={"Jonas","Petras","Ona","Lina","Mantas","Egle","Darius","Ruta","Tomas","Ieva"};
vector<string> lastNames={"Petraitis","Kazlauskas","Jankauskas","Stankevicius","Vilkas","Daugela","Miskinis","Jankauskiene","Zalys","Baranauskas"};
for(int ii=0; ii<m; ii++) {
A.vardas = firstNames[rand() % firstNames.size()];
A.pavarde = lastNames[rand() % lastNames.size()];

    int n=(rand() % 10)+1;
    int sum=0;

    cout<<"Atsiktinai sugeneruoti "<<ii+1<<" - ojo studento pazymiai: "<<endl;
for(int i=0; i<n; i++) {
    int temp = (rand() % 10)+1;
A.paz.push_back(temp);
    sum += temp;
    
    cout<<temp<<" ";
    cout<<endl;}

A.egzaminas = (rand() % 10) + 1;
    cout<<"Atsitiktinai sugeneruotas "<<ii+1<<" - ojo studento egzamino pazymys: "<<A.egzaminas<<endl;

A.paz.push_back(A.egzaminas);

sort(A.paz.begin(), A.paz.end());

int kiekis = A.paz.size();

if(kiekis == 0) A.mediana = 0;
else if(kiekis % 2 == 0) A.mediana = (A.paz[kiekis/2 - 1] + A.paz[kiekis/2]) / 2.0;
else A.mediana = A.paz[kiekis/2];

A.paz.pop_back();

A.rezultatas = sum*1.0/(n*1.0)*0.4 + A.egzaminas*0.6;
grupe.push_back(A);
A.paz.clear(); }
}




else if(pasirinkimas==4) {
std::ifstream fd("kursiokai.txt");
    string temp;
std::getline(fd,temp);

while(fd>>A.vardas>>A.pavarde) {
A.paz.clear();
    int sum=0;

for(int i=0;i<15;i++) {
    int pazymys;
fd>>pazymys;
A.paz.push_back(pazymys);
sum+=pazymys; }

fd>>A.egzaminas;
A.paz.push_back(A.egzaminas);

sort(A.paz.begin(), A.paz.end());
    int kiekis=A.paz.size();
if(kiekis % 2 == 0)
    A.mediana = (A.paz[kiekis/2 - 1] + A.paz[kiekis/2]) / 2.0;
else
    A.mediana = A.paz[kiekis/2];

A.paz.pop_back();

A.rezultatas=sum*1.0/15*0.4 + A.egzaminas*0.6;

grupe.push_back(A); }
fd.close(); }




else {
cout<<"Prasome pasirinkti viena is skaiciu 1, 2, 3 arba 4\n"; 
}




    cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Rezultatas" << setw(20) << "Mediana" << endl;
for(auto A:grupe){
    cout << left << setw(20) << A.vardas << setw(20) << A.pavarde;
    cout<<setw(20)<<fixed<<setprecision(2)<<A.rezultatas;
    cout<<setw(20)<<A.mediana<<endl;
}
    return 0;
}