#include <iostream>
#include <cmath>
#include "LZespolona.hh"
#include <cmath>

#define MIN_DIFF 0.01

/*!
 * Realizuje porównanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwsza porównywana liczba zespolona,
 *    Skl2 - druga porównywana liczba zespolona.
 * Zwraca:
 *    True dla równych liczb zespolonych.
 */

bool  operator == (LZespolona  Skl1,  LZespolona  Skl2){

  if (abs(Skl1.re - Skl2.re) <= MIN_DIFF && abs(Skl1.im - Skl2.im) <= MIN_DIFF)
    return true;
  else
    return false;
  
}

// opreacje matematyczne

/*
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}


/*
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik 
 *    Skl2 - drugi skladnik 
 * Zwraca:
 *    roznice dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}



/*
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik 
 *    Skl2 - drugi skladnik 
 * Zwraca:
 *    iloczyn dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re * Skl2.re - Skl1.im * Skl2.im;
  Wynik.im = Skl1.re * Skl2.im + Skl1.im * Skl2.re;
  return Wynik;
}



/*
 * Realizuje dzielenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik 
 *    Skl2 - drugi skladnik 
 * Zwraca:
 *    iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;
  double mianownik;
  Wynik = Skl1*Sprzezenie(Skl2);
  mianownik=pow(Modul2(Skl2),2);
  Wynik = Wynik / mianownik;
  return Wynik;
}



/*
 * Realizuje dzielenie liczby zespolonej przez liczbe
 * Argumenty:
 *    Skl1 - pierwszy skladnik 
 *    Skl2 - drugi skladnik 
 * Zwraca:
 *    iloraz dwoch skladnikow przekazanych jako parametry.
 */
LZespolona  operator / (LZespolona  Skl1,  double mianownik)
{
  LZespolona  Wynik;
  Wynik.re = Skl1.re / mianownik;
  Wynik.im = Skl1.im / mianownik;
  return Wynik;
}


//sprzezenie
LZespolona Sprzezenie(LZespolona LZesp){
LZesp.im = LZesp.im * (-1);
return LZesp;
}

//modul
double Modul2(LZespolona LZesp){
double modul;
modul = sqrt( (LZesp.re * LZesp.re) + (LZesp.im * LZesp.im) );
return modul;
}



void Wyswietl(LZespolona LZesp )
{
cout << " (" << LZesp.re << showpos << LZesp.im << "i) " << noshowpos;
}




ostream & operator << (ostream &wyj,const LZespolona LZesp)
{
wyj << " (" << LZesp.re << showpos << LZesp.im << "i) " << noshowpos;
return wyj;
}




istream & operator >> (istream &wej, LZespolona &LZesp)
{
  char znak;
  wej>>znak;
  if(znak!='(')
  {
    wej.setstate(ios::badbit);
  }
  wej>>LZesp.re;
  wej>>LZesp.im;
  wej>>znak;
    if(znak!='i')
  {
    wej.setstate(ios::badbit);
  }
  wej>>znak;
    if(znak!=')')
  {
    wej.setstate(ios::badbit);
  }
  return wej;

}




