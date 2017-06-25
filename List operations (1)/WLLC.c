#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "WLLC.h"


WLLC lista_pusta()
{
    return NULL;
}


WLLC dopisz_liczbe_na_poczatek(int x, WLLC lista)
{
WLLC pomocnicza=lista;

lista=(WLLC)malloc(sizeof(wezel));
lista->czy_liczba=1;
lista->gdzie.liczba=x;
lista->nastepny=pomocnicza;
return lista;
}


WLLC dopisz_liste_na_poczatek(WLLC podlista, WLLC lista)
{
WLLC pomocnicza=lista;

lista=(WLLC)malloc(sizeof(wezel));
lista->czy_liczba=0;
lista->nastepny=pomocnicza;
lista->gdzie.wskaznik=podlista;
return lista;
}


void wypisz_liste(WLLC lista, bool czy_podlista)
{
    if (czy_podlista == 1)
        printf("[");

    if (lista == NULL)
    {
    printf("]");
    return;
    }

    else
    {
        if (lista->czy_liczba == 0)
        {
        if(lista->gdzie.wskaznik != NULL)
            wypisz_liste(lista->gdzie.wskaznik, 1);
        else
        {
        printf("]");
        return;
        }
        if (lista->nastepny != NULL)
            printf(", ");
        }

        else
        {
        printf("%d", lista->gdzie.liczba);
            if ((lista->nastepny) != NULL)
                printf(", ");
        }
    }

    wypisz_liste(lista->nastepny, 0);
}



WLLC merge(WLLC l1, WLLC l2)
{
bool czy_pierwszy=0;
WLLC nowa=NULL;
WLLC pomocnicza=NULL;
WLLC poczatek=NULL;

    while (l1 != NULL)
    {
    pomocnicza=nowa;
    nowa=(WLLC)malloc(sizeof(wezel));
    nowa->nastepny=NULL;
    nowa->czy_liczba=l1->czy_liczba;
    if (nowa->czy_liczba == 1)
        nowa->gdzie.liczba=l1->gdzie.liczba;
    else
        nowa->gdzie.wskaznik=l1->gdzie.wskaznik;
    if (czy_pierwszy != 0)
        pomocnicza->nastepny=nowa;
    else
        poczatek=nowa;
    l1=l1->nastepny;
    czy_pierwszy=1;
    }

    while (l2 != NULL)
    {
    pomocnicza=nowa;
    nowa=(WLLC)malloc(sizeof(wezel));
    nowa->nastepny=NULL;
    nowa->czy_liczba=l2->czy_liczba;
    if (nowa->czy_liczba == 1)
        nowa->gdzie.liczba=l2->gdzie.liczba;
    else
        nowa->gdzie.wskaznik=l2->gdzie.wskaznik;
    if (czy_pierwszy != 0)
        pomocnicza->nastepny=nowa;
    else
        poczatek=nowa;
    l2=l2->nastepny;
    czy_pierwszy=1;
    }
return poczatek;
}



WLLC flat(WLLC li)
{
WLLC wynik=NULL;
wynik=splaszcz(li, wynik);
WLLC odwrocona=NULL;
    while (wynik != NULL)
    {
    odwrocona=dopisz_liczbe_na_poczatek(wynik->gdzie.liczba, odwrocona);
    wynik=wynik->nastepny;
    }

return odwrocona;
}


WLLC splaszcz(WLLC li, WLLC wynik)
{
    if (li != NULL)
    {
        if (li->czy_liczba == 1)
        {
        wynik=dopisz_liczbe_na_poczatek(li->gdzie.liczba, wynik);
        }

        else
        {
        wynik=splaszcz(li->gdzie.wskaznik, wynik);
        }
    wynik=splaszcz(li->nastepny, wynik);
    }
return wynik;
}
