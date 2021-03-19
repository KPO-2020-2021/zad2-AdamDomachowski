#include "statystyka.hh"




void Wyswietl (statystyka stat)
{
    cout << "poprawne odpowiezi : " << stat.poprawne << endl;;
    cout << "bledne odpowiezi : " << stat.bledne << endl;
    cout << "procent dobrych : " << (stat.poprawne * 100.0)/stat.wszystkie<<"%"<<endl;
}
void inicjuj (statystyka &stat)
{
    stat.poprawne = 0;
    stat.bledne = 0;
    stat.wszystkie = 0;    
}
