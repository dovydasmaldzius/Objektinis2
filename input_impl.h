#ifndef INPUT_IMPL_H //apsauga nuo kelių įtraukimų
#define INPUT_IMPL_H //apsauga nuo kelių įtraukimų

#include "Studentas.h"
#include "includes.h"

template<typename Container>
void Nuskaitymas(Container& grupe, int &rusiavimas) {
    
    Studentas A;

    cout<<"Kaip norite rusiuoti duomenis? Pasirinkite: \n";
    cout<<"1 - rusiuoti pagal varda \n";
    cout<<"2 - rusiuoti pagal pavarde \n";
    cout<<"3 - rusiuoti pagal galutini rezultata \n";
    cin>>rusiavimas;
std::ifstream fd("kursiokai.txt");
string temp;
getline(fd, temp); //nuskaitoma antraste

while(getline(fd, temp)) { //skaitomos visos kitos eilutės, kol jų yra
    std::stringstream ss(temp); //eilutė paverčiama į srauto objektą, kad būtų galima lengviau išskirti duomenis
ss>>A.vardas()>>A.pavarde(); //iš srauto objekto išskiriami vardas ir pavardė
vector<int> pazymiai; //laikinai saugomi pazymiai
int pazymys;
int sum = 0;

while(ss >> pazymys) {
    pazymiai.push_back(pazymys); //pažymys pridedamas į laikinojo vektoriaus masyvą, kol yra skaitomų pažymių
}
A.egzaminas() = pazymiai.back(); //paima paskutinį pažymį kaip egzamino pažymį
pazymiai.pop_back(); //pašalina paskutinį pažymį iš vektoriaus, nes jis jau yra priskirtas egzaminui
A.paz() = pazymiai; //likusius pažymius priskiria namų darbų pažymiams
for(int paz:A.paz()) { 
sum+=paz;
}

std::sort(A.paz().begin(), A.paz().end()); //surūšiuoja pažymius nuo mažiausio iki didžiausio
int kiekis=A.paz().size();
    if(kiekis % 2 == 0)
A.mediana() = (A.paz()[kiekis/2 - 1] + A.paz()[kiekis/2]) / 2.0;
    else
A.mediana() = A.paz()[kiekis/2];
        // prevent division by zero
    if (!A.paz().empty())
A.rezultatas()=(sum*1.0/A.paz().size())*0.4 + A.egzaminas()*0.6;
    else
A.rezultatas() = 0;
    A.paz().clear(); //išvalomi pažymiai, kad būtų galima įvesti kitam studentui
    grupe.push_back(A); //studentas įdedamas į grupę
}
fd.close(); 
}

#endif //apsauga nuo kelių įtraukimų