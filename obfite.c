#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


int obf(int liczba)
{
int suma=0;
  for (int i=1; i<=(liczba/2); i++)
  {
    if (!(liczba%i))
      suma+=i;
  }//for
  if (suma>liczba)
    return suma;
  else
    return (liczba-1);
}//obf



void znajdz(int liczba)
{
int parzysta=0, nieparzysta=0, wynik=0;
if (liczba==INT_MAX)
{
printf ("BRAK BRAK\n");
return;
}//if
liczba++;
int poml=liczba;
do
{
if (poml==INT_MAX)
{
printf ("BRAK BRAK\n");
return;
}
wynik=obf(poml);
}
while (wynik<=(poml++));
poml--;
if (poml%2)
  nieparzysta=(poml);
else
  parzysta=(poml);

poml-=1;
do
{
poml+=2;
if (poml==INT_MAX || poml+1==INT_MAX)
{
  if (nieparzysta==0)
  {
  printf ("%d %s\n", parzysta, "BRAK");
  return;
  }
  else if (parzysta==0)
  {
  printf ("%s %d\n", "BRAK", nieparzysta);
  return;
  }
}//if
wynik=obf(poml);
}
while (wynik<=poml);

if (poml%2)
  nieparzysta=poml;
else
  parzysta=poml;

printf ("%d %d\n", parzysta, nieparzysta);
}//znajdz



int main()
{
int m;
scanf ("%d", &m);
znajdz(m);
system("pause");
}
