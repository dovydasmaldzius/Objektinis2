#include "structure.h"
#include "funkcions.h"
#include "includes.h"

void LaikoMatavimas() { vector<int> dydziai = {1000,10000,100000,1000000,10000000};

for(int n : dydziai){
cout << "\nFailas uzdarytas\n";
string failas = "studentai" + to_string(n) + ".txt";
vector<Studentas> grupe;
vector<Studentas> vargsiukai;
vector<Studentas> kietiakiai;

auto total_start = std::chrono::high_resolution_clock::now(); // Pradedame matuoti bendrą laiką nuo pradžios iki pabaigos

auto start = std::chrono::high_resolution_clock::now(); // Pradedame matuoti laiką nuskaitymui

auto end = std::chrono::high_resolution_clock::now(); // Baigiame matuoti laiką nuskaitymui

    cout<<n<<" irasu nuskaitymo laikas: "<<std::chrono::duration<double>(end-start).count()<<endl;
start = std::chrono::high_resolution_clock::now(); // Pradedame matuoti laiką rikiavimui
NuskaitymasIsFailo(failas, grupe);

sort(grupe.begin(), grupe.end(), [](const Studentas& a, const Studentas& b) {
return a.rezultatas < b.rezultatas;});

end = std::chrono::high_resolution_clock::now(); // Baigiame matuoti laiką rikiavimui

cout << n << " irasu rusiavimas didejimo tvarka laikas (su sort funkcija): " << std::chrono::duration<double>(end-start).count()<<endl;

start = std::chrono::high_resolution_clock::now(); // Pradedame matuoti laiką dalijimui i dvi grupes

for(const auto& s : grupe) {
    if(s.rezultatas >= 5.0)
kietiakiai.push_back(s);
    else
vargsiukai.push_back(s);
}

grupe.clear();

end = std::chrono::high_resolution_clock::now(); // Baigiame matuoti laiką dalijimui i dvi grupes

    cout<<n<<" irasu dalijimo i dvi grupes laikas, panaikinant pradini vector: "<<std::chrono::duration<double>(end-start).count()<<endl;

start = std::chrono::high_resolution_clock::now(); // Pradedame matuoti laiką vargšiukų irašymui į failą

ofstream fr("vargsiukai" + to_string(n) + ".txt");
for(const auto& s : vargsiukai)
    fr << s.vardas << " " << s.pavarde << " " << s.rezultatas << "\n";
    fr.close();

end = std::chrono::high_resolution_clock::now(); // Baigiame matuoti laiką vargsiuku irasymui i faila

    cout<<n<<" irasu vargsiuku irasymo i faila laikas: "<<std::chrono::duration<double>(end-start).count() << endl;
start = std::chrono::high_resolution_clock::now(); //Pradedame matuoti laiką kietekų irašymui į failą

ofstream rf("kietiakiai" + to_string(n) + ".txt");
for(const auto& s : kietiakiai)
    rf << s.vardas << " " << s.pavarde << " " << s.rezultatas << "\n";
    rf.close();

end = std::chrono::high_resolution_clock::now(); // Baigiame matuoti laiką kieteku irašymui į failą

    cout << n << " irasu kieteku irasymo i faila laikas: " << std::chrono::duration<double>(end-start).count() << endl;
auto total_end = std::chrono::high_resolution_clock::now(); // Baigiame matuoti bendrą laiką nuo pradžios iki pabaigos
    cout << n << " irasu bendras testo laikas: " << std::chrono::duration<double>(total_end-total_start).count() << endl;
}
}