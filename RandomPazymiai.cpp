#include "include.h"
#include "using.h"
#include "RankinisIvedimas.h"
#include "RandomPazymiai.h"

void RandomPazymiai(vector<Studentas>& grupe){
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

for(int ii=0; ii<m; ii++){
while(true) {
    cout<<"Iveskite varda ir pavarde \n";
cin>>A.vardas>>A.pavarde;
bool hasDigit = std::any_of(A.vardas.begin(), A.vardas.end(), [](unsigned char c){ return std::isdigit(c); }) || std::any_of(A.pavarde.begin(), A.pavarde.end(), [](unsigned char c){ return std::isdigit(c); });
if(hasDigit) {
    cout << "Prasome ivesti varda ir pavarde dar karta \n";
    continue; }
    break;
}
int n;
while(true) {
    cout<<"iveskite pazymiu skaiciu: \n";
cin>>n;
if(cin.fail() || n < 0) {
    cout<<"Prasome ivesti tik naturaliuosius skaicius! \n";
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
    else break; }
        
int sum=0;

    cout<<"Atsiktinai sugeneruoti "<<ii+1<<" - ojo studento pazymiai: \n";
for(int i=0;i<n;i++) {
int temp = (rand() % 10) + 1;
A.paz.push_back(temp);
sum+=temp;
    cout<<temp<<" ";
    cout<<endl; }
        
A.egzaminas = (rand() % 10) + 1;
    cout<<"Atsitiktinai sugeneruotas "<<ii+1<<" - ojo studento egzamino pazymys: "<<A.egzaminas<<"\n";

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