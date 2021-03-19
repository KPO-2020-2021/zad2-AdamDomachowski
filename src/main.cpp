#include <iostream>
#include "BazaTestu.hh"
#include "statystyka.hh"


using namespace std;




int main(int argc, char **argv)
{

  

  if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }


  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }

  
  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;


  LZespolona Odpowiedz, Wynik;
  WyrazenieZesp   WyrZ_PytanieTestowe;
  statystyka stat;
  inicjuj(stat);


  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {

    cout << "Podaj wynik operacji:" << WyrZ_PytanieTestowe << " ";

    
    for(int i=0; i<3; i++) //sprawdzanie poprawnosci wpisania
    {
    cin>>Odpowiedz;
      if(cin.bad())
        {
          cout<< "blad wczytania";
        }
      else
        {
          break;
        }
      cin.clear(); //zerujemy informacje o bledzie
      cin.ignore(1024,'\n'); //czyscimy bufor pamieci
    }

    Wynik = Oblicz (WyrZ_PytanieTestowe);

    if (Wynik == Odpowiedz) //porownanie odpowiedzi do wyniku
      {
        cout<<"!!! DOBRZE !!!"<<endl;
        stat.poprawne++;
      }
    else
      {
        cout << "ZLE WYNIK TO: " << Wynik << endl;
        stat.bledne++;
      }
    stat.wszystkie++;  
  }
  Wyswietl(stat);

  
  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}





  /*
  cin>>Odpowiedz;

  if(cin.bad())
  {
    cout<< "blad wczytania";
  }
  else
  
  cin.clear(); //zerujemy informacje o bledzie
  cin.ignore(1024,'\n'); //czyscimy bufor pamieci

  cin>>Z;

  if(cin.bad())
  {
    cout<< "blad wczytania";
  }
  else
  cout<<Z;
  */