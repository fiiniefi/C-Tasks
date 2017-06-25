#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


void rozbij(unsigned int liczba)
{
int i=2, p=0;
bool boo=0;
while (liczba>0)
{
    while (!(liczba%i))
    {
    liczba=liczba/i;
    p++;
    }

        if (p)
        {
            if (!boo)
            {
            printf("%d%c%d", i, '^', p);
            boo=1;
            }
            else
            printf("%c%d%c%d", '*', i, '^', p);
        }
    p=0;

    if (liczba==1)
    {
    liczba-=1;
    }
    i++;
}//while
printf("%c", '\n');
}//rozbij



int main()
{
unsigned int liczba;
scanf ("%u", &liczba);
if (liczba==1)
{
printf("1^1");
return 0;
}
else if (liczba<=0)
return 0;
rozbij(liczba);
}
