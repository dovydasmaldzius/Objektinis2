#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "Vector.h"
#include <string>

TEST_CASE("Default constructor creates empty vector") { //tikrina, ar numatytasis konstruktorius sukuria tuščią vektorių
    Vector<int> v;
    REQUIRE(v.empty());
    REQUIRE(v.size() == 0);
    REQUIRE(v.capacity() == 0);
}

TEST_CASE("Constructor with size n") { //tikrina, ar konstruktorius su parametru n sukuria vektorių su n elementų (nu numatytomis reikšmėmis)
    Vector<int> v(5);
    REQUIRE(v.size() == 5);
    REQUIRE(v.capacity() == 5);
    for (int i = 0; i < 5; ++i) {
        REQUIRE(v[i] == 0);
    }
}

TEST_CASE("Constructor with size and value") { //tikrina, ar konstruktorius su parametrais n ir value sukuria vektorių su n elementų, kurių kiekvienas yra lygus value
    Vector<int> v(3, 42);
    REQUIRE(v.size() == 3);
    REQUIRE(v[0] == 42);
    REQUIRE(v[1] == 42);
    REQUIRE(v[2] == 42);
}

TEST_CASE("Constructor with initializer list") { //tikrina, ar konstruktorius su initializer list sukuria vektorių su elementais, nurodytais sąraše
    Vector<int> v = {1, 2, 3, 4, 5};
    REQUIRE(v.size() == 5);
    REQUIRE(v[0] == 1);
    REQUIRE(v[4] == 5);
}

TEST_CASE("Range constructor with iterators") { //tikrina, ar konstruktorius su iteratorių pora sukuria vektorių su elementais, esančiais tarp nurodytų iteratorių
    std::vector<int> stdv = {10, 20, 30, 40};
    Vector<int> v(stdv.begin(), stdv.end());
    REQUIRE(v.size() == 4);
    REQUIRE(v[0] == 10);
    REQUIRE(v[3] == 40);
}

TEST_CASE("Copy constructor") { //tikrina, ar kopijavimo konstruktorius sukuria naują vektorių, kuris yra lygus originalui, bet turi atskirą atmintį
    Vector<int> v1 = {1, 2, 3};
    Vector<int> v2(v1);
    REQUIRE(v2.size() == v1.size());
    REQUIRE(v2[0] == 1);
    REQUIRE(v2[2] == 3);
    
    v2[0] = 999;
    REQUIRE(v1[0] == 1);
}

TEST_CASE("Move constructor") { //tikrina, ar perkėlimo konstruktorius sukuria naują vektorių, kuris yra lygus originalui, bet turi atskirą atmintį
    Vector<int> v1 = {1, 2, 3};
    Vector<int> v2(std::move(v1));
    REQUIRE(v2.size() == 3);
    REQUIRE(v2[0] == 1);
    REQUIRE(v1.size() == 0);
}

TEST_CASE("Copy assignment operator") { //tikrina, ar kopijavimo priskyrimo operatorius priskiria vieno vektoriaus turinį kitam, o originalas lieka nepakitęs
    Vector<int> v1 = {1, 2, 3};
    Vector<int> v2 = {10, 20};
    v2 = v1;
    REQUIRE(v2.size() == 3);
    REQUIRE(v2[0] == 1);
    REQUIRE(v2[2] == 3);
}

TEST_CASE("Move assignment operator") { //tikrina, ar perkėlimo priskyrimo operatorius priskiria vieno vektoriaus turinį kitam
    Vector<int> v1 = {1, 2, 3};
    Vector<int> v2 = {10, 20};
    v2 = std::move(v1);
    REQUIRE(v2.size() == 3);
    REQUIRE(v2[0] == 1);
    REQUIRE(v1.size() == 0);
}

TEST_CASE("Initializer list assignment") { //tikrina, ar priskyrimo operatorius su initializer list priskiria vektoriui elementus, nurodytus sąraše
    Vector<int> v;
    v = {5, 10, 15};
    REQUIRE(v.size() == 3);
    REQUIRE(v[1] == 10);
}




