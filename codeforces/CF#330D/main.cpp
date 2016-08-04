#include <iostream>
#include <stdio.h>
#include <cmath>
#define PI 3.1415926
using namespace std;
int n, r, v;

int main()
{
    scanf("%d%d%d",&n,&r,&v);
    while(n--)
    {
        int s, f;
        scanf("%d %d", &s, &f);
        long double dist=f-s;
        long double ans=0;
        int k=(int)dist/(2*PI*r);
        dist-=k*(2*PI*r);
        ans+=k*(2*PI*r)/v;
        dist /= 2;
        long double L=0.0,R = dist;
        int T=60;
        while(T--)
        {
            long double mid=(L+R)/2 ;
            if(mid+r*sin(mid/r)>dist)
                R=mid;
            else
                L=mid;
        }
        ans+=2*L/v;
        printf("%.10lf\n",double(ans));
    }
    return 0;
}
