#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "Studentas.h"
#include "Zmogus.h"

TEST_CASE("Galutinis balas skaiciuojamas teisingai") {

    Studentas s;

    s.setEgzaminas(10);

    s.addPaz(8);
    s.addPaz(10);
    s.skaiciuotiRezultata();

    REQUIRE(s.rezultatas() == Catch::Approx(9.6));
}