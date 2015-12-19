#include <iostream>
#include <stdio.h>
using namespace std;

long long cal(int n)
{
    if(n==1) return 1;
    else if(n&1) return cal(n/2)*3+1;
    else return cal(n/2)*3;
}

int main()
{
    int ca;
    long long n;
    while(~scanf("%d",&ca))
    {
        while(ca--)
        {
        scanf("%I64d",&n);
        if(n==1) puts("1");
        else printf("%I64d\n",cal(n));
        }
    }

    return 0;
}
