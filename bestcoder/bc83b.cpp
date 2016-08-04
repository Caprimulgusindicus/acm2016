#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int d[22222];
int a[22222];
int r[22222];
int b[22222];
int main()
{
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        memset(d,0,sizeof(d));
        memset(a,0,sizeof(a));
        memset(r,0,sizeof(r));
        memset(b,0,sizeof(b));
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<n;i++)
        {
            scanf("%d",&d[i]);
        }
        for(int i=1;i<=n;i++
        {
            scanf("%d%d%d",&a[i],&r[i],&b[i]);
        }
    }
    return 0;
}
