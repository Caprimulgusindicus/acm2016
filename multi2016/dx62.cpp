#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
long long split(long long iNum)
{
long long iCount=0;
iNum=abs(iNum);
while (iNum)
{
iCount+=iNum%2;
iNum/=2;
}
return iCount;
}
int main()
{
    long long T;
    scanf("%I64d", &T);
    while(T--)
    {
        long long n;
        scanf("%I64d", &n);
        long long a = 0, s = 0;
        for (long long i = 1; i <= n; i++)
        {
            long long k;
            scanf("%I64d", &k);
            a ^= k;
            s += split(k);
        }
        long long ans=0;
        if (a > 0)
        {
            if ((s - split(a)) % 2 == 0)
                ans = 1;
            else ans = 2;
        }
        else
        {
            if ((s - split(a)) % 2 == 0)
                ans = 2;
            else ans = 1;
        }
        if (ans == 1) printf("First player wins.\n");
        else printf("Second player wins.\n");
    }
}