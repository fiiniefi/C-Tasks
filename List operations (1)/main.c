#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "WLLC.h"


int main()
{
WLLC l1, l2, l3, l4, l5;
WLLC p1, p2, p3, p4;
l1=lista_pusta();
l2=lista_pusta();
l3=lista_pusta();
l4=lista_pusta();
l5=lista_pusta();
p1=lista_pusta();
p2=lista_pusta();
p3=lista_pusta();
p4=lista_pusta();

l1=dopisz_liczbe_na_poczatek(7, l1);
l1=dopisz_liczbe_na_poczatek(6, l1);
l2=dopisz_liczbe_na_poczatek(5, l2);
l2=dopisz_liczbe_na_poczatek(4, l2);
l1=dopisz_liste_na_poczatek(l2, l1);
l3=dopisz_liczbe_na_poczatek(3, l3);
l3=dopisz_liczbe_na_poczatek(2, l3);
l4=dopisz_liste_na_poczatek(l3, l4);
l1=dopisz_liste_na_poczatek(l4, l1);
l5=dopisz_liste_na_poczatek(NULL, l5);
l1=dopisz_liste_na_poczatek(l5, l1);
printf("Lista l:\n");
wypisz_liste(l1, 1);
printf("\n");
/////////////////////////////////////////////////
printf("Lista p:\n");
p1=dopisz_liczbe_na_poczatek(64, p1);
p1=dopisz_liczbe_na_poczatek(63, p1);
p2=dopisz_liste_na_poczatek(NULL, p2);
p3=dopisz_liczbe_na_poczatek(62, p3);
p3=dopisz_liczbe_na_poczatek(61, p3);
p4=dopisz_liczbe_na_poczatek(60, p4);
p4=dopisz_liczbe_na_poczatek(59, p4);
p4=dopisz_liczbe_na_poczatek(58, p4);
p1=dopisz_liste_na_poczatek(p2, p1);
p1=dopisz_liste_na_poczatek(p3, p1);
p1=dopisz_liste_na_poczatek(p4, p1);
wypisz_liste(p1, 2);
printf("\n");
///////////////////////////////////////////////
printf("Lista polaczona:\n");
WLLC polaczona=merge(l1, p1);
wypisz_liste(polaczona, 1);
printf("\n");
printf("Lista l1 po zmianach:\n");
wypisz_liste(l1, 1);
printf("\n");
printf("Lista p1 po zmianach:\n");
wypisz_liste(p1, 1);
printf("\n");
/////////////////////////////////////////////
printf("Teraz uzyje funkcji flat na liscie polaczonej. Oto efekt:\n");
polaczona=flat(polaczona);
wypisz_liste(polaczona, 1);
}
