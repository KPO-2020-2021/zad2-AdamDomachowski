#include <iostream>
#include <cstring>
#include <cassert>
#include "WyrazenieZesp.hh"

using namespace std;


void Wyswietl(WyrazenieZesp  WyrZ)
{

    //showpos - pokazuje plusy przed liczba jesli > 0
    //noshowpos - wyłącza tę opcję.

    cout << " (" << WyrZ.Arg1.re << showpos << WyrZ.Arg1.im << "i) " << noshowpos;
    if(WyrZ.Op == 0) cout << "+"; //WyrZ.Op przyjmuje wartosci od 0 - 3 nalezy je potem odszyfrowac
    if(WyrZ.Op == 1) cout << "-";
    if(WyrZ.Op == 2) cout << "*";
    if(WyrZ.Op == 3) cout << "/";
    cout << " (" << WyrZ.Arg2.re << showpos << WyrZ.Arg2.im << "i) =" << noshowpos;
}


ostream & operator << (ostream &wyj, const WyrazenieZesp WyrZ)
{
    wyj<< " (" << WyrZ.Arg1.re << showpos << WyrZ.Arg1.im << "i) " << noshowpos;
    if(WyrZ.Op == 0) wyj << "+"; //WyrZ.Op przyjmuje wartosci od 0 - 3 nalezy je potem odszyfrowac
    if(WyrZ.Op == 1) wyj << "-";
    if(WyrZ.Op == 2) wyj << "*";
    if(WyrZ.Op == 3) wyj << "/";
    wyj << " (" << WyrZ.Arg2.re << showpos << WyrZ.Arg2.im << "i) =" << noshowpos; 

return wyj;
}


LZespolona Oblicz(WyrazenieZesp  WyrZ){
LZespolona z;


switch (WyrZ.Op){

    case Op_Dodaj:
        z = WyrZ.Arg1 + WyrZ.Arg2;
        break;
    
    case Op_Odejmij:
        z = WyrZ.Arg1 - WyrZ.Arg2;
        break;

    case Op_Mnoz:
        z = WyrZ.Arg1 * WyrZ.Arg2;
        break;

    case Op_Dziel:
        z = WyrZ.Arg1 / WyrZ.Arg2;
        break;     
    }
return z;
}
