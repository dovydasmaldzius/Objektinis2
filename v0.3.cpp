#include "struktura.h"
#include "include.h"
#include "Funkcijos.h"

    int main() {
std::ios::sync_with_stdio(false); //duomenų srauto sinchronizavimas su C funkcijomis išjungiamas, kad būtų pasiektas didesnis efektyvumas
srand(time(NULL)); //naudojamas, kad funkcija rand() kiekvieną kartą generuotų ne tas pačias reikšmes
    int pasirinkimas;
    int rusiavimas=0;
    int m;
Studentas A; //vienas studentas, kurio duomenys bus įvedami, o vėliau įdedami į grupę
    vector<Studentas>grupe; //saugomi visi studentai

while(true) {
    cout<<"Kaip norite ivesti duomenis?"<<endl;
    cout<<"1 - studentu vardus, pavardes ir pazymius ivesti ranka"<<endl;
    cout<<"2 - studentu vardus ir pavardes ivesti ranka, pazymius generuoti atsitiktinai"<<endl;
    cout<<"3 - studentu vardus, pavardes ir pazymius generuoti atsitiktinai"<<endl;
    cout<<"4 - duomenis nuskaityti is failo"<<endl;
try { //programos vieta, kurioje gali įvykti klaida
cin>>pasirinkimas;
if(cin.fail()) {
    throw std::runtime_error("Prasome ivesti tik skaicius nuo 1 iki 4!"); //tikrina, ar įvestas skaičius, jei ne - išmetamas klaidos pranešimas
}
if(pasirinkimas < 1 || pasirinkimas > 4) {
    throw std::out_of_range("Prasome ivesti tik skaicius nuo 1 iki 4!"); //tikrina, ar įvestas skaičius yra nuo 1 iki 4, jei ne - išmetamas klaidos pranešimas
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
Isvedimas(grupe, pasirinkimas, rusiavimas);

return 0;
};