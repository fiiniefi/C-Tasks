#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int n=4;
bool wartosci[(4*4)+1];
int kwadrat[4][4];

bool sprawdz_ustawienie()
{
int suma=0, sumad=0;

for (int i=0; i<n; i++)
{
suma+=kwadrat[n-2][i];
sumad+=kwadrat[n-1][i];
}

if (sumad!=suma)
    return 0;

sumad=0;
for (int i=0; i<n; i++)
{
    for (int p=0; p<n; p++)
        sumad+=kwadrat[p][i];
    if (sumad!=suma)
        return 0;
    sumad=0;
}

for (int i=0; i<n; i++)
    sumad+=kwadrat[i][i];
if (suma!=sumad)
    return 0;
sumad=0;

for (int i=n-1, p=0; i>=0; i--, p++)
    sumad+=kwadrat[i][p];
if (suma!=sumad)
    return 0;
return 1;
}


void  wszystkie_wolne()
{
for (int i=1; i<(n*n)+1; i++)
    wartosci[i]=1;
}


bool kwadratf(int ktory)
{
if (ktory==(n*n))
    return sprawdz_ustawienie();
else if (!(ktory%n) && ktory!=n)
{
int suma=0, sumad=0;
for (int i=0; i<n; i++)
    suma+=kwadrat[0][i];
for (int i=1; i<ktory/n; i++)
{
    for (int p=0; p<n; p++)
        sumad+=kwadrat[i][p];

    if (sumad!=suma)
        return 0;
    else
        sumad=0;
}
}
for (int i=1; i<(n*n)+1; i++)
{
bool czy;
while (i<((n*n)+1) && wartosci[i]==0)
{
i++;
}

if (i>=(n*n)+1)
    return 0;
wartosci[i]=0;
printf("%d   ", ktory);
kwadrat[ktory/n][ktory%n]=i;
if ((czy=kwadratf(ktory+1)))
    return 1;
wartosci[i]=1;
}
return 0;
}


void narysuj()
{
    for (int i=0; i<n; i++)
        {for (int p=0; p<n; p++)
            printf("%d ", kwadrat[i][p]);
        printf("\n");
        }
}

bool wywolaj()
{
wszystkie_wolne();
return kwadratf(1);
}

int main()
{
bool czy=wywolaj();
if (czy)
    narysuj();
}