TEST_CASE("operator[] for access") { //tikrina, ar operator[] teisingai grąžina elementus pagal indeksą
    Vector<int> v = {10, 20, 30};
    REQUIRE(v[0] == 10);
    REQUIRE(v[1] == 20);
    REQUIRE(v[2] == 30);
}

TEST_CASE("operator[] for modification") { //tikrina, ar operator[] leidžia modifikuoti elementus pagal indeksą
    Vector<int> v = {1, 2, 3};
    v[1] = 99;
    REQUIRE(v[1] == 99);
}

TEST_CASE("at() function for access") { //tikrina, ar at() teisingai grąžina elementus pagal indeksą
    Vector<int> v = {10, 20, 30};
    REQUIRE(v.at(0) == 10);
    REQUIRE(v.at(2) == 30);
}

TEST_CASE("at() throws exception for out of range") { //tikrina, ar at() metodas išmesto išimtį, kai indeksas yra už ribų
    Vector<int> v = {1, 2, 3};
    REQUIRE_THROWS_AS(v.at(5), std::out_of_range);
}

TEST_CASE("front() and back()") { //tikrina, ar front() ir back() metodai teisingai grąžina pirmą ir paskutinį elementą

    Vector<int> v = {10, 20, 30};
    REQUIRE(v.front() == 10);
    REQUIRE(v.back() == 30);
}

TEST_CASE("data() pointer access") { //tikrina, ar data() metodas grąžina teisingą rodyklę į vidinį masyvą, leidžiantį tiesiogiai pasiekti elementus
    Vector<int> v = {1, 2, 3};
    int* ptr = v.data();
    REQUIRE(ptr[0] == 1);
    REQUIRE(ptr[2] == 3);
}




TEST_CASE("size() returns correct number of elements") { //tikrina, ar size() metodas grąžina teisingą elementų skaičių
    Vector<int> v;
    REQUIRE(v.size() == 0);
    v.push_back(1);
    REQUIRE(v.size() == 1);
    v.push_back(2);
    REQUIRE(v.size() == 2);
}

TEST_CASE("empty() returns true for empty vector") { //tikrina, ar empty() metodas grąžina true, kai vektorius yra tuščias, ir false, kai jame yra elementų
    Vector<int> v;
    REQUIRE(v.empty());
    v.push_back(1);
    REQUIRE(!v.empty());
}

TEST_CASE("capacity() grows when needed") { //tikrina, ar capacity() metodas grąžina teisingą talpą, ir ar vektorius automatiškai auga, kai pasiekiama dabartinė talpa
    Vector<int> v;
    auto initial_cap = v.capacity();
    REQUIRE(initial_cap == 0);
    
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    REQUIRE(v.capacity() >= 10);
}

TEST_CASE("reserve() allocates specified capacity") { //tikrina, ar reserve() metodas rezervuoja nurodytą talpą, ir ar vektorius gali saugoti tiek elementų be papildomos realokacijos
    Vector<int> v;
    v.reserve(100);
    REQUIRE(v.capacity() >= 100);
    REQUIRE(v.size() == 0);
}

TEST_CASE("shrink_to_fit() reduces capacity") { //tikrina, ar shrink_to_fit() metodas sumažina talpą iki elementų skaičiaus, ir ar vektorius vis tiek saugo visus elementus po šios operacijos
    Vector<int> v;
    v.reserve(100);
    REQUIRE(v.capacity() >= 100);
    
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.shrink_to_fit();
    REQUIRE(v.capacity() == v.size());
    REQUIRE(v.size() == 3);
}




TEST_CASE("push_back() adds element to end") { //tikrina, ar push_back() metodas prideda elementą į vektoriaus pabaigą
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    REQUIRE(v.size() == 3);
    REQUIRE(v[0] == 10);
    REQUIRE(v[1] == 20);
    REQUIRE(v[2] == 30);
}

TEST_CASE("push_back() with rvalue reference") { //tikrina, ar push_back() metodas su rvalue reference (perkeliamu argumentu) teisingai perkelia elementą į vektorių, o ne kopijuoja jį
    Vector<std::string> v;
    std::string s("hello");
    v.push_back(std::move(s));
    REQUIRE(v.size() == 1);
    REQUIRE(v[0] == "hello");
}

