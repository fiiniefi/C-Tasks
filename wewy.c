#include <stdlib.h>
#include <stdio.h>
#define rozmiar 10000

void zeruj(char tablica[])
{
for (int i=0; i<rozmiar; i++)
    tablica[i]=0;
}


void wczytaj(char tablica[])
{
int a=0, i=0;
while ((a=getchar())!=EOF && i<rozmiar)
    tablica[i++]=a;
tablica[i]='\n';
}

void wypisz(char tablica[], int m, int n)
{
int i=0, s=0, p, linia=0, linia2=0;
while(tablica[i])
{
        linia=0;
        printf("\n");
        for (int p=1; p<m; p++)
            printf(" ");
        linia+=m-1;

    while (linia<=n && tablica[i])
    {
        for (s=i, p=i; tablica[s]!=' ' && tablica[s]!='\n' && tablica[s]!='\t'; s++)
        {
            if ((s-i)+linia>n)
            {
            p=s;
            linia+=(s-i);
            break;
            }
        }

        if ((s-i)>(1+n-m))
        {
        printf("Za dlugie slowo!\n");
        return;
        }
        linia2=linia;
        if (p==i)
        {
        while (tablica[i]!=' ' && tablica[i]!='\n' && tablica[i]!='\t')
        {
        printf("%c", tablica[i++]);
        linia++;
        }
        if (linia2!=linia)
        {
        printf(" ");
        linia++;
        }
        i++;
        }
    }
}

}


int main(int argc, char* argv[])
{
char tablica[rozmiar];
int m,n;
if (argc<=2)
{
printf("Brak argumentow \n");
return 1;
}
sscanf(argv[1], "%d", &m);
sscanf(argv[2], "%d", &n);
if ((m>=n) || (n>=200))
{
printf("Bledne dane! \n");
return 1;
}
zeruj(tablica);
wczytaj(tablica);
wypisz(tablica, m, n);
}
