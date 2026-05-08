#include "structure.h"
#include "funkcions.h"
#include "includes.h"

void IsvestiIFaila(const vector<Studentas>& grupe, const string& failas) {
ofstream fr(failas);

fr<<left<<setw(20)<<"Vardas"<<setw(20)<<"Pavarde"<<setw(20)<<"Galutinis\n";

for(const auto& A : grupe){
    fr<<left<<setw(20)<<A.vardas<<setw(20)<<A.pavarde<<setw(20)<<fixed<<setprecision(2)<<A.rezultatas<<"\n";
}
fr.close();
}
void Isvedimas(vector<Studentas>& grupe, int pasirinkimas, int rusiavimas) {

    vector<Studentas>vargsiukai;
    vector<Studentas>kietiakai;

Studentas A;

if(pasirinkimas==4) {
    if(rusiavimas==1) {
    sort(grupe.begin(), grupe.end(), [](const Studentas &a, const Studentas &b) {
return a.vardas<b.vardas;
});
}
else if(rusiavimas==2) {
    sort(grupe.begin(), grupe.end(), [](const Studentas &a, const Studentas &b) {
return a.pavarde<b.pavarde;
});
}
else if(rusiavimas==3) {
    sort(grupe.begin(), grupe.end(), [](const Studentas &a, const Studentas &b) {
return a.rezultatas<b.rezultatas;
});
}
else {
    cout<<"Prasome pasirinkti tik 1, 2 arba 3!\n"; }
}
for(const auto& stud : grupe){
    if(stud.rezultatas < 5.0)
vargsiukai.push_back(stud);
    else
kietiakai.push_back(stud);
}

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
    cout<<left<<setw(20)<<A.vardas<<setw(20)<<A.pavarde<<setw(20)<<fixed<<setprecision(2)<< A.rezultatas<<"\n";
}
}

else if(isvedimas==2){
ofstream fr("rezultatai.txt");
    fr<<left<<setw(20)<<"Vardas"<<setw(20)<<"Pavarde"<<setw(20)<<"Galutinis"<<"\n";
for(const auto &A : grupe) {
    fr<<left<<setw(20)<<A.vardas<<setw(20)<<A.pavarde<<setw(20)<<fixed<<setprecision(2)<<A.rezultatas<<"\n";
}

fr.close();
    cout<<"Prasome patikrinti faila rezultatai.txt \n";
}

auto end = std::chrono::high_resolution_clock::now(); //fiksuojamas tikslus laikas PO operacijos atlikimo
std::chrono::duration<double> diff = end - start; //parodo, kad laikas bus gražintas sekundėmis, nes naudojama double tipo kintamasis

cout<<"Duomenu isvedimo laikas: "<< diff.count()<<" s \n"; //gražina skirtumą tarp pradžios ir pabaigos laiko sekundėmis
}