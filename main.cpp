#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
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

struct Studentas{
string vardas="A",pavarde="B";
int *pazymiai;
vector<int>paz;
int egzaminas;
double rezultatas=0;
double mediana=0;
};

void outputas (const vector<Studentas> &grupe);
int main()
{ int s;
Studentas A;
vector<Studentas>grupe;
cout << "kiek yra studentu? " << endl;
cin>>s;
for(int ii=0;ii<s;ii++)
{

    cout<<"iveskite varda ir pavarde"<<endl;
cin>>A.vardas>>A.pavarde;
    cout<<"iveskite semestro pazymius:\nKiek pazymiu bus?"<<endl;
int n,temp,sum=0;
cin>>n;
for(int i=0;i<n;i++)
{cin>>temp;
A.paz.push_back(temp);
sum+=temp;
}

    cout<<"iveskite egzamino pazymi"<<endl;
cin>>A.egzaminas;
sort(A.paz.begin(), A.paz.end());

int kiekis = A.paz.size();

if(kiekis == 0) A.mediana = 0;
else if(kiekis % 2 == 0) A.mediana = (A.paz[kiekis/2 - 1] + A.paz[kiekis/2]) / 2.0;
else A.mediana = A.paz[kiekis/2];
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
