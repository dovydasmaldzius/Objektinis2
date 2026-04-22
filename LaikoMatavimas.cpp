#include "structure.h"
#include "funkcions.h"
#include "includes.h"

void LaikoMatavimas() { vector<int> dydziai = {1000,10000,100000,1000000,10000000};

for(int n:dydziai){
cout << "\nFailas uzdarytas\n";
string failas = "studentai" + to_string(n) + ".txt";
vector<Studentas> grupe;
vector<Studentas> vargsiukai;
vector<Studentas> kietiakiai;

auto total_start = std::chrono::high_resolution_clock::now();

auto start = std::chrono::high_resolution_clock::now();

auto end = std::chrono::high_resolution_clock::now();

    cout << n << " irasu nuskaitymo laikas: " << std::chrono::duration<double>(end-start).count() << endl;
start = std::chrono::high_resolution_clock::now();
NuskaitymasIsFailo(failas, grupe);

sort(grupe.begin(), grupe.end(), [](const Studentas& a, const Studentas& b){
return a.rezultatas < b.rezultatas;});

end = std::chrono::high_resolution_clock::now();

cout << n << " irasu rusiavimas didejimo tvarka laikas (su sort funkcija): " << std::chrono::duration<double>(end-start).count() << endl;

start = std::chrono::high_resolution_clock::now();

auto it = partition(grupe.begin(), grupe.end(), [](const Studentas& s){ 
return s.rezultatas >= 5.0;});

kietiakiai.assign(grupe.begin(), it);
vargsiukai.assign(it, grupe.end());

grupe.clear();

end = std::chrono::high_resolution_clock::now();

    cout << n << " irasu dalijimo i dvi grupes laikas, panaikinant pradini vector: " << std::chrono::duration<double>(end-start).count() << endl;

start = std::chrono::high_resolution_clock::now();

ofstream fv("vargsiukai" + to_string(n) + ".txt");
for(const auto& s : vargsiukai)
    fv << s.vardas << " " << s.pavarde << " " << s.rezultatas << "\n";
    fv.close();

end = std::chrono::high_resolution_clock::now();

    cout << n << " irasu vargsiuku irasymo i faila laikas: " << std::chrono::duration<double>(end-start).count() << endl;
start = std::chrono::high_resolution_clock::now();

ofstream fk("kietiakiai" + to_string(n) + ".txt");
for(const auto& s : kietiakiai)
    fk << s.vardas << " " << s.pavarde << " " << s.rezultatas << "\n";
    fk.close();

end = std::chrono::high_resolution_clock::now();

    cout << n << " irasu kieteku irasymo i faila laikas: " << std::chrono::duration<double>(end-start).count() << endl;
auto total_end = std::chrono::high_resolution_clock::now();
    cout << n << " irasu bendras testo laikas: " << std::chrono::duration<double>(total_end-total_start).count() << endl;
}
}