#include "Studentas.h"
#include "funkcions.h"
#include "includes.h"

void LaikoMatavimas()
{
    std::vector<string> failai = {
"studentai1000.txt",
"studentai10000.txt",
"studentai100000.txt",
"studentai1000000.txt",
"studentai10000000.txt"
};

for(const auto& f : failai) {
    cout << "=== " << f << " ===\n";
    cout << "SU VECTOR (Vector<Studentas>)\n";
TestuotiGreiti<vector<Studentas>>(f);
    cout << "SU STD VECTOR (std::vector<Studentas>)\n";
TestuotiGreiti<std::vector<Studentas>>(f);
    cout << "\n";
}
}