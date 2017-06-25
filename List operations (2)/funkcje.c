//Marcin Drewniak
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "definicje.h"

kolejka inicjalizuj()
{
return NULL;
}

kolejka dopisz_na_poczatek(kolejka k, double x)
{
    if (k == NULL)
    {
        k=(kolejka)malloc(sizeof(wezel));
        k->informacja=x;
        k->nastepny=k;
    }

    else
    {
        kolejka p;
        p=(kolejka)malloc(sizeof(wezel));
        p->informacja=x;
        p->nastepny=k->nastepny;
        k->nastepny=p;
    }
return k;
}

kolejka dopisz_na_koniec(kolejka k, double x)
{
    if (k == NULL)
    {
        k=(kolejka)malloc(sizeof(wezel));
        k->informacja=x;
        k->nastepny=k;
    }

    else
    {
        kolejka p;
        p=(kolejka)malloc(sizeof(wezel));
        p->informacja=x;
        p->nastepny=k->nastepny;
        k->nastepny=p;
        k=p;
    }
return k;
}

double wartosc_z_poczatku(kolejka k)
{
    kolejka p=k->nastepny;
    return p->informacja;
}

double usun_wartosc_z_poczatku(kolejka *k)
{
    if (czy_pusta(*k))
        return NAN;
    kolejka p=((*k)->nastepny);
    double wartosc=p->informacja;
    (*k)->nastepny=(p)->nastepny;
    if (p->nastepny == p)
        *k=NULL;
    free(p);
    return wartosc;
}

bool czy_pusta(kolejka k)
{
    if (k == NULL)
        return 1;
    else
        return 0;
}

int dlugosc_listy(kolejka k)
{
    int licznik;
    if (k == NULL)
        return 0;
    else
    {
        kolejka p=k->nastepny;
        licznik=1;
        kolejka n=p->nastepny;
        while (n!=p)
        {
            licznik++;
            n=n->nastepny;
        }
    }
    return licznik;
}

void wypisz_kolejke(kolejka k)
{
    if (k == NULL)
    {
        printf("Kolejka jest pusta!\n\n");
        return;
    }

    else
    {
    kolejka p=k->nastepny;
    kolejka n=p;
    do
    {
        printf("%f ", n->informacja);
        n=n->nastepny;
    }
    while (n!=p);
    printf("\n\n");
    }
}


/********************************************************/
/********************Zadanie 2***************************/
/********************************************************/


kolejka polacz_bez_kopiowania(kolejka k, kolejka p)
{
if (p==NULL && k==NULL)
{
printf("Bledne dane!\n");
exit(0);
}
else if (p==NULL)
    return k;
else if (k==NULL)
    return p;
kolejka pomocniczy=k->nastepny;
k->nastepny=p->nastepny;
p->nastepny=pomocniczy;
return p;
}


kolejka skopiuj(kolejka k, kolejka p)
{
kolejka zapamietaj, pomocniczy;
bool info=0;
    if (p==NULL)
    {
    return k;
    }
p=p->nastepny;
zapamietaj=p;
    if (k==NULL)
    {
    info=1;
    k=(kolejka)malloc(sizeof(wezel));
    k->nastepny=k;
    k->informacja=p->informacja;
    p=p->nastepny;
    }
    if (info && zapamietaj==p)
        return k;
    do
    {
    pomocniczy=k;
    k=(kolejka)malloc(sizeof(wezel));
    k->nastepny=pomocniczy->nastepny;
    pomocniczy->nastepny=k;
    k->informacja=p->informacja;
    p=p->nastepny;
    }
    while (p!=zapamietaj);

return k;
}


