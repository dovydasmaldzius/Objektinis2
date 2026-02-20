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
int s;
Studentas A;
vector<Studentas>grupe;
    cout << "kiek yra studentu? " << endl;
cin>>s;

for(int ii=0;ii<s;ii++) {
    cout<<"iveskite varda ir pavarde"<<endl;
cin>>A.vardas>>A.pavarde;
int n;

while(true) {
    cout<<"iveskite pazymiu skaiciu:"<<endl;
cin>>n;
if(cin.fail() || n < 0) {
    cout<<"Prasome ivesti tik skaicius nuo 1 iki 10! "<<endl;
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
    else break; }
        
int temp;
int sum=0;

for(int i=0;i<n;i++) {
while(true){
    cout<<"iveskite pazymi: "<<endl;
cin>>temp;
if(cin.fail() || temp < 1 || temp > 10) {
    cout<<"Prasome ivesti tik skaicius nuo 1 iki 10! "<<endl;
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
    else{
A.paz.push_back(temp);
sum+=temp;
break; }
}
}

while(true) {
    cout<<"iveskite egzamino pazymi"<<endl;
cin>>A.egzaminas;
if(cin.fail() || A.egzaminas < 1 || A.egzaminas > 10) {
    cout<<"Prasome ivesti tik skaicius nuo 1 iki"<<endl;
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
    else break; 
}

A.paz.push_back(A.egzaminas);

sort(A.paz.begin(), A.paz.end());

int kiekis = A.paz.size();

if(kiekis == 0) A.mediana = 0;
else if(kiekis % 2 == 0) A.mediana = (A.paz[kiekis/2 - 1] + A.paz[kiekis/2]) / 2.0;
else A.mediana = A.paz[kiekis/2];
A.paz.pop_back();

A.rezultatas=sum*1.0/(n*1.0)*0.4+A.egzaminas*0.6;
grupe.push_back(A);
A.paz.clear();
}
    cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Rezultatas" << setw(20) << "Mediana" << endl;
for(auto A:grupe){
    cout << left << setw(20) << A.vardas << setw(20) << A.pavarde;
    cout<<setw(20)<<fixed<<setprecision(2)<<A.rezultatas;
    cout<<setw(20)<<A.mediana<<endl;
}
    return 0;
}
