#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;
struct point
{
    ll x;
    ll y;
//    long long double x;
}p[111111];
long long pf(long long  n)
{
    return n*n;
}

double dist(point a,point b)
{
    return pf(a.x-b.x)-pf(a.y-b.y);
}

int main()
{
    ll ax,ay,bx,by,tx,ty,n;
    while(~scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&ax,&ay,&bx,&by,&tx,&ty))
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%I64d%I64d",&p[i].x,&p[i].y);
        }
    }
    return 0;
}