kolejka quicksort(kolejka k)
{
kolejka zapamietaj, wieksze=NULL, mniejszerowne=NULL, pomocniczy, posortowana;
if (k==NULL)
{
printf("Bledne dane!\n");
exit(0);
}
else if (k==k->nastepny)
    return k;

k=k->nastepny;
double piwot=k->informacja;
zapamietaj=k;
k=k->nastepny;

    while (zapamietaj!=k)
    {
        if ((k->informacja) <= piwot)
        {
            if (mniejszerowne==NULL)
            {
            mniejszerowne=(kolejka)malloc(sizeof(wezel));
            mniejszerowne->nastepny=mniejszerowne;
            mniejszerowne->informacja=k->informacja;
            }

            else
            {
            pomocniczy=mniejszerowne;
            mniejszerowne=(kolejka)malloc(sizeof(wezel));
            mniejszerowne->nastepny=pomocniczy->nastepny;
            pomocniczy->nastepny=mniejszerowne;
            mniejszerowne->informacja=k->informacja;
            }
        }

        else if ((k->informacja) > piwot)
        {
            if (wieksze==NULL)
            {
            wieksze=(kolejka)malloc(sizeof(wezel));
            wieksze->nastepny=wieksze;
            wieksze->informacja=k->informacja;
            }

            else
            {
            pomocniczy=wieksze;
            wieksze=(kolejka)malloc(sizeof(wezel));
            wieksze->nastepny=pomocniczy->nastepny;
            pomocniczy->nastepny=wieksze;
            wieksze->informacja=k->informacja;
            }
        }

    k=k->nastepny;
    }


kolejka pierwszy=NULL, pierw=NULL;

    if (mniejszerowne != NULL)
    {
    pierwszy=mniejszerowne->nastepny;
    mniejszerowne=sortowanie_rekurencyjne(mniejszerowne, pierwszy);
    }

    if (wieksze != NULL)
    {
    pierw=wieksze->nastepny;
    wieksze=sortowanie_rekurencyjne(wieksze, pierw);
    }

    if (mniejszerowne == NULL && wieksze == NULL)
    {
    posortowana=(kolejka)malloc(sizeof(wezel));
    posortowana->nastepny=posortowana;
    posortowana->informacja=piwot;
    return posortowana;
    }

    else if (mniejszerowne == NULL)
    {
    posortowana=(kolejka)malloc(sizeof(wezel));
    posortowana->informacja=piwot;
    posortowana->nastepny=pierw;
    wieksze->nastepny=posortowana;
    return wieksze;
    }

    else if (wieksze == NULL)
    {
    posortowana=mniejszerowne;
    pomocniczy=(kolejka)malloc(sizeof(wezel));
    pomocniczy->nastepny=pierwszy;
    pomocniczy->informacja=piwot;
    mniejszerowne->nastepny=pomocniczy;
    return pomocniczy;
    }

    else
    {
    posortowana=mniejszerowne;
    pomocniczy=(kolejka)malloc(sizeof(wezel));
    mniejszerowne->nastepny=pomocniczy;
    pomocniczy->nastepny=pierw;
    wieksze->nastepny=pierwszy;
    pomocniczy->informacja=piwot;
    return wieksze;
    }
}


kolejka sortowanie_rekurencyjne(kolejka k, kolejka pierwszy)
{
if(k==NULL)
    return NULL;

else if (k == (k->nastepny))
    return k;
kolejka ostatni=k, pomocnicza;
double zmienna;

while ((k->nastepny)!=ostatni)
    k=k->nastepny;

    if ((k->informacja) > (ostatni->informacja))
    {
    zmienna=ostatni->informacja;
    ostatni->informacja=k->informacja;
    k->informacja=zmienna;
    }
if(k==pierwszy)
    return ostatni;


    do
    {
    pomocnicza=k;
    while((k->nastepny)!=pomocnicza)
        k=k->nastepny;

        if ((k->informacja) > (ostatni->informacja))
        {
        zmienna=ostatni->informacja;
        ostatni->informacja=k->informacja;
        k->informacja=zmienna;
        }
    }
    while (k!=pierwszy);
while ((k->nastepny)!=ostatni)
    k=k->nastepny;
sortowanie_rekurencyjne(k, pierwszy);
return ostatni;
}