TEST_CASE("push_back() triggers reallocation") { //tikrina, ar push_back() metodas sukelia realokaciją, kai pasiekiama dabartinė talpa, ir ar vektorius vis tiek saugo visus elementus po realokacijos
    Vector<int> v;
    size_t reallocs = v.get_reallocation_count();
    for (int i = 0; i < 100; ++i) {
        v.push_back(i);
    }
    REQUIRE(v.get_reallocation_count() > reallocs);
    REQUIRE(v.size() == 100);
}

TEST_CASE("pop_back() removes last element") { //tikrina, ar pop_back() metodas pašalina paskutinį elementą iš vektoriaus, sumažina dydį
    Vector<int> v = {10, 20, 30};
    v.pop_back();
    REQUIRE(v.size() == 2);
    REQUIRE(v.back() == 20);
    
    v.pop_back();
    REQUIRE(v.size() == 1);
    REQUIRE(v.back() == 10);
}

TEST_CASE("emplace_back() constructs element in place") { //tikrina, ar emplace_back() metodas sukuria elementą tiesiogiai vektoriaus viduje, be papildomo kopijavimo ar perkėlimo, ir ar jis teisingai perduoda argumentus į elemento konstruktorių
    Vector<std::string> v;
    v.emplace_back(5, 'a');
    REQUIRE(v.size() == 1);
    REQUIRE(v[0] == "aaaaa");
}




TEST_CASE("insert() single element at position") { //tikrina, ar insert() metodas įterpia vieną elementą į nurodytą poziciją, perkelia esamus elementus, jei reikia, ir grąžina iteratorių į naujai įterptą elementą
    Vector<int> v = {1, 2, 4, 5};
    auto it = v.insert(v.cbegin() + 2, 3);
    REQUIRE(*it == 3);
    REQUIRE(it == v.begin() + 2);
    REQUIRE(v.size() == 5);
    REQUIRE(v[2] == 3);
    REQUIRE(v[3] == 4);
    REQUIRE(v[4] == 5);
}

TEST_CASE("insert() multiple copies of element") { //tikrina, ar insert() metodas perkelia esamus elementus, jei reikia, ir grąžina iteratorių į pirmą naujai įterptą elementą
    Vector<int> v = {1, 5};
    v.insert(v.cbegin() + 1, 3, 99);
    REQUIRE(v.size() == 5);
    REQUIRE(v[1] == 99);
    REQUIRE(v[2] == 99);
    REQUIRE(v[3] == 99);
    REQUIRE(v[4] == 5);
}

TEST_CASE("insert() range from another container") { //tikrina, ar insert() metodas įterpia elementus iš kito konteinerio intervalo, perkelia esamus elementus, jei reikia, ir grąžina iteratorių į pirmą naujai įterptą elementą
    Vector<int> v = {1, 5};
    std::vector<int> vals = {2, 3, 4};
    v.insert(v.cbegin() + 1, vals.begin(), vals.end());
    REQUIRE(v.size() == 5);
    REQUIRE(v[1] == 2);
    REQUIRE(v[2] == 3);
    REQUIRE(v[3] == 4);
}

TEST_CASE("insert() initializer list") { //tikrina, ar insert() metodas įterpia elementus iš initializer list, perkelia esamus elementus, jei reikia, ir grąžina iteratorių į pirmą naujai įterptą elementą
    Vector<int> v = {1, 5};
    v.insert(v.cbegin() + 1, {2, 3, 4});
    REQUIRE(v.size() == 5);
    REQUIRE(v[1] == 2);
    REQUIRE(v[3] == 4);
}





TEST_CASE("erase() single element") { //tikrina, ar erase() metodas pašalina vieną elementą iš nurodytos pozicijos ir perkelia esamus elementus
    Vector<int> v = {1, 2, 3, 4, 5};
    v.erase(v.cbegin() + 2);
    REQUIRE(v.size() == 4);
    REQUIRE(v[2] == 4);
    REQUIRE(v[3] == 5);
}

