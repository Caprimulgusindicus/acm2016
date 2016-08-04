#include<stdio.h>
#include <iostream>
using namespace std;
int main()
{
    long long  a,b,c;
    while(~scanf("%I64d%I64d%I64d",&a,&b,&c))
    {
        if(a==b) puts("YES");
        else if(c==0&&(a!=b)) puts("NO");
        else if((b-a)/c*c==(b-a)&&((b-a)/c>0)) puts("YES");
        else puts("NO");
    }

    return 0;
}
