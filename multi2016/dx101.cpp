#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int num1[10]={0,3,3,5,4,4,3,5,5,4};
int num2[10]={0,3,6,6,5,5,5,7,6,6};
int num3[10]={0,6,6,8,8,7,7,9,8,8};
int prime[1111];
int sum[1111];

int main()
{
    memset(prime,0,sizeof(prime));

    for(int i=1;i<=9;i++)
        prime[i]=num1[i];
    for(int i=10;i<=90;i=i+10)
        prime[i]=num2[i/10];
    for(int i=11;i<=19;i++)
        prime[i]=num3[i%10];

    for(int i=21;i<=99;i++)
    {
        if(i%10==0)
            continue;
        prime[i]=num1[i%10]+num2[i/10];
    }
    prime[1000]=11;
    for(int i=100;i<=900;i=i+100)
        prime[i]=num1[i/100]+7;

    for(int i=101;i<=999;i++)
    {
        if(i%100==0)
            continue;
        prime[i]=num1[i/100]+10+prime[i%100];
    }

    for(int i=1;i<=1000;i++)
        sum[i]=sum[i-1]+prime[i];

    int T;
    scanf("%d",&T);
    int n;
    while(T--)
    {
        scanf("%d",&n);
        printf("%d\n",sum[n]);
    }
    return 0;
}