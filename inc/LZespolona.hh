#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>

using namespace std;
/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */


LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2); //dodawanie
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2); //odejmowanie
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2); //mnozenie
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2); //dzielenie zespolonej przez zespolona
LZespolona  operator / (LZespolona  Skl1,  double mianownik); //dzielenie zespolonej przez liczbe
LZespolona operator += (LZespolona Skl1, LZespolona const Skl2);
LZespolona operator /= (LZespolona Skl1, LZespolona const Skl2);



//operacje matematyczne
LZespolona Sprzezenie(LZespolona);
double Modul2(LZespolona);


void Wyswietl(LZespolona LZesp );
double arg(LZespolona z); // oblicza modul l zespolonej


ostream & operator << (ostream &wyj,const LZespolona LZesp);
istream & operator >> (istream &wej, LZespolona &LZesp);

bool operator == (LZespolona  Skl1,  LZespolona  Skl2);

#endif
