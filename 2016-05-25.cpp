#include <stdio.h>
#include <iostream>
using namespace std;
long long gcd(long long a,long long b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
   int n;
   long long x,g,maxx;
   scanf("%d",&n);
   maxx=0;
   for(int i=1;i<=n;i++)
   {
       scanf("%I64d",&x);
       if(i!=1)
            g=gcd(g,x);
       else
            g=x;
       maxx=max(maxx,x);
   }
   long long ans=maxx/g-n;
   if(ans%2!=0) puts("Alice");
    else puts("Bob");
    return 0;
}