TEST_CASE("erase() range of elements") { //tikrina, ar erase() metodas pašalina elementų intervalą iš vektoriaus ir perkelia esamus elementus
    Vector<int> v = {1, 2, 3, 4, 5}; 
    v.erase(v.cbegin() + 1, v.cbegin() + 4);
    REQUIRE(v.size() == 2);
    REQUIRE(v[0] == 1);
    REQUIRE(v[1] == 5);
}

TEST_CASE("erase() all elements") { //tikrina, ar erase() metodas pašalina visus elementus iš vektoriaus, palikdamas jį tuščią
    Vector<int> v = {1, 2, 3};
    v.erase(v.cbegin(), v.cend());
    REQUIRE(v.empty());
    REQUIRE(v.size() == 0);
}




TEST_CASE("resize() increases size with default values") { //tikrina, ar resize() metodas padidina vektoriaus dydį iki n, užpildydamas naujus elementus numatytomis reikšmėmis
    Vector<int> v = {1, 2};
    v.resize(5);
    REQUIRE(v.size() == 5);
    REQUIRE(v[2] == 0);
    REQUIRE(v[3] == 0);
    REQUIRE(v[4] == 0);
}

TEST_CASE("resize() increases size with specified value") { //tikrina, ar resize() metodas padidina vektoriaus dydį iki n, užpildydamas naujus elementus nurodyta reikšme
    Vector<int> v = {1, 2};
    v.resize(5, 99);
    REQUIRE(v.size() == 5);
    REQUIRE(v[2] == 99);
    REQUIRE(v[3] == 99);
    REQUIRE(v[4] == 99);
}

TEST_CASE("resize() decreases size") { //tikrina, ar resize() metodas sumažina vektoriaus dydį iki n, pašalindamas elementus iš pabaigos
    Vector<int> v = {1, 2, 3, 4, 5};
    v.resize(3);
    REQUIRE(v.size() == 3);
    REQUIRE(v[0] == 1);
    REQUIRE(v[2] == 3);
}

TEST_CASE("assign() with count and value") { //tikrina, ar assign() metodas priskiria vektoriui n elementų, kurių kiekvienas yra lygus value
    Vector<int> v = {1, 2, 3};
    v.assign(4, 42);
    REQUIRE(v.size() == 4);
    REQUIRE(v[0] == 42);
    REQUIRE(v[3] == 42);
}

TEST_CASE("assign() with range") { //tikrina, ar assign() metodas priskiria vektoriui elementus iš nurodyto intervalo
    Vector<int> v = {1, 2, 3};
    std::vector<int> src = {10, 20, 30, 40};
    v.assign(src.begin(), src.end());
    REQUIRE(v.size() == 4);
    REQUIRE(v[0] == 10);
    REQUIRE(v[3] == 40);
}





TEST_CASE("clear() empties the vector") { //tikrina, ar clear() metodas išvalo vektorių, palikdamas jį tuščią, ir ar dydis tampa 0
    Vector<int> v = {1, 2, 3};
    v.clear();
    REQUIRE(v.empty());
    REQUIRE(v.size() == 0);
    // Talpa gali likti nepakitusi, todėl jos netikriname
}

TEST_CASE("swap() exchanges contents") { //tikrina, ar swap() metodas apsikeičia dviejų vektorių turiniu, įskaitant elementus, dydį ir talpą
    Vector<int> v1 = {1, 2, 3};
    Vector<int> v2 = {10, 20};
    v1.swap(v2);
    
    REQUIRE(v1.size() == 2);
    REQUIRE(v1[0] == 10);
    REQUIRE(v1[1] == 20);
    
    REQUIRE(v2.size() == 3);
    REQUIRE(v2[0] == 1);
    REQUIRE(v2[2] == 3);
}




TEST_CASE("Iterator traversal") { //tikrina, ar iteratoriai leidžia teisingai pereiti per vektoriaus elementus nuo pradžios iki pabaigos
    Vector<int> v = {10, 20, 30}; //traversal - tai procesas, kai pereiname per visus elementus vieną po kito
    int sum = 0;
    for (auto it = v.begin(); it != v.end(); ++it) {
        sum += *it;
    }
    REQUIRE(sum == 60);
}

