#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <limits>

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

struct Studentas {
string vardas="A",pavarde="B";
int *pazymiai;
vector<int>paz;
int egzaminas;
double rezultatas=0;
double mediana=0;
};



void outputas (const vector<Studentas> &grupe);
int main() {
srand(time(nullptr));
int s;
Studentas A;
vector<Studentas>grupe; //saugomi visi studentai
while(true){
    cout << "kiek yra studentu? " << endl;
cin>>s;
if(cin.fail() || s < 0) {
    cout<<"Prasome yvesti tik naturaliuosius skaicius! "<<endl;
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
    else break; }

for(int ii=0;ii<s;ii++) {
    cout<<"iveskite varda ir pavarde"<<endl;
cin>>A.vardas>>A.pavarde;
int n;
while(true) { //ciklas, kuris veikia iki tol, kol vartotojas įves klaidingą reikšmę
    cout<<"iveskite pazymiu skaiciu:"<<endl;
cin>>n;
if(cin.fail() || n < 0) { //tikrina, ar įvestas domuo yra teigiamas skaičius
    cout<<"Prasome ivesti tik naturaliuosiusskaicius! "<<endl;
cin.clear(); //klaida pašalinama
cin.ignore(numeric_limits<streamsize>::max(), '\n'); } //
    else break; } //baigiamas ciklas, jei įvestis teisinga
        
int temp; //laikinas pažymys
int sum=0;

    cout<<"Atsitiktinai sugeneruoti pazymiai: ";

for(int i=0;i<n;i++) {
    temp=rand() % 10 + 1;
    A.paz.push_back(temp);
    sum+=temp;
    cout<<temp<<" ";
}
    cout<<endl;

    cout<<"Atsitiktinai generuojamas egzamino pazymys: ";
A.egzaminas=rand() % 10 + 1;
    cout<<A.egzaminas<<endl;

A.paz.push_back(A.egzaminas); //laikinai įdedame egzamino pažymį į pažymių vektoriu, tam, kad galėtume teisingai apskaičiuoti medianą

sort(A.paz.begin(), A.paz.end()); //pažymiai yra surūšiuojami didėjimo tvarka

int kiekis=A.paz.size(); //skaičiuojama, kiek yra pažymių

if(kiekis == 0) A.mediana = 0; //jei pažymių nėra - mediana lygi 0
else if(kiekis % 2 == 0) A.mediana = (A.paz[kiekis/2 - 1] + A.paz[kiekis/2]) / 2.0; //jei pažymių skaičius yra lyginis - skaičiuojama mediana kaip dviejų vidurinių skaičių vidurkis
else A.mediana = A.paz[kiekis/2]; //jei pažymių skaičius yra nelyginis - medana yra vidurinis skaičius
A.paz.pop_back(); //pašalinamas egzamino pažymys iš pažymių vektoraus, nes jo reikėjo tik medianos skaičiavimui

A.rezultatas=sum*1.0/(n*1.0)*0.4+A.egzaminas*0.6;
grupe.push_back(A);
A.paz.clear(); //išvalomi pažymiai, kad juos būtų galima įvesti kitam studentui
}
    cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Rezultatas" << setw(20) << "Mediana" << endl;
for(auto A:grupe){
    cout << left << setw(20) << A.vardas << setw(20) << A.pavarde;
    cout<<setw(20)<<fixed<<setprecision(2)<<A.rezultatas;
    cout<<setw(20)<<A.mediana<<endl;
}
    return 0;
}