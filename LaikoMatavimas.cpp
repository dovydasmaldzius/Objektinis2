#include "structure.h"
#include "funkcions.h"
#include "includes.h"

void LaikoMatavimas() { vector<int> dydziai = {1000,10000,100000,1000000,10000000};

for(int n : dydziai){
string failas = "studentai" + to_string(n) + ".txt";

    cout<<"\n Vector:      \n";
TestuotiGreiti<vector<Studentas>>(failas);
    cout<<"   List:        \n";
TestuotiGreiti<std::list<Studentas>>(failas);
    cout<<"   Deque:       \n";
TestuotiGreiti<std::deque<Studentas>>(failas); }
}