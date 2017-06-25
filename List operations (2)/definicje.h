//Marcin Drewniak
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct wez
{
    double informacja;
    struct wez* nastepny;
} wezel;

typedef wezel* kolejka;


kolejka inicjalizuj();
kolejka dopisz_na_poczatek(kolejka k, double x);
kolejka dopisz_na_koniec(kolejka k, double x);
double wartosc_z_poczatku(kolejka k);
double usun_wartosc_z_poczatku(kolejka* k);
bool czy_pusta(kolejka k);
int dlugosc_listy(kolejka k);
void wypisz_kolejke(kolejka k);

/********************************************************/
/********************Zadanie 2***************************/
/********************************************************/

kolejka polacz_bez_kopiowania(kolejka k, kolejka p);
kolejka skopiuj(kolejka k, kolejka p);
kolejka quicksort(kolejka k);
kolejka sortowanie_przez_wstawianie(kolejka k);
kolejka posortuj_rosnaco(kolejka k);
kolejka sortowanie_rekurencyjne(kolejka k, kolejka pierwszy);
kolejka wstaw_we_wlasciwe_miejsce(kolejka k, double x);
