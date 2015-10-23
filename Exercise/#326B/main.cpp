#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
long long n;
long long ans;
int main()
{
    while(~scanf("%I64d",&n))
    {

        for(long long  i=2;i*i<=n;i++)
            while(n%(i*i)==0)
                n/=i;
        printf("%I64d\n",n);
    }
    return 0;
}
