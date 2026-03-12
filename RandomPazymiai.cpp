#include "include.h"
#include "using.h"
#include "Funkcijos.h"

void RandomPazymiai(vector<Studentas>& grupe) {
Studentas A;

char testistud='t';
while(testistud=='t' || testistud=='T') {
    int sum=0;
while(true) {
    cout<<"Iveskite varda ir pavarde \n";
cin>>A.vardas>>A.pavarde;
bool hasDigit = std::any_of(A.vardas.begin(), A.vardas.end(), [](unsigned char c){ return std::isdigit(c); }) || std::any_of(A.pavarde.begin(), A.pavarde.end(), [](unsigned char c){ return std::isdigit(c); });
if(hasDigit) {
    cout << "Prasome ivesti varda ir pavarde dar karta \n";
    continue; }
    break;
}
char testipaz='t';
int temp;

cout<<"Random namu darbu pazymiai:\n";

while(testipaz=='t' || testipaz=='T') {
temp = (rand() % 10) + 1;
cout<<"Random pazymys: "<<temp<<endl;

A.paz.push_back(temp);
sum+=temp;
    cout<<"Spauskite t, jei norite ivesti kita pazymi "<<endl;
    cout<<"Jei baigete pazymiu ivedima, spauskite bet koki (ne t) simboli"<<endl;
cin>>testipaz;
}
        
A.egzaminas = (rand() % 10) + 1;
cout<<"Sugeneruotas egzamino pazymys: "<<A.egzaminas<<endl;

A.paz.push_back(A.egzaminas);
        
sort(A.paz.begin(), A.paz.end());
        
int kiekis = A.paz.size();
        
if(kiekis == 0) A.mediana = 0;
else if(kiekis % 2 == 0) A.mediana = (A.paz[kiekis/2 - 1] + A.paz[kiekis/2]) / 2.0;
else A.mediana = A.paz[kiekis/2];
A.paz.pop_back();
        
A.rezultatas = (sum * 1.0 / A.paz.size()) * 0.4 + A.egzaminas * 0.6;
grupe.push_back(A);
A.paz.clear(); 
    cout<<"Spauskite t, jei norite ivesti kita studenta "<<endl;
    cout<<"Jei baigete studentu ivedima, spauskite bet koki (ne t) simboli"<<endl;
cin>>testistud;
}
}