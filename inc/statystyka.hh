#ifndef statystyka_HH
#define statystyka_HH
#include <iostream>
using namespace std;

struct statystyka
{
    int poprawne;
    int bledne;
    int wszystkie;
};

void Wyswietl (statystyka stat);
void inicjuj (statystyka &stat);

#endif