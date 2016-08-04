#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    long long  n;
    while(~scanf("%lld",&n))
    {
        long long step=0;
        while(n>1)
        {
            if(!(n&1))
            {
                step+=n;
                n/=2;
            }
            else
            {
                step+=n/2+1;
                step+=n/2+1;
                n=n/2*3+2;
            }
        }
    printf("%lld\n",step);
    }
    return 0;
}
