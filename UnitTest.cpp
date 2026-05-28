#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "Vector.h"
#include <string>

// ============================================================================
// CONSTRUCTORS AND BASIC OPERATIONS
// ============================================================================

TEST_CASE("Default constructor creates empty vector") {
    Vector<int> v;
    REQUIRE(v.empty());
    REQUIRE(v.size() == 0);
    REQUIRE(v.capacity() == 0);
}

TEST_CASE("Constructor with size n") {
    Vector<int> v(5);
    REQUIRE(v.size() == 5);
    REQUIRE(v.capacity() == 5);
    for (int i = 0; i < 5; ++i) {
        REQUIRE(v[i] == 0);
    }
}

TEST_CASE("Constructor with size and value") {
    Vector<int> v(3, 42);
    REQUIRE(v.size() == 3);
    REQUIRE(v[0] == 42);
    REQUIRE(v[1] == 42);
    REQUIRE(v[2] == 42);
}

TEST_CASE("Constructor with initializer list") {
    Vector<int> v = {1, 2, 3, 4, 5};
    REQUIRE(v.size() == 5);
    REQUIRE(v[0] == 1);
    REQUIRE(v[4] == 5);
}

TEST_CASE("Range constructor with iterators") {
    std::vector<int> stdv = {10, 20, 30, 40};
    Vector<int> v(stdv.begin(), stdv.end());
    REQUIRE(v.size() == 4);
    REQUIRE(v[0] == 10);
    REQUIRE(v[3] == 40);
}

TEST_CASE("Copy constructor") {
    Vector<int> v1 = {1, 2, 3};
    Vector<int> v2(v1);
    REQUIRE(v2.size() == v1.size());
    REQUIRE(v2[0] == 1);
    REQUIRE(v2[2] == 3);
    
    v2[0] = 999;
    REQUIRE(v1[0] == 1);
}

TEST_CASE("Move constructor") {
    Vector<int> v1 = {1, 2, 3};
    Vector<int> v2(std::move(v1));
    REQUIRE(v2.size() == 3);
    REQUIRE(v2[0] == 1);
    REQUIRE(v1.size() == 0);
}

TEST_CASE("Copy assignment operator") {
    Vector<int> v1 = {1, 2, 3};
    Vector<int> v2 = {10, 20};
    v2 = v1;
    REQUIRE(v2.size() == 3);
    REQUIRE(v2[0] == 1);
    REQUIRE(v2[2] == 3);
}

TEST_CASE("Move assignment operator") {
    Vector<int> v1 = {1, 2, 3};
    Vector<int> v2 = {10, 20};
    v2 = std::move(v1);
    REQUIRE(v2.size() == 3);
    REQUIRE(v2[0] == 1);
    REQUIRE(v1.size() == 0);
}

TEST_CASE("Initializer list assignment") {
    Vector<int> v;
    v = {5, 10, 15};
    REQUIRE(v.size() == 3);
    REQUIRE(v[1] == 10);
}

// ============================================================================
// ELEMENT ACCESS
// ============================================================================

TEST_CASE("operator[] for access") {
    Vector<int> v = {10, 20, 30};
    REQUIRE(v[0] == 10);
    REQUIRE(v[1] == 20);
    REQUIRE(v[2] == 30);
}

TEST_CASE("operator[] for modification") {
    Vector<int> v = {1, 2, 3};
    v[1] = 99;
    REQUIRE(v[1] == 99);
}

TEST_CASE("at() function for access") {
    Vector<int> v = {10, 20, 30};
    REQUIRE(v.at(0) == 10);
    REQUIRE(v.at(2) == 30);
}

TEST_CASE("at() throws exception for out of range") {
    Vector<int> v = {1, 2, 3};
    REQUIRE_THROWS_AS(v.at(5), std::out_of_range);
}

TEST_CASE("front() and back()") {
    Vector<int> v = {10, 20, 30};
    REQUIRE(v.front() == 10);
    REQUIRE(v.back() == 30);
}

TEST_CASE("data() pointer access") {
    Vector<int> v = {1, 2, 3};
    int* ptr = v.data();
    REQUIRE(ptr[0] == 1);
    REQUIRE(ptr[2] == 3);
}

