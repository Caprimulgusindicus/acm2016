#include <iostream>
#include <stdio.h>
using namespace std;
int a[222][222];
int main()
{
    for(int i=1;i<=201;i++)
        for(int j=1;j<=201;j++)
            a[i][j]=0;
    for(int i=1;i<=201;i++)
        a[i][1]=1;

    for(int i=2;i<=201;i++)
        for(int j=2;j<=i+1;j++)
            a[i][j]=(a[i-1][j]+a[i-1][j-1])%1000000;

    int n,m;
    while(~scanf("%d%d",&n,&m)&&m&&n)
        cout<<a[n+m][m]<<endl;
    return 0;
}