TEST_CASE("Const iterator") { //tikrina, ar const iteratoriai leidžia teisingai pereiti per vektoriaus elementus
    Vector<int> v = {1, 2, 3};
    int sum = 0;
    for (auto it = v.cbegin(); it != v.cend(); ++it) {
        sum += *it;
    }
    REQUIRE(sum == 6);
}

TEST_CASE("Range-based for loop") { //tikrina, ar range-based for loop veikia su vektoriaus iteratoriais, leidžiant lengvai pereiti per elementus
    Vector<int> v = {1, 2, 3}; //range-based for loop - tai sintaksė, leidžianti lengvai pereiti per visus elementus konteinerio, nereikalaujant rankinio iteratoriaus valdymo
    int sum = 0;
    for (int x : v) {
        sum += x;
    }
    REQUIRE(sum == 6);
}

TEST_CASE("Reverse iterator") { //tikrina, ar reverse iteratoriai leidžia teisingai pereiti per vektoriaus elementus nuo pabaigos iki pradžios
    Vector<int> v = {1, 2, 3};
    Vector<int> reversed;
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        reversed.push_back(*it);
    }
    REQUIRE(reversed[0] == 3);
    REQUIRE(reversed[1] == 2);
    REQUIRE(reversed[2] == 1);
}

TEST_CASE("Iterator arithmetic") { //tikrina, ar iteratoriai leidžia teisingai atlikti aritmetines operacijas
    Vector<int> v = {10, 20, 30, 40, 50};
    auto it = v.begin();
    it += 2;
    REQUIRE(*it == 30);
    
    it -= 1;
    REQUIRE(*it == 20);
    
    REQUIRE(*(it + 2) == 40);
    REQUIRE(*(v.end() - 1) == 50);
}

TEST_CASE("Iterator comparison") { //tikrina, ar iteratoriai leidžia teisingai palyginti pozicijas vektoriuje, naudojant relacinius operatorius
    Vector<int> v = {1, 2, 3};
    auto it1 = v.begin();
    auto it2 = v.begin() + 1;
    
    REQUIRE(it1 < it2);
    REQUIRE(it1 <= it2);
    REQUIRE(it2 > it1);
    REQUIRE(it2 >= it1);
    REQUIRE(it1 != it2);
}




TEST_CASE("operator== for equal vectors") { //tikrina, ar operator== grąžina true, kai du vektoriai yra lygūs
    Vector<int> v1 = {1, 2, 3};
    Vector<int> v2 = {1, 2, 3};
    REQUIRE(v1 == v2);
}

TEST_CASE("operator!= for different vectors") { //tikrina, ar operator!= grąžina true, kai du vektoriai nėra lygūs
    Vector<int> v1 = {1, 2, 3};
    Vector<int> v2 = {1, 2, 4};
    REQUIRE(v1 != v2);
}

TEST_CASE("operator< lexicographical comparison") { //tikrina, ar operator< teisingai palygina du vektorius leksikografinėje tvarkoje
    Vector<int> v1 = {1, 2, 3}; //leksikografinė tvarka - tai būdas palyginti du konteinerius elementas po elemento
    Vector<int> v2 = {1, 2, 4};
    REQUIRE(v1 < v2);
    REQUIRE(!(v2 < v1));
}

TEST_CASE("operator<= comparison") { //tikrina, ar operator<= teisingai palygina du vektorius leksikografinėje tvarkoje
    Vector<int> v1 = {1, 2, 3};
    Vector<int> v2 = {1, 2, 3};
    REQUIRE(v1 <= v2);
    REQUIRE(v1 <= Vector<int>{1, 2, 4});
}




TEST_CASE("String storage") { //tikrina, ar vektorius gali saugoti ir teisingai grąžinti elementus sudėtingesniais duomenų tipais, tokiais kaip std::string
    Vector<std::string> v;
    v.push_back("hello");
    v.push_back("world");
    REQUIRE(v.size() == 2);
    REQUIRE(v[0] == "hello");
    REQUIRE(v[1] == "world");
}

