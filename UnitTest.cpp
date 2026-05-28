#include "catch_amalgamated.hpp"
#include "Studentas.h"
#include "Zmogus.h"
#include <sstream>

// ...

TEST_CASE("Operator>> reads student data and computes result") { //tikrina, ar operatorius >> teisingai nuskaito studento duomenis
    std::istringstream input("Jonas Jonaitis 7 8 9 10"); //sukuriamas įvesties srautas su studento duomenimis
    Studentas s; // sukuriamas tuščias studentas
    input >> s; // duomenys iš įvesties srauto nuskaitomi į studento objektą

    // REQUIRE - tikrina, ar studento duomenys buvo nuskaitomi teisingai, ir ar galutinis rezultatas buvo apskaičiuotas teisingai
    REQUIRE(s.vardas() == "Jonas"); 
    REQUIRE(s.pavarde() == "Jonaitis");
    REQUIRE(s.egzaminas() == 10);
    REQUIRE(s.paz() == std::vector<int>{7, 8, 9});
    REQUIRE(s.rezultatas() == Catch::Approx(0.4 * 8.0 + 0.6 * 10.0));

}
TEST_CASE("Galutinis balas skaiciuojamas teisingai") {

    Studentas s;

    s.setEgzaminas(10); 

    s.addPaz(8);
    s.addPaz(10);
    s.skaiciuotiRezultata(); // Iškviečiama funkcija, kuri apskaičiuoja galutinį balą

    REQUIRE(s.rezultatas() == Catch::Approx(9.6)); // Catch::Approx naudojamas, kad būtų galima palyginti dviejų skaičių artumą, nes gali būti nedidelių skirtumų
}

TEST_CASE("Copy constructor veikia") {

    Studentas s1; // sukuriamas tuščias studentas

    s1.vardas() = "Jonas";
    s1.pavarde() = "Jonaitis";

    Studentas s2(s1); // sukuriamas naujas studentas, kuris yra kopija s1, naudojant copy constructor

    REQUIRE(s2.vardas() == "Jonas");
    REQUIRE(s2.pavarde() == "Jonaitis");
}

TEST_CASE("Copy assignment veikia") {

    Studentas s1; // sukuriamas tuščias studentas
    s1.vardas() = "Petras";

    Studentas s2; // sukuriamas dar vienas tuščias studentas

    s2 = s1; // s2 priskiriama s1, naudojant copy assignment operator

    REQUIRE(s2.vardas() == "Petras");
}

TEST_CASE("Move constructor veikia") {

    Studentas s1; // sukuriamas tuščias studentas

    s1.vardas() = "Aiste";

    Studentas s2(std::move(s1)); // sukuriamas naujas studentas, kuris perima s1 duomenis, naudojant move constructor

    REQUIRE(s2.vardas() == "Aiste");
}

TEST_CASE("Move assignment veikia") {

    Studentas s1; // sukuriamas tuščias studentas

    s1.vardas() = "Tomas";

    Studentas s2; // sukuriamas dar vienas tuščias studentas

    s2 = std::move(s1); // s2 priskiriama s1, naudojant move assignment operator, todėl s2 perima s1 duomenis, o s1 tampa tuščiu objektu

    REQUIRE(s2.vardas() == "Tomas");
}