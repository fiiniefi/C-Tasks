#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void wczytaj(double tablica[][3])
{
for (int i=0; i<2; i++)
    for (int p=0; p<3; p++)
        scanf("%lf", &tablica[i][p]);
}

void wczytdl(double tablica[])
{
for (int i=0; i<3; i++)
    scanf("%lf", &tablica[i]);
}

void wypisz(double tablica[])
{
for (int i=0; i<3; i++)
    printf("%.2f ", tablica[i]);
printf("\n");
}

void dodaj(double tablica[][3])
{
wczytaj(tablica);
for (int i=0; i<3; i++)
    tablica[0][i]=tablica[0][i]+tablica[1][i];
}

void odejmij(double tablica[][3])
{
wczytaj(tablica);
for (int i=0; i<3; i++)
    tablica[0][i]=tablica[0][i]-tablica[1][i];
}

double iloczyn(double tablica[][3])
{
wczytaj(tablica);
for (int i=0; i<3; i++)
    tablica[0][i]=tablica[0][i]*tablica[1][i];
tablica[1][0]=0;
for (int i=0; i<3; i++)
    tablica[1][0]+=tablica[0][i];
return tablica[1][0];
}

void mnozenie(double tablica[])
{
wczytdl(tablica);
double liczba;
scanf("%lf", &liczba);
for (int i=0; i<3; i++)
    tablica[i]*=liczba;
}

double dlugosc(double tablica[])
{
wczytdl(tablica);
double dlug=sqrt((tablica[0]*tablica[0])+(tablica[1]*tablica[1])+(tablica[2]*tablica[2]));
return dlug;
}


int main()
{
double tablica[2][3];
double tabdl[3];
int co;
while(co!=EOF)
{
    co=getchar();
    switch (co)
    {
    case '+':
    dodaj(tablica);
    wypisz(tablica[0]);
    break;

    case '-':
    odejmij(tablica);
    wypisz(tablica[0]);
    break;

    case '*':
    printf("%.2f \n", iloczyn(tablica));
    break;

    case '.':
    mnozenie(tabdl);
    wypisz(tabdl);
    break;

    case '|':
    printf("%.2f \n", dlugosc(tabdl));
    break;

    default:
    break;
    }
}
}
