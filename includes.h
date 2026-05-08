#ifndef INCLUDES_H //apsauga nuo kelių įtraukimų
#define INCLUDES_H //apsauga nuo kelių įtraukimų

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <chrono>
#include <sstream>
#include <stdexcept>
#include <random>
#include <list>
#include <deque>
#include <type_traits>

using std::string;
using std::vector;
using std::list;
using std::deque;
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
using std::mt19937;
using std::uniform_int_distribution;
using std::random_device;
using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::to_string;
using std::find; //naudojama funkcijoms, kurios ieško elementų konteineryje, naudojant lambda funkciją
using std::find_if; //naudojama funkcijoms, kurios ieško elementų konteineryje su sąlyga, naudojant lambda funkciją
using std::search; //naudojama funkcijoms, kurios ieško elementų konteineryje, naudojant lambda funkciją
using std::copy; //naudojama funkcijoms, kurios kopijuoja elementus iš vieno konteinerio į kitą, naudojant lambda funkciją
using std::remove; //naudojama funkcijoms, kurios pašalina elementus iš konteinerio, naudojant lambda funkciją
using std::remove_if; //naudojama funkcijoms, kurios pašalina elementus iš konteinerio su sąlyga, naudojant lambda funkciją
using std::remove_copy; //naudojama funkcijoms, kurios pašalina kopijas iš konteinerio, naudojant lambda funkciją
using std::remove_copy_if; //naudojama funkcijoms, kurios pašalina kopijas iš konteinerio su sąlyga, naudojant lambda funkciją
using std::transform; //naudojama funkcijai, kuri konvertuoja string į int, naudojant lambda funkciją
using std::partition; //greitesnis nei stable_partition, bet nekeičia elementų tvarkos
using std::stable_partition; //lėtesnis nei partition, bet nekeičia elementų tvarkos

#endif //apsauga nuo kelių įtraukimų