#include "Studentas.h"
#include "funkcions.h"
#include "includes.h"

template<typename Container>
void IsvestiIFaila(const Container& grupe, const std::string& failas) {
    ofstream fr(failas);
    fr<<left<<setw(20)<<"Vardas"<<setw(20)<<"Pavarde"<<setw(20)<<"Galutinis\n";
    for(const auto& A : grupe) {
    fr<<left<<setw(20)<<A.vardas()<<setw(20)<<A.pavarde()<<setw(20)<<fixed<<setprecision(2)<<A.rezultatas()<<"\n";
}
    fr.close();
}

template<typename Container>
void Isvedimas(Container& grupe, int pasirinkimas, int rusiavimas) {
Container vargsiukai;
Container kietiakai;

auto pagalVarda = [](const Studentas &a, const Studentas &b) {
return a.vardas() < b.vardas(); };

auto pagalPavarde = [](const Studentas &a, const Studentas &b){
return a.pavarde() < b.pavarde(); };

auto pagalRez = [](const Studentas &a, const Studentas &b){
return a.rezultatas() < b.rezultatas(); };

if(pasirinkimas == 4) { //contexpr - compile time if, kuris leidžia pasirinkti rikiavimo metodą pagal konteinerio tipą
if constexpr (std::is_same<Container, std::list<Studentas>>::value) { //tikrina, ar konteineris yra list, jei taip - naudojamas list sort metodas
    if(rusiavimas==1) grupe.sort(pagalVarda);
    else if(rusiavimas==2) grupe.sort(pagalPavarde);
    else if(rusiavimas==3) grupe.sort(pagalRez);
    else cout<<"Prasome pasirinkti tik 1, 2 arba 3!\n"; }
else {
    if(rusiavimas==1)
std::sort(grupe.begin(), grupe.end(), pagalVarda);
    else if(rusiavimas==2)
std::sort(grupe.begin(), grupe.end(), pagalPavarde);
    else if(rusiavimas==3)
std::sort(grupe.begin(), grupe.end(), pagalRez);
    else cout<<"Prasome pasirinkti tik 1, 2 arba 3!\n"; }
}
else {
    cout<<"Prasome pasirinkti tik 1, 2 arba 3!\n"; }

for(const auto& stud : grupe) {
if(stud.rezultatas() < 5.0)
    vargsiukai.push_back(stud);
else
    kietiakai.push_back(stud); }

IsvestiIFaila(vargsiukai,"vargsiukai.txt");
IsvestiIFaila(kietiakai,"kietiakai.txt");

int isvedimas;
while(true) {
    cout<<"Kur norite matyti rezultatus? \n";
    cout<<"1 - ekrane \n";
    cout<<"2 - faile rezultatai.txt \n";
cin>>isvedimas;
if(cin.fail() || (isvedimas!=1 && isvedimas!=2)) {
    cout<<"Prasome pasirinkti tik skaiciu 1 arba 2! \n";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
else break;
}

auto start = std::chrono::high_resolution_clock::now(); //fiksuojamas tikslus laikas prieš operacijos atlikimą, kad būtų galima apskaičiuoti, kiek laiko užtrunka duomenų išvedimas

if(isvedimas==1) {
    cout<<left<<setw(20)<<"Vardas"<<setw(20)<<"Pavarde"<<setw(20)<<"Galutinis"<<"\n";
for(const auto &A : grupe) {
    cout<<left<<setw(20)<<A.vardas()<<setw(20)<<A.pavarde()<<setw(20)<<fixed<<setprecision(2)<< A.rezultatas()<<"\n";
}
}

else if(isvedimas==2){
ofstream fr("rezultatai.txt");
    fr<<left<<setw(20)<<"Vardas"<<setw(20)<<"Pavarde"<<setw(20)<<"Galutinis"<<"\n";
for(const auto &A : grupe) {
    fr<<left<<setw(20)<<A.vardas()<<setw(20)<<A.pavarde()<<setw(20)<<fixed<<setprecision(2)<<A.rezultatas()<<"\n";
}

fr.close();
    cout<<"Prasome patikrinti faila rezultatai.txt \n";
}

auto end = std::chrono::high_resolution_clock::now(); //fiksuojamas tikslus laikas PO operacijos atlikimo
std::chrono::duration<double> diff = end - start; //parodo, kad laikas bus gražintas sekundėmis, nes naudojama double tipo kintamasis

cout<<"Duomenu isvedimo laikas: "<< diff.count()<<" s \n"; //gražina skirtumą tarp pradžios ir pabaigos laiko sekundėmis
}