#include <stdio.h>
#include <stdlib.h>
#include "funkcje.h"

int main()
{
ulamek pierwszy=wczytaj();
ulamek drugi=wczytaj();
ulamek suma=dodaj(pierwszy, drugi);
ulamek roznica=odejmij(pierwszy, drugi);
ulamek iloczyn=pomnoz(pierwszy, drugi);
ulamek iloraz=podziel(pierwszy, drugi);
printf("Ulamek pierwszy:\n");
wypisz(pierwszy);
printf("Ulamek drugi:\n");
wypisz(drugi);
printf("Suma:\n");
wypisz(suma);
printf("Roznica:\n");
wypisz(roznica);
printf("Iloczyn:\n");
wypisz(iloczyn);
printf("Iloraz:\n");
wypisz(iloraz);
return 0;
}
