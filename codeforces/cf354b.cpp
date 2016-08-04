#include <iostream>
#include <stdio.h>
using namespace std;
double a[15][15];
int main ()
{
    int n,t;
    scanf("%d%d",&n,&t);
    while(t--)
    {
        a[0][0]++;
        for(int i=0;i<n;i++)
            for(int j=0;j<=i;j++)
                if(a[i][j]>1)
                {
                    double tmp=a[i][j]-1;
                    a[i][j]-=tmp;
                    a[i+1][j]+=tmp/2;
                    a[i+1][j+1]+=tmp/2;
                }
    }
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<=i;j++)
            if(a[i][j]>=1)
            cnt++;
    printf("%d\n", cnt);
    return 0;
}
