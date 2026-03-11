#include "struktura.h"
#include "include.h"
#include "using.h"
#include "Funkcijos.h"
#include "RankinisIvedimas.cpp"
#include "RandomPazymiai.cpp"
#include "RandomStudentai.cpp"
#include "Nuskaitymas.cpp"
#include "Isvedimas.cpp"

void RankinisIvedimas(vector<Studentas>& grupe);
void RandomPazymiai(vector<Studentas>& grupe);
void RandomStudentai(vector<Studentas>& grupe);
void Nuskaitymas(vector<Studentas>& grupe, int &rusiavimas);
void Isvedimas(vector<Studentas>& grupe, int pasirinkimas, int rusiavimas);

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
cin>>pasirinkimas;
if(cin.fail() || pasirinkimas < 1 || pasirinkimas > 4){
    cout<<"Prasome ivesti tik skaicius 1, 2, 3 arba 4!"<<endl;
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
else break;
}
    if(pasirinkimas==1) RankinisIvedimas(grupe);
    else if(pasirinkimas==2) RandomPazymiai(grupe);
    else if(pasirinkimas==3) RandomStudentai(grupe);
    else if(pasirinkimas==4) Nuskaitymas(grupe, rusiavimas);
Isvedimas(grupe, pasirinkimas, rusiavimas);
return 0;
};