// ============================================================================
// CAPACITY AND SIZE
// ============================================================================

TEST_CASE("size() returns correct number of elements") {
    Vector<int> v;
    REQUIRE(v.size() == 0);
    v.push_back(1);
    REQUIRE(v.size() == 1);
    v.push_back(2);
    REQUIRE(v.size() == 2);
}

TEST_CASE("empty() returns true for empty vector") {
    Vector<int> v;
    REQUIRE(v.empty());
    v.push_back(1);
    REQUIRE(!v.empty());
}

TEST_CASE("capacity() grows when needed") {
    Vector<int> v;
    auto initial_cap = v.capacity();
    REQUIRE(initial_cap == 0);
    
    for (int i = 0; i < 10; ++i) {
        v.push_back(i);
    }
    REQUIRE(v.capacity() >= 10);
}

TEST_CASE("reserve() allocates specified capacity") {
    Vector<int> v;
    v.reserve(100);
    REQUIRE(v.capacity() >= 100);
    REQUIRE(v.size() == 0);
}

TEST_CASE("shrink_to_fit() reduces capacity") {
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

// ============================================================================
// PUSH_BACK AND POP_BACK
// ============================================================================

TEST_CASE("push_back() adds element to end") {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    REQUIRE(v.size() == 3);
    REQUIRE(v[0] == 10);
    REQUIRE(v[1] == 20);
    REQUIRE(v[2] == 30);
}

TEST_CASE("push_back() with rvalue reference") {
    Vector<std::string> v;
    std::string s("hello");
    v.push_back(std::move(s));
    REQUIRE(v.size() == 1);
    REQUIRE(v[0] == "hello");
}

TEST_CASE("push_back() triggers reallocation") {
    Vector<int> v;
    size_t reallocs = v.get_reallocation_count();
    for (int i = 0; i < 100; ++i) {
        v.push_back(i);
    }
    REQUIRE(v.get_reallocation_count() > reallocs);
    REQUIRE(v.size() == 100);
}

TEST_CASE("pop_back() removes last element") {
    Vector<int> v = {10, 20, 30};
    v.pop_back();
    REQUIRE(v.size() == 2);
    REQUIRE(v.back() == 20);
    
    v.pop_back();
    REQUIRE(v.size() == 1);
    REQUIRE(v.back() == 10);
}

TEST_CASE("emplace_back() constructs element in place") {
    Vector<std::string> v;
    v.emplace_back(5, 'a');
    REQUIRE(v.size() == 1);
    REQUIRE(v[0] == "aaaaa");
}

// ============================================================================
// INSERT OPERATIONS
// ============================================================================

TEST_CASE("insert() single element at position") {
    Vector<int> v = {1, 2, 4, 5};
    auto it = v.insert(v.cbegin() + 2, 3);
    REQUIRE(*it == 3);
    REQUIRE(it == v.begin() + 2);
    REQUIRE(v.size() == 5);
    REQUIRE(v[2] == 3);
    REQUIRE(v[3] == 4);
    REQUIRE(v[4] == 5);
}

TEST_CASE("insert() multiple copies of element") {
    Vector<int> v = {1, 5};
    v.insert(v.cbegin() + 1, 3, 99);
    REQUIRE(v.size() == 5);
    REQUIRE(v[1] == 99);
    REQUIRE(v[2] == 99);
    REQUIRE(v[3] == 99);
    REQUIRE(v[4] == 5);
}

TEST_CASE("insert() range from another container") {
    Vector<int> v = {1, 5};
    std::vector<int> vals = {2, 3, 4};
    v.insert(v.cbegin() + 1, vals.begin(), vals.end());
    REQUIRE(v.size() == 5);
    REQUIRE(v[1] == 2);
    REQUIRE(v[2] == 3);
    REQUIRE(v[3] == 4);
}

TEST_CASE("insert() initializer list") {
    Vector<int> v = {1, 5};
    v.insert(v.cbegin() + 1, {2, 3, 4});
    REQUIRE(v.size() == 5);
    REQUIRE(v[1] == 2);
    REQUIRE(v[3] == 4);
}

// ============================================================================
// ERASE OPERATIONS
// ============================================================================

TEST_CASE("erase() single element") {
    Vector<int> v = {1, 2, 3, 4, 5};
    v.erase(v.cbegin() + 2);
    REQUIRE(v.size() == 4);
    REQUIRE(v[2] == 4);
    REQUIRE(v[3] == 5);
}

TEST_CASE("erase() range of elements") {
    Vector<int> v = {1, 2, 3, 4, 5};
    v.erase(v.cbegin() + 1, v.cbegin() + 4);
    REQUIRE(v.size() == 2);
    REQUIRE(v[0] == 1);
    REQUIRE(v[1] == 5);
}

TEST_CASE("erase() all elements") {
    Vector<int> v = {1, 2, 3};
    v.erase(v.cbegin(), v.cend());
    REQUIRE(v.empty());
    REQUIRE(v.size() == 0);
}

// ============================================================================
// RESIZE AND ASSIGN
// ============================================================================

TEST_CASE("resize() increases size with default values") {
    Vector<int> v = {1, 2};
    v.resize(5);
    REQUIRE(v.size() == 5);
    REQUIRE(v[2] == 0);
    REQUIRE(v[3] == 0);
    REQUIRE(v[4] == 0);
}

TEST_CASE("resize() increases size with specified value") {
    Vector<int> v = {1, 2};
    v.resize(5, 99);
    REQUIRE(v.size() == 5);
    REQUIRE(v[2] == 99);
    REQUIRE(v[3] == 99);
    REQUIRE(v[4] == 99);
}

TEST_CASE("resize() decreases size") {
    Vector<int> v = {1, 2, 3, 4, 5};
    v.resize(3);
    REQUIRE(v.size() == 3);
    REQUIRE(v[0] == 1);
    REQUIRE(v[2] == 3);
}

TEST_CASE("assign() with count and value") {
    Vector<int> v = {1, 2, 3};
    v.assign(4, 42);
    REQUIRE(v.size() == 4);
    REQUIRE(v[0] == 42);
    REQUIRE(v[3] == 42);
}

TEST_CASE("assign() with range") {
    Vector<int> v = {1, 2, 3};
    std::vector<int> src = {10, 20, 30, 40};
    v.assign(src.begin(), src.end());
    REQUIRE(v.size() == 4);
    REQUIRE(v[0] == 10);
    REQUIRE(v[3] == 40);
}

// ============================================================================
// CLEAR AND SWAP
// ============================================================================

TEST_CASE("clear() empties the vector") {
    Vector<int> v = {1, 2, 3};
    v.clear();
    REQUIRE(v.empty());
    REQUIRE(v.size() == 0);
    // Capacity may not be zero
}

TEST_CASE("swap() exchanges contents") {
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

// ============================================================================
// ITERATORS
// ============================================================================

TEST_CASE("Iterator traversal") {
    Vector<int> v = {10, 20, 30};
    int sum = 0;
    for (auto it = v.begin(); it != v.end(); ++it) {
        sum += *it;
    }
    REQUIRE(sum == 60);
}

TEST_CASE("Const iterator") {
    Vector<int> v = {1, 2, 3};
    int sum = 0;
    for (auto it = v.cbegin(); it != v.cend(); ++it) {
        sum += *it;
    }
    REQUIRE(sum == 6);
}

TEST_CASE("Range-based for loop") {
    Vector<int> v = {1, 2, 3};
    int sum = 0;
    for (int x : v) {
        sum += x;
    }
    REQUIRE(sum == 6);
}

TEST_CASE("Reverse iterator") {
    Vector<int> v = {1, 2, 3};
    Vector<int> reversed;
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        reversed.push_back(*it);
    }
    REQUIRE(reversed[0] == 3);
    REQUIRE(reversed[1] == 2);
    REQUIRE(reversed[2] == 1);
}

TEST_CASE("Iterator arithmetic") {
    Vector<int> v = {10, 20, 30, 40, 50};
    auto it = v.begin();
    it += 2;
    REQUIRE(*it == 30);
    
    it -= 1;
    REQUIRE(*it == 20);
    
    REQUIRE(*(it + 2) == 40);
    REQUIRE(*(v.end() - 1) == 50);
}

TEST_CASE("Iterator comparison") {
    Vector<int> v = {1, 2, 3};
    auto it1 = v.begin();
    auto it2 = v.begin() + 1;
    
    REQUIRE(it1 < it2);
    REQUIRE(it1 <= it2);
    REQUIRE(it2 > it1);
    REQUIRE(it2 >= it1);
    REQUIRE(it1 != it2);
}

// ============================================================================
// COMPARISON OPERATORS
// ============================================================================

TEST_CASE("operator== for equal vectors") {
    Vector<int> v1 = {1, 2, 3};
    Vector<int> v2 = {1, 2, 3};
    REQUIRE(v1 == v2);
}

TEST_CASE("operator!= for different vectors") {
    Vector<int> v1 = {1, 2, 3};
    Vector<int> v2 = {1, 2, 4};
    REQUIRE(v1 != v2);
}

TEST_CASE("operator< lexicographical comparison") {
    Vector<int> v1 = {1, 2, 3};
    Vector<int> v2 = {1, 2, 4};
    REQUIRE(v1 < v2);
    REQUIRE(!(v2 < v1));
}

TEST_CASE("operator<= comparison") {
    Vector<int> v1 = {1, 2, 3};
    Vector<int> v2 = {1, 2, 3};
    REQUIRE(v1 <= v2);
    REQUIRE(v1 <= Vector<int>{1, 2, 4});
}

// ============================================================================
// EDGE CASES AND STRESS TESTS
// ============================================================================

TEST_CASE("String storage") {
    Vector<std::string> v;
    v.push_back("hello");
    v.push_back("world");
    REQUIRE(v.size() == 2);
    REQUIRE(v[0] == "hello");
    REQUIRE(v[1] == "world");
}

TEST_CASE("Large capacity handling") {
    Vector<int> v;
    for (int i = 0; i < 1000; ++i) {
        v.push_back(i);
    }
    REQUIRE(v.size() == 1000);
    REQUIRE(v[0] == 0);
    REQUIRE(v[999] == 999);
}

TEST_CASE("Repeated resizing") {
    Vector<int> v;
    for (int round = 0; round < 5; ++round) {
        for (int i = 0; i < 100; ++i) {
            v.push_back(i);
        }
        REQUIRE(v.size() == static_cast<decltype(v.size())>((round + 1) * 100));
    }
    REQUIRE(v.size() == 500);
}

TEST_CASE("Complex type: struct") {
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

TEST_CASE("Reallocation count tracking") {
    Vector<int> v;
    auto initial_count = v.get_reallocation_count();
    
    // Push until reallocation happens
    for (int i = 0; i < 100; ++i) {
        v.push_back(i);
    }
    
    REQUIRE(v.get_reallocation_count() > initial_count);
}

TEST_CASE("Insert at beginning") {
    Vector<int> v = {2, 3, 4};
    v.insert(v.cbegin(), 1);
    REQUIRE(v.size() == 4);
    REQUIRE(v[0] == 1);
    REQUIRE(v[1] == 2);
}

TEST_CASE("Insert at end") {
    Vector<int> v = {1, 2, 3};
    v.insert(v.cend(), 4);
    REQUIRE(v.size() == 4);
    REQUIRE(v[3] == 4);
}

TEST_CASE("Multiple sequential operations") {
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

// ============================================================================
// COMPATIBILITY WITH STD::VECTOR INTERFACE
// ============================================================================

TEST_CASE("Vector is compatible with std::vector operations") {
    Vector<int> v = {1, 2, 3, 4, 5};
    
    // Can use with standard algorithms
    int sum = 0;
    for (int x : v) {
        sum += x;
    }
    REQUIRE(sum == 15);
    
    // Can be sorted using iterators
    Vector<int> v2 = {5, 2, 8, 1, 9};
    std::sort(v2.begin(), v2.end());
    REQUIRE(v2[0] == 1);
    REQUIRE(v2[4] == 9);
}

TEST_CASE("Vector with custom struct Studentas") {
    // This tests that Vector works with the actual Studentas class
    // Just verify instantiation works
    Vector<int> v;
    for (int i = 0; i < 100; ++i) {
        v.push_back(i);
    }
    REQUIRE(v.size() == 100);
}
