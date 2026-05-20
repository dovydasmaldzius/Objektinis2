#include "Studentas.h"
#include "funkcions.h"
#include "includes.h"

void LaikoMatavimas()
{
vector<string> failai = {
    "studentai1000.txt",
    "studentai10000.txt",
    "studentai100000.txt",
    "studentai1000000.txt",
    "studentai10000000.txt"
};

for(const auto& f : failai) { //atliekami testai su visais sugeneruotais failais su vectoriaus, listo ir deko konteineriais
    cout<<"VECTOR\n";
TestuotiGreiti<vector<Studentas>>(f);
    cout<<"LIST\n";
TestuotiGreiti<list<Studentas>>(f);
    cout<<"DEQUE\n";
TestuotiGreiti<deque<Studentas>>(f); }
}