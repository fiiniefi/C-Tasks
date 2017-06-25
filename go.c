#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>




int main()
{
int n=0, lczar=0, lbial=0, maxczar=0, maxbial=0, a=0, b=0, c=0;
while (n==0 && a!=EOF)
{
    if ((a=getchar())=='S')
        if ((a=getchar())=='Z')
            if ((a=getchar())=='[')
                if ((a=getchar())>='0' && a<='9')
                {
                ungetc(a, stdin);
                scanf ("%d", &n);
                    if ((a=getchar())!=']')
                        n=0;
                }
}

if ((n>19) || (n<=0))
    return 0;
char tablica[n+2][n+2];
tablica[0][0]=' ';

for (int i=1; i<n+1; i++)
    tablica[0][i]=((i-1)+'A');

for (int i=1; i<n+1; i++)
{
tablica[i][0]=(i-1)+'A';
    for (int p=1; p<n+1; p++)
        tablica[i][p]='.';
}

for (int i=0; i<n+1; i++)
    tablica[i][n+1]='\n';
tablica[n+1][0]=0;

/******************************************************************/

while (a!='\n')
{
a=getchar();
    if (a==';')
    {
    a=getchar();
        if (a=='B')
        {
        a=getchar();
            if (a=='[')
            {
            a=getchar();
                if ( a-'a'<=n )
                {
                b=getchar();
                    if (b-'a'<=n)
                    {
                    tablica[(b+1)-'a'][(a+1)-'a']='X';
                    c=getchar();
                        if (c!=']')
                        {
                        tablica[(b+1)-'a'][(a+1)-'a']='.';
                        a=c;
                        continue;
                        }//c!=']'
                    }//b-'a'
                    else
                    {
                    a=b;
                    continue;
                    }//else
                }//a-'a'
                else
                    continue;
            }//'['
            else
                continue;
        }//'B'

        else if (a=='W')
        {
        a=getchar();
            if (a=='[')
            {
            a=getchar();
                if (a-'a'<=n)
                {
                b=getchar();
                    if (b-'a'<=n)
                    {
                    tablica[(b+1)-'a'][(a+1)-'a']='O';
                    c=getchar();
                        if (c!=']')
                        {
                        tablica[(b+1)-'a'][(a+1)-'a']='.';
                        a=c;
                        continue;
                        }//c!=']'

                    }//b-'a'
                    else
                    {
                    a=b;
                    continue;
                    }//else
                }//a-'a'
                else
                    continue;
            }//'['
            else
            continue;
        }//'W'

        else
            continue;
    }//';'

}//while

for (int i=0; i<n+2; i++)
{
    for (int p=0; p<n+2; p++)
    {
        if (tablica[i][p]=='O')
            lbial++;
        else if (tablica[i][p]=='X')
            lczar++;
    }//for p
if (lczar>maxczar)
    maxczar=lczar;
lczar=0;
if (lbial>maxbial)
    maxbial=lbial;
lbial=0;

}//for i
lbial=lczar=0;
/***********************************************************/

for (int i=0; i<n+1; i++)
{
    for (int p=0; p<n+2; p++)
    {
    if (p==0)
        printf("%c", tablica[i][p]);
    else
        printf(" %c", tablica[i][p]);

    }
}


printf("%d %d", maxczar, maxbial);
//system("pause");
}
