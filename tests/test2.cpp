#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "./doctest/doctest.h"
#include "LZespolona.hh"

TEST_CASE("Test LZespolona dzielenie przez skalar 1") {
    LZespolona x, y;
    double t = 2;
    
    x.re = 2;
    x.im = 2;

    y.re = 1;
    y.im = 1;
   
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar 2") {
    LZespolona x, y;
    double t = 3;
    
    x.re = 2;
    x.im = 2;

    y.re = 0.66;
    y.im = 0.66;
   
    CHECK(x/t == y);
}

TEST_CASE("Test LZespolona dzielenie przez skalar - zero") {
    LZespolona x;
    double t = 0;
    
    x.re = 2;
    x.im = 2;
 
   WARN_THROWS(x/t);
}

TEST_CASE("Test LZespolona wyswietlanie zaokraglania") {
    LZespolona x;
    x.re = 2.0/3.0;
    x.im = 2.0/3.0;

    std::ostringstream out;

    out << x;

    CHECK( "(0.67+0.67i)" == out.str() );
}


TEST_CASE("Test LZespolona wczytywanie standardowe") {
    LZespolona x;

    std::istringstream in("(99+99.99i)");
    in >> x;
     std::ostringstream out;
    out << x;

    CHECK( "(99.00+99.99i)" == out.str() );
}