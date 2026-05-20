#ifndef PAZYMIAIRANDOM_IMPL_H //apsauga nuo kelių įtraukimų
#define PAZYMIAIRANDOM_IMPL_H //apsauga nuo kelių įtraukimų

#include "Studentas.h"
#include "includes.h"

template<typename Container>
void RandomPazymiai(Container& grupe) {

Studentas A;

char testistud='t';
while(testistud=='t' || testistud=='T') {
    int sum=0;
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

char testipaz='t';
int temp;

    cout<<"Random namu darbu pazymiai:\n";
while(testipaz=='t' || testipaz=='T') {
    temp = (rand() % 10) + 1;
    cout<<"Random pazymys: "<<temp<<endl;

A.paz().push_back(temp);
    sum+=temp;
    cout<<"Spauskite t, jei norite ivesti kita pazymi "<<endl;
    cout<<"Jei baigete pazymiu ivedima, spauskite bet koki (ne t) simboli"<<endl;
cin>>testipaz;
}
        
A.egzaminas() = (rand() % 10) + 1;
    cout<<"Sugeneruotas egzamino pazymys: "<<A.egzaminas()<<endl;

A.paz().push_back(A.egzaminas());
        
std::sort(A.paz().begin(), A.paz().end());
        
int kiekis = A.paz().size();
    if(kiekis == 0) A.mediana() = 0;
    else if(kiekis % 2 == 0) A.mediana() = (A.paz()[kiekis/2 - 1] + A.paz()[kiekis/2]) / 2.0;
    else A.mediana() = A.paz()[kiekis/2];

A.paz().pop_back();
        
    A.rezultatas() = (sum * 1.0 / A.paz().size()) * 0.4 + A.egzaminas() * 0.6;
grupe.push_back(A);
    A.paz().clear(); 
    cout<<"Spauskite t, jei norite ivesti kita studenta "<<endl;
    cout<<"Jei baigete studentu ivedima, spauskite bet koki (ne t) simboli"<<endl;
cin>>testistud;
}
}

#endif // apsauga nuo kelių įtraukimų
