#include <stdio.h>
#include <iostream>
using namespace std;

int gcd(int a,int b)
{
    if(b==0) return a;
    else return gcd(b,a%b);
}


int main()
{
    int ct;
    int t;
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        int a;int b;int n;
        scanf("%d%d%d",&n,&a,&b);

        int ans=n/gcd(a,b);
        ans-=2;
        printf("Case #%d: ", k);
        if(ans<=0)  puts("Iaka");
        else if(ans%2==0) puts("Iaka");
        else puts("Yuwgna");

    }
    return 0;
}
