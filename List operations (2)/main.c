//Marcin Drewniak
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "definicje.h"

int main()
{
kolejka k=inicjalizuj();
printf("Sprawdzam, czy kolejka jest pusta: ");
if(czy_pusta(k))
    printf("tak\n\n");
else
    printf("nie\n\n");

printf("Dopisuje na poczatek 3.14\n");
k=dopisz_na_poczatek(k, 3.14);
printf("Dopisuje na poczatek 5.25\n");
k=dopisz_na_poczatek(k, 5.25);
printf("Dopisuje na koniec 6.43\n");
k=dopisz_na_koniec(k, 6.43);
printf("Stan kolejki po dopisaniu: \n");
wypisz_kolejke(k);
printf("Podaje wartosc z poczatku bez usuwania: ");
printf("%f\n", wartosc_z_poczatku(k));
printf("Dlugosc listy: ");
printf("%d\n", dlugosc_listy(k));
printf("Podaje wartosc z poczatku i usuwam: ");
printf("%f\n", usun_wartosc_z_poczatku(&k));
printf("Podaje wartosc z poczatku po usunieciu: ");
printf("%f\n", wartosc_z_poczatku(k));
printf("Dlugosc listy po usunieciu: ");
printf("%d\n", dlugosc_listy(k));
printf("Sprawdzam, czy kolejka jest pusta: ");
if(czy_pusta(k))
    printf("tak\n\n");
else
    printf("nie\n\n");

/********************************************************/
/********************Zadanie 2***************************/
/********************************************************/

kolejka p=inicjalizuj();
p=dopisz_na_koniec(p, 9.87);
p=dopisz_na_poczatek(p, 32.64);
p=dopisz_na_koniec(p, 100.49);
printf("\n\nZADANIE 2:\n\n");
printf("Wypisuje kolejke 1: ");
wypisz_kolejke(k);
printf("\nWypisuje kolejke 2: ");
wypisz_kolejke(p);
kolejka polaczona_bez_kopiowania=polacz_bez_kopiowania(k, p);
printf("\nLacze obie kolejki i wypisuje: ");
wypisz_kolejke(polaczona_bez_kopiowania);
printf("\nTeraz dodaje jeden element do przodu i na koniec i wypisuje:\n");
polaczona_bez_kopiowania=dopisz_na_koniec(polaczona_bez_kopiowania, 6.43);
polaczona_bez_kopiowania=dopisz_na_poczatek(polaczona_bez_kopiowania, 3.21);
wypisz_kolejke(polaczona_bez_kopiowania);
printf("\n\nTeraz kopiowanie:\n\n");
kolejka z=inicjalizuj();
z=dopisz_na_koniec(z, 102.43);
z=dopisz_na_poczatek(z, 21.3);
z=dopisz_na_poczatek(z, 764.23);
kolejka y=inicjalizuj();
y=dopisz_na_koniec(y, 44.55);
y=dopisz_na_koniec(y, 55.44);
y=dopisz_na_poczatek(y, 11.22);
kolejka f=inicjalizuj();
printf("Stan kolejki z: ");
wypisz_kolejke(z);
printf("\nStan kolejki y: ");
wypisz_kolejke(y);
printf("\nKopiowanie pustej kolejki: ");
skopiuj(z, f);
printf("\nKopiowanie DO pustej kolejki i wypisanie: ");
kolejka pusta_skopiowana=skopiuj(f, z);
wypisz_kolejke(pusta_skopiowana);
kolejka polaczona_z_kopiowaniem=skopiuj(y, z);
printf("\nPolaczylem pelne kolejki y i z, teraz wypisuje: \n");
wypisz_kolejke(polaczona_z_kopiowaniem);
printf("\n\nSortowanie przez wstawianie:\n\n");
printf("Stan kolejki k:\n");
wypisz_kolejke(k);
printf("\nSortuje k przez wstawianie i wypisuje:\n");
k=sortowanie_przez_wstawianie(k);
wypisz_kolejke(k);
printf("\nSortuje polaczona z kopiowaniem przez wstawianie i wypisuje:\n");
polaczona_z_kopiowaniem=sortowanie_przez_wstawianie(polaczona_z_kopiowaniem);
wypisz_kolejke(polaczona_z_kopiowaniem);

printf("\n\nTeraz sortujemy uzywajac quicksorta:\n\n");
kolejka q=inicjalizuj();
q=dopisz_na_poczatek(q, 43.12);
q=dopisz_na_koniec(q, 44.12);
q=dopisz_na_koniec(q, 3.23);
q=dopisz_na_poczatek(q, 112.1);
q=dopisz_na_poczatek(q, 22.12);
q=dopisz_na_koniec(q, 14.23);
q=dopisz_na_poczatek(q, 43.12);
printf("Stan kolejki q przed sortowaniem: \n");
wypisz_kolejke(q);
printf("\nTeraz sortuje ja quicksortem i wypisuje:\n");
q=quicksort(q);
wypisz_kolejke(q);

printf("\n\nTeraz wstawiamy wartosci w odpowiednie miejsce:\n\n");
printf("Wstawiam %f do polaczonej z kopiowaniem i wypisuje liste: \n", 10.50);
polaczona_z_kopiowaniem=wstaw_we_wlasciwe_miejsce(polaczona_z_kopiowaniem, 10.50);
wypisz_kolejke(polaczona_z_kopiowaniem);
printf("\nWstawiam %f do k i wypisuje liste: \n", 8.44);
k=wstaw_we_wlasciwe_miejsce(k, 8.44);
wypisz_kolejke(k);
printf("\nWstawiam %f do pustej kolejki f i wypisuje: \n", 1.00);
f=wstaw_we_wlasciwe_miejsce(f, 1.00);
wypisz_kolejke(f);
kolejka asd=inicjalizuj();
asd=dopisz_na_koniec(asd, 4.32);
printf("\nStan kolejki asd: ");
wypisz_kolejke(asd);
printf("\nDopisuje %f do jednoelementowej kolejki asd i wypisuje ja: \n", 6.54);
asd=wstaw_we_wlasciwe_miejsce(asd, 6.54);
wypisz_kolejke(asd);
}
