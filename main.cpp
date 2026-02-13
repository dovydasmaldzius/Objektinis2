#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
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
double rezultatas;
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
A.rezultatas=sum*1.0/(n*1.0)*0.4+A.egzaminas*0.6;
grupe.push_back(A);
A.paz.clear();
}
cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde" << setw(20) << "Rezultatas" << endl;
for(auto A:grupe){
    cout << left << setw(20) << A.vardas << setw(20) << A.pavarde;
cout<<setw(20)<<fixed<<setprecision(2)<<A.rezultatas<<endl;
}
    return 0;
}
