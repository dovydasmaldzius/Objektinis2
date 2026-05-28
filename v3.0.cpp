#include "Studentas.h"
#include "includes.h"
#include "funkcions.h"
#include "Strategijos.h"

using StudContainer = vector<Studentas>; //naudojama vektoriaus konteinerio tipas, kad būtų galima lengvai keisti konteinerį
//using StudContainer = std::list<Studentas>;
//using StudContainer = std::deque<Studentas>;

    int main() {
    std::ios::sync_with_stdio(false); //duomenų srauto sinchronizavimas su C funkcijomis išjungiamas, kad būtų pasiektas didesnis efektyvumas
srand(time(NULL)); //naudojamas, kad funkcija rand() kiekvieną kartą generuotų ne tas pačias reikšmes
    int pasirinkimas;
    int rusiavimas=0;
    StudContainer grupe; //studentų grupė, kurioje saugomi visi studentai
while(true) {
    cout<<"Kaip norite ivesti duomenis?"<<endl;
    cout<<"1 - studentu vardus, pavardes ir pazymius ivesti ranka"<<endl;
    cout<<"2 - studentu vardus ir pavardes ivesti ranka, pazymius generuoti atsitiktinai"<<endl;
    cout<<"3 - studentu vardus, pavardes ir pazymius generuoti atsitiktinai"<<endl;
    cout<<"4 - duomenis nuskaityti is failo"<<endl;
    cout<<"5 - generuoti failus"<<endl;
    cout<<"6 - atlikti kodo greicio analize su skirtingais konteineriais"<<endl;
try { //programos vieta, kurioje gali įvykti klaida
cin>>pasirinkimas;
if(cin.fail()) {
    throw std::runtime_error("Prasome ivesti tik skaicius nuo 1 iki 6!"); //tikrina, ar įvestas skaičius, jei ne - išmetamas klaidos pranešimas
}
if(pasirinkimas < 1 || pasirinkimas > 6) {
    throw std::out_of_range("Prasome ivesti tik skaicius nuo 1 iki 6!"); //tikrina, ar įvestas skaičius yra nuo 1 iki 6, jei ne - išmetamas klaidos pranešimas
}
break;
}
catch(const std::exception& e) { //gaudoma bet kokia išimtis, kuri gali įvykti įvedant duomenis
    cout << e.what() << endl; //išvedamas klaidos pranešimas
cin.clear(); //klaida išvaloma, kad būtų galima vėl įvesti duomenis
cin.ignore(numeric_limits<streamsize>::max(), '\n'); //pašalinami netinkami įvesties duomenys, kad būtų galima vėl įvesti duomenis
}
}
if(pasirinkimas==1) RankinisIvedimas(grupe);
    else if(pasirinkimas==2) RandomPazymiai(grupe);
    else if(pasirinkimas==3) RandomStudentai(grupe);
    else if(pasirinkimas==4) Nuskaitymas(grupe, rusiavimas);
    else if(pasirinkimas==5) {
vector<int> dydziai={1000,10000,100000,1000000,10000000};
for(int n : dydziai) {
    string failas = "studentai" + to_string(n) + ".txt"; //kuriami failu pavadinimai

auto start = std::chrono::high_resolution_clock::now();
GeneruotiFaila(failas,n);

auto end = std::chrono::high_resolution_clock::now();
std::chrono::duration<double> diff = end - start;
    cout<<failas<<" sukurtas per "<<diff.count()<<" s\n";
}
return 0;
}
else if(pasirinkimas==6) {
LaikoMatavimas();
return 0;
}
Isvedimas(grupe, pasirinkimas, rusiavimas); //duomenų išvedimas
return 0;
cout<<"\nSpauskite Enter, kad Uzdarytumete programa...\n";
cin.ignore(numeric_limits<streamsize>::max(), '\n');
cin.get(); 
}