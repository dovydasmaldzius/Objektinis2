#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <ctime>
#include <fstream>
#include <chrono>
#include <sstream>

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
using std::ifstream;
using std::getline;
using std::ofstream;


struct Studentas {
string vardas="A",pavarde="B";
vector<int>paz; //vektorių masyvas su namų darbų pažymiais
int egzaminas;
double rezultatas=0;
double mediana=0;
};

int main() {
    std::ios::sync_with_stdio(false); //duomenų srauto sinchronizavimas su C funkcijomis išjungiamas, kad būtų pasiektas didesnis efektyvumas
    srand(time(NULL)); //naudojamas, kad funkcija rand() kiekvieną kartą generuotų ne tas pačias reikšmes
int pasirinkimas;
int rusiavimas;
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

if(pasirinkimas==1) {
    while(true) {
    cout << "kiek yra studentu? \n";
cin>>m;
if(cin.fail() || m < 0) { 
    cout<<"Prasome ivesti tik naturaliuosius skaicius! \n";
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
    else break; }

for(int ii=0; ii<m; ii++) {
while(true) {
    cout<<"Iveskite varda ir pavarde: \n";
cin>>A.vardas>>A.pavarde;
bool hasDigit = std::any_of(A.vardas.begin(), A.vardas.end(), [](unsigned char c){ return std::isdigit(c); }) || std::any_of(A.pavarde.begin(), A.pavarde.end(), [](unsigned char c){ return std::isdigit(c); });
if(hasDigit) {
    cout << "Prasome ivesti varda ir pavarde dar karta \n";
    continue; }
    break;
}

int n;
while(true) { //ciklas, kuris veikia iki tol, kol vartotojas įves klaidingą reikšmę
    cout<<"iveskite pazymiu skaiciu: \n";
cin>>n;
if(cin.fail() || n < 0) {
    cout<<"Prasome ivesti tik naturaliuosius skaicius! \n";
cin.clear(); //klaida pašalinama
cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
    else break; } //baigiamas ciklas, jei įvestis teisinga
        
int temp; //laikinas pažymys
int sum=0;

for(int i=0;i<n;i++) {
while(true) {
    cout<<"iveskite pazymi: \n";
cin>>temp;
if(cin.fail() || temp < 1 || temp > 10) {
    cout<<"Prasome ivesti tik skaicius nuo 1 iki 10! \n";
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
    else {
A.paz.push_back(temp); //pažymys pridedamas į studento pažymių vektorių
sum+=temp; //pažymys pridedamas prie sumos
break; } //baigiasi ciklas, jei įvestis teisinga
}
}

while(true) {
    cout<<"iveskite egzamino pazymi: \n";
cin>>A.egzaminas;
if(cin.fail() || A.egzaminas < 1 || A.egzaminas > 10) {
    cout<<"Prasome ivesti tik skaicius nuo 1 iki 10! \n";
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
    else break; 
}

A.paz.push_back(A.egzaminas); //laikinai įdedame egzamino pažymį į pažymių vektoriu, tam, kad galėtume teisingai apskaičiuoti medianą

sort(A.paz.begin(), A.paz.end()); //pažymiai surikiuojami, kad būtų galima apskaičiuoti medianą

int kiekis = A.paz.size(); //skaičiuojama, kiek yra pažymių

if(kiekis == 0) A.mediana = 0; //jei pažymių nėra - mediana lygi 0
else if(kiekis % 2 == 0) A.mediana = (A.paz[kiekis/2 - 1] + A.paz[kiekis/2]) / 2.0; //jei pažymių skaičius yra lyginis - skaičiuojama mediana kaip dviejų vidurinių skaičių vidurkis
else A.mediana = A.paz[kiekis/2]; //jei pažymių skaičius yra nelyginis - medana yra vidurinis skaičius
A.paz.pop_back(); //pašalinamas egzamino pažymys iš pažymių vektoraus, nes jo reikėjo tik medianos skaičiavimui

A.rezultatas=sum*1.0/(n*1.0)*0.4+A.egzaminas*0.6;
grupe.push_back(A);
A.paz.clear(); }//išvalomi pažymiai, kad juos būtų galima įvesti kitam studentui
}




else if(pasirinkimas==2) {
    while(true) {
    cout << "kiek yra studentu? \n";
cin>>m;
if(cin.fail() || m < 0) { 
    cout<<"Prasome ivesti tik naturaliuosius skaicius! \n";
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
    else break; }

for(int ii=0; ii<m; ii++){
while(true) {
    cout<<"Iveskite varda ir pavarde \n";
cin>>A.vardas>>A.pavarde;
bool hasDigit = std::any_of(A.vardas.begin(), A.vardas.end(), [](unsigned char c){ return std::isdigit(c); }) || std::any_of(A.pavarde.begin(), A.pavarde.end(), [](unsigned char c){ return std::isdigit(c); });
if(hasDigit) {
    cout << "Prasome ivesti varda ir pavarde dar karta \n";
    continue; }
    break;
}
int n;
while(true) {
    cout<<"iveskite pazymiu skaiciu: \n";
cin>>n;
if(cin.fail() || n < 0) {
    cout<<"Prasome ivesti tik naturaliuosius skaicius! \n";
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
    else break; }
        
int sum=0;

    cout<<"Atsiktinai sugeneruoti "<<ii+1<<" - ojo studento pazymiai: \n";
for(int i=0;i<n;i++) {
int temp = (rand() % 10) + 1;
A.paz.push_back(temp);
sum+=temp;
    cout<<temp<<" ";
    cout<<endl; }
        
A.egzaminas = (rand() % 10) + 1;
    cout<<"Atsitiktinai sugeneruotas "<<ii+1<<" - ojo studento egzamino pazymys: "<<A.egzaminas<<"\n";

A.paz.push_back(A.egzaminas);
        
sort(A.paz.begin(), A.paz.end());
        
int kiekis = A.paz.size();
        
if(kiekis == 0) A.mediana = 0;
else if(kiekis % 2 == 0) A.mediana = (A.paz[kiekis/2 - 1] + A.paz[kiekis/2]) / 2.0;
else A.mediana = A.paz[kiekis/2];
A.paz.pop_back();
        
A.rezultatas=sum*1.0/(n*1.0)*0.4+A.egzaminas*0.6;
grupe.push_back(A);
A.paz.clear(); }
}




else if(pasirinkimas==3) {
    while(true) {
    cout << "kiek yra studentu? \n";
cin>>m;
if(cin.fail() || m < 0) { 
    cout<<"Prasome ivesti tik naturaliuosius skaicius! \n";
cin.clear();
cin.ignore(numeric_limits<streamsize>::max(), '\n'); }
    else break; }

vector<string> firstNames={"Jonas","Petras","Ona","Lina","Mantas","Egle","Darius","Ruta","Tomas","Ieva"};
vector<string> lastNames={"Petraitis","Kazlauskas","Jankauskas","Stankevicius","Vilkas","Daugela","Miskinis","Jankauskiene","Zalys","Baranauskas"};
for(int ii=0; ii<m; ii++) {
A.vardas = firstNames[rand() % firstNames.size()];
A.pavarde = lastNames[rand() % lastNames.size()];

    int n=(rand() % 10)+1;
    int sum=0;

    cout<<"Atsiktinai sugeneruoti "<<ii+1<<" - ojo studento pazymiai: \n";
for(int i=0; i<n; i++) {
    int temp = (rand() % 10)+1;
A.paz.push_back(temp);
    sum += temp;
    
    cout<<temp<<" ";
    cout<<"\n";}

A.egzaminas = (rand() % 10) + 1;
    cout<<"Atsitiktinai sugeneruotas "<<ii+1<<" - ojo studento egzamino pazymys: "<<A.egzaminas<<"\n";

A.paz.push_back(A.egzaminas);

sort(A.paz.begin(), A.paz.end());

int kiekis = A.paz.size();

if(kiekis == 0) A.mediana = 0;
else if(kiekis % 2 == 0) A.mediana = (A.paz[kiekis/2 - 1] + A.paz[kiekis/2]) / 2.0;
else A.mediana = A.paz[kiekis/2];

A.paz.pop_back();

A.rezultatas = sum*1.0/(n*1.0)*0.4 + A.egzaminas*0.6;
grupe.push_back(A);
A.paz.clear(); }
}




else if(pasirinkimas==4) {
    cout<<"Kaip norite rusiuoti duomenis? Pasirinkite: \n";
    cout<<"1 - rusiuoti pagal galutini rezultata \n";
    cout<<"2 - rusiuoti pagal mediana \n";
cin>>rusiavimas;
std::ifstream fd("kursiokai.txt");
string temp;
getline(fd, temp); //nuskaitoma antraste

while(getline(fd, temp)) { //skaitomos visos kitos eilutės, kol jų yra
    std::stringstream ss(temp); //eilutė paverčiama į srauto objektą, kad būtų galima lengviau išskirti duomenis
ss>>A.vardas>>A.pavarde;
vector<int> pazymiai; //laikinai saugomi pazymiai
    int pazymys;
    int sum = 0;

    while(ss >> pazymys) {
pazymiai.push_back(pazymys); //pažymys pridedamas į laikinojo vektoriaus masyvą, kol yra skaitomų pažymių
}
    A.egzaminas=pazymiai.back(); //paima paskutinį pažymį kaip egzamino pažymį
    pazymiai.pop_back(); //pašalina paskutinį pažymį iš vektoriaus, nes jis jau yra priskirtas egzaminui
    A.paz=pazymiai; //likusius pažymius priskiria namų darbų pažymiams
for(int paz:A.paz) { 
sum+=paz;
}

sort(A.paz.begin(), A.paz.end()); //surūšiuoja pažymius nuo mažiausio iki didžiausio
    int kiekis=A.paz.size();
if(kiekis % 2 == 0)
    A.mediana = (A.paz[kiekis/2 - 1] + A.paz[kiekis/2]) / 2.0;
else
    A.mediana = A.paz[kiekis/2];

    A.rezultatas=(sum*1.0/A.paz.size())*0.4 + A.egzaminas*0.6;
    A.paz.clear(); //išvalomi pažymiai, kad būtų galima įvesti kitam studentui
    grupe.push_back(A); //studentas įdedamas į grupę
}
fd.close(); 
}




if(pasirinkimas==4) {
    if(rusiavimas==1) {
    sort(grupe.begin(), grupe.end(), [](const Studentas &a, const Studentas &b) {
return a.rezultatas>b.rezultatas;
});
}
else if(rusiavimas==2) {
    sort(grupe.begin(), grupe.end(), [](const Studentas &a, const Studentas &b) {
return a.mediana>b.mediana;
});
}
else {
    cout<<"Prasome pasirinkti tik 1 arba 2!\n"; }
}




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
    cout << left << setw(20) << "Vardas" << setw(20) << "Pavarde";
if(pasirinkimas==4) {
if(rusiavimas==1)
    cout << setw(20) << "Galutinis";
else
    cout << setw(20) << "Mediana"; 
}
else {
    cout << setw(20) << "Galutinis" << setw(20) << "Mediana";
}
    cout<<"\n";

for(const auto &A:grupe) { //naudojama esamo objekto grupe tik adresas, kad būtų galima išvengti nereikalingo kopijavimo
    cout << left << setw(20) << A.vardas << setw(20) << A.pavarde;
if(pasirinkimas==4) {
if(rusiavimas==1)
    cout << setw(20) << fixed << setprecision(2) << A.rezultatas;
else
    cout << setw(20) << A.mediana;
}
else {
    cout << setw(20) << fixed << setprecision(2) << A.rezultatas << setw(20) << A.mediana;
}
    cout<<"\n";
}
}

else if(isvedimas==2){
ofstream fr("rezultatai.txt");
fr<<left<<setw(20)<<"Vardas"<<setw(20)<<"Pavarde";

if(pasirinkimas==4) {
if(rusiavimas==1)
    fr<<setw(20)<<"Galutinis";
else
    fr<<setw(20)<<"Mediana";
}
else {
    fr<<setw(20)<<"Galutinis"<<setw(20)<<"Mediana";
}
    fr<<"\n";

for(const auto &A:grupe) { //naudojama esamo objekto grupe tik adresas, kad būtų galima išvengti nereikalingo kopijavimo
    fr<<left<<setw(20)<<A.vardas<<setw(20)<<A.pavarde;

if(pasirinkimas==4) {
if(rusiavimas==1)
    fr<<setw(20)<<fixed<<setprecision(2)<<A.rezultatas;
else
    fr<<setw(20)<<A.mediana;
}
else {
    fr<<setw(20)<<fixed<<setprecision(2)<<A.rezultatas<<setw(20)<<A.mediana;
}
    fr<<"\n";
}

fr.close();
    cout<<"Prasome patikrinti faila rezultatai.txt \n";
}

auto end = std::chrono::high_resolution_clock::now(); //fiksuojamas tikslus laikas PO operacijos atlikimo
std::chrono::duration<double> diff = end - start; //parodo, kad laikas bus gražintas sekundėmis, nes naudojama double tipo kintamasis

cout<<"Duomenu isvedimo laikas: "<< diff.count()<<" s \n"; //gražina skirtumą tarp pradžios ir pabaigos laiko sekundėmis

    return 0;
};