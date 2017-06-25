#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct wez* WLLC;

typedef union kom
{
int liczba;
WLLC wskaznik;
}komorka;


typedef struct wez
{
bool czy_liczba;
komorka gdzie;
WLLC nastepny;
}wezel;


WLLC lista_pusta();
WLLC dopisz_liczbe_na_poczatek(int x, WLLC lista);
WLLC dopisz_liste_na_poczatek(WLLC podlista, WLLC lista);
void wypisz_liste(WLLC lista, bool czy_podlista);
WLLC merge(WLLC l1, WLLC l2);
WLLC flat(WLLC li);
WLLC splaszcz(WLLC li, WLLC wynik);