TEST_CASE("Large capacity handling") { //tikrina, ar vektorius gali tvarkyti didelį kiekį elementų, ir ar jis teisingai saugo ir grąžina visus elementus
    Vector<int> v;
    for (int i = 0; i < 1000; ++i) {
        v.push_back(i);
    }
    REQUIRE(v.size() == 1000);
    REQUIRE(v[0] == 0);
    REQUIRE(v[999] == 999);
}

TEST_CASE("Repeated resizing") { //tikrina, ar vektorius gali būti keičiamas dydžiu daug kartų, ir ar jis teisingai saugo elementus kiekvieno keitimo metu
    Vector<int> v;
    for (int round = 0; round < 5; ++round) {
        for (int i = 0; i < 100; ++i) {
            v.push_back(i);
        }
        REQUIRE(v.size() == static_cast<decltype(v.size())>((round + 1) * 100));
    }
    REQUIRE(v.size() == 500);
}

TEST_CASE("Complex type: struct") { //tikrina, ar vektorius gali saugoti ir teisingai grąžinti elementus, kurie yra sudėtingesniais duomenų tipais, tokiais kaip struktūros
    struct Point {
        int x, y;
        bool operator==(const Point& other) const {
            return x == other.x && y == other.y;
        }
    };
    
    Vector<Point> v;
    v.push_back({1, 2});
    v.push_back({3, 4});
    REQUIRE(v.size() == 2);
    REQUIRE(v[0].x == 1);
    REQUIRE(v[1].y == 4);
}

TEST_CASE("Reallocation count tracking") { //tikrina, ar vektorius teisingai seka realokacijų skaičių, ir ar jis padidėja, kai push_back() sukelia realokaciją
    Vector<int> v;
    auto initial_count = v.get_reallocation_count();
    
    // Push until reallocation happens
    for (int i = 0; i < 100; ++i) {
        v.push_back(i);
    }
    
    REQUIRE(v.get_reallocation_count() > initial_count);
}

TEST_CASE("Insert at beginning") { //tikrina, ar insert() metodas teisingai įterpia elementą į vektoriaus pradžią
    Vector<int> v = {2, 3, 4};
    v.insert(v.cbegin(), 1);
    REQUIRE(v.size() == 4);
    REQUIRE(v[0] == 1);
    REQUIRE(v[1] == 2);
}

TEST_CASE("Insert at end") { //tikrina, ar insert() metodas teisingai įterpia elementą į vektoriaus pabaigą
    Vector<int> v = {1, 2, 3};
    v.insert(v.cend(), 4);
    REQUIRE(v.size() == 4);
    REQUIRE(v[3] == 4);
}

TEST_CASE("Multiple sequential operations") { //tikrina, ar vektorius teisingai tvarko kelis iš eilės vykstančius modifikavimo veiksmus, tokius kaip push_back(), insert(), erase() ir pop_back()
    Vector<int> v = {1, 2, 3};
    v.push_back(4);
    v.insert(v.cbegin() + 1, 99);
    v.erase(v.cbegin() + 3);
    v.pop_back();
    
    REQUIRE(v.size() == 3);
    REQUIRE(v[0] == 1);
    REQUIRE(v[1] == 99);
    REQUIRE(v[2] == 2);
}




TEST_CASE("Vector is compatible with std::vector operations") { //tikrina, ar vektorius yra suderinamas su operacijomis, kurios veikia su std::vector, tokiomis kaip iteracija, algoritmai ir kt.
    Vector<int> v = {1, 2, 3, 4, 5};
    
    int sum = 0;
    for (int x : v) {
        sum += x;
    }
    REQUIRE(sum == 15);
    
    Vector<int> v2 = {5, 2, 8, 1, 9};
    std::sort(v2.begin(), v2.end());
    REQUIRE(v2[0] == 1);
    REQUIRE(v2[4] == 9);
}

TEST_CASE("Vector with custom struct Studentas") { //tikrina, ar vektorius gali saugoti ir teisingai grąžinti elementus, kurie yra sudėtingesniais duomenų tipais, tokiais kaip struktūros

    Vector<int> v;
    for (int i = 0; i < 100; ++i) {
        v.push_back(i);
    }
    REQUIRE(v.size() == 100);
}
