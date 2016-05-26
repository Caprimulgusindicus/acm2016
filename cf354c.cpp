#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int main()
{
    char s[1111111];
    int x[111111];
    int n,k;
    memset(x,0,sizeof(x));
    scanf("%d%d",&n,&k);
    scanf("%s",&s);
    for(int i=0;i<=n;i++)
            x[i+1]=x[i]+(s[i]=='a');

    int l=1;
    int r=1;
    int c=0;
    while(l<=n)
    {
        while(r<=n&&x[r]-x[l-1]<=k)
        {
            c=max(c,r-l+1);
            r++;
        }
        l++;
    }
    for(int i=0;i<=n;i++)

            x[i+1]=x[i]+(s[i]=='b');

    l=1,r=1;
    while(l<=n)
    {
        while(r<=n&&x[r]-x[l-1]<=k)
        {
            c=max(c,r-l+1);
            r++;
        }
        l++;
    }
    printf("%d\n",c);


    return 0;
}