kolejka sortowanie_przez_wstawianie(kolejka k)
{
bool czy_wiekszy;
kolejka posortowana=NULL, zapamietaj, poprzedni=NULL, pomocnicza=NULL, zapamietajpos;
if (k==NULL)
{
printf("Bledne dane!\n");
exit(0);
}
if (k == k->nastepny)
    return k;

k=k->nastepny;   //pierwszy element k
posortowana=(kolejka)malloc(sizeof(wezel));
posortowana->nastepny=posortowana;
posortowana->informacja=k->informacja;
zapamietaj=k;  //pierwszy element k
zapamietajpos=posortowana; //pierwszy element, potem sie zmienia sie
k=k->nastepny;   //drugi element k
    while (k!=zapamietaj)   //dopoki k nie jest pierwszym elementem
    {
    poprzedni=posortowana;
    czy_wiekszy=0;

    if ((k->informacja) > ((posortowana)->informacja))
    {
    czy_wiekszy=1;
    posortowana=posortowana->nastepny;
        while ((k->informacja) > ((posortowana)->informacja) && ((posortowana)!=zapamietajpos))
        {
        poprzedni=posortowana;
        posortowana=posortowana->nastepny;
        }
    }
        if(!czy_wiekszy)
        {
        posortowana=zapamietajpos;
        while ((posortowana->nastepny)!=zapamietajpos)
            posortowana=posortowana->nastepny;
        pomocnicza=zapamietajpos;
        zapamietajpos=(kolejka)malloc(sizeof(wezel));
        zapamietajpos->nastepny=pomocnicza;
        posortowana->nastepny=zapamietajpos;
        zapamietajpos->informacja=k->informacja;
        }

        else
        {
        pomocnicza=poprzedni;
        poprzedni=(kolejka)malloc(sizeof(wezel));
        poprzedni->nastepny=pomocnicza->nastepny;
        poprzedni->informacja=k->informacja;
        pomocnicza->nastepny=poprzedni;
        }

    k=k->nastepny;
    posortowana=zapamietajpos;
    }//while

while((posortowana->nastepny)!=zapamietajpos)
    posortowana=posortowana->nastepny;

return posortowana;
}


kolejka wstaw_we_wlasciwe_miejsce(kolejka k, double x)
{
    if (k==NULL)
    {
    k=(kolejka)malloc(sizeof(wezel));
    k->nastepny=k;
    k->informacja=x;
    return k;
    }

kolejka zapamietaj, pomocniczy, poprzedni;
bool czy_najmniejszy=1;
poprzedni=k;
k=k->nastepny; //pierwszy element
zapamietaj=k;

    if (k == k->nastepny)
    {
    pomocniczy=(kolejka)malloc(sizeof(wezel));
    pomocniczy->nastepny=k;
    k->nastepny=pomocniczy;
    pomocniczy->informacja=x;
    if (x < (k->informacja))
        return k;
    else
        return pomocniczy;
    }

    if ( x > (k->informacja))
    {
    czy_najmniejszy=0;
    poprzedni=k;
    k=k->nastepny;
        while ( x > (k->informacja) &&  k!=zapamietaj)
        {
        poprzedni=k;
        k=k->nastepny;
        }
    }

    if (czy_najmniejszy)
    {
    pomocniczy=poprzedni;
    poprzedni=(kolejka)malloc(sizeof(wezel));
    poprzedni->nastepny=pomocniczy->nastepny;
    pomocniczy->nastepny=poprzedni;
    poprzedni->informacja=x;
    zapamietaj=poprzedni;
    }

    else if(!czy_najmniejszy)
    {
    pomocniczy=poprzedni;
    poprzedni=(kolejka)malloc(sizeof(wezel));
    poprzedni->nastepny=pomocniczy->nastepny;
    pomocniczy->nastepny=poprzedni;
    poprzedni->informacja=x;
    }

while ((k->nastepny)!=zapamietaj)
    k=k->nastepny;
return k;
}
