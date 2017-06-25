#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "funkcje.h"

ulamek wczytaj()
{
int a,b;
char c=0;
while (c!='/' || b==0)
    scanf("%d%c%d", &a, &c, &b);
return skroc(a, b);
}

ulamek skroc(int a, int b)
{
if (b<0)
{
    a*=-1;
    b*=-1;
}
int pa=a, pb=b, pc;
if (pa<0)
    pa*=-1;
while (pb)
{
    pc=pb;
    pb=pa%pb;
    pa=pc;
}
a/=pa;
b/=pa;
return scal(a,b);
}

ulamek scal(int a, int b)
{
ulamek zwroc;
zwroc=0;
zwroc=a;
zwroc<<=32;
zwroc|=b;
return zwroc;
}

void wyodrebnij (ulamek kopia, int* a, int* b)
{
*b=kopia;
kopia>>=32;
*a=kopia;
}

void wypisz(ulamek kopia)
{
int a,b;
wyodrebnij(kopia, &a, &b);
printf("%d%c%d\n", a, '/', b);
}

void nww(int* a, int* b, int* c, int* d)
{
int e=*b, f=*d;
int ileb=1, iled=1;
while((*b)!=(*d))
{
    if((*b)<(*d))
    {
        (*b)+=e;
        ileb++;
    }
    if ((*d)<(*b))
    {
        (*d)+=f;
        iled++;
    }
}
(*a)*=ileb;
(*c)*=iled;
}

ulamek dodaj(ulamek pierwszy, ulamek drugi)
{
int pierwszaa, pierwszab, drugaa, drugab;
wyodrebnij(pierwszy, &pierwszaa, &pierwszab);
wyodrebnij(drugi, &drugaa, &drugab);
nww(&pierwszaa, &pierwszab, &drugaa, &drugab);
int wynika, wynikb;
wynika=pierwszaa+drugaa;
wynikb=pierwszab;
return skroc(wynika, wynikb);
}

ulamek odejmij(ulamek pierwszy, ulamek drugi)
{
int pierwszaa, pierwszab, drugaa, drugab;
wyodrebnij (pierwszy, &pierwszaa, &pierwszab);
wyodrebnij (drugi, &drugaa, &drugab);
nww(&pierwszaa, &pierwszab, &drugaa, &drugab);
int wynika, wynikb;
wynika=pierwszaa-drugaa;
wynikb=pierwszab;
return skroc(wynika, wynikb);
}

ulamek pomnoz(ulamek pierwszy, ulamek drugi)
{
int pierwszaa, pierwszab, drugaa, drugab;
wyodrebnij (pierwszy, &pierwszaa, &pierwszab);
wyodrebnij (drugi, &drugaa, &drugab);
int wynika, wynikb;
wynika=pierwszaa*drugaa;
wynikb=pierwszab*drugab;
return skroc(wynika, wynikb);
}

ulamek podziel(ulamek pierwszy, ulamek drugi)
{
int drugaa, drugab;
wyodrebnij (drugi, &drugaa, &drugab);
drugi=skroc(drugab, drugaa);
return pomnoz(pierwszy, drugi);
}
