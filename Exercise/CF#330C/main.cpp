#include <iostream>
#include <stdio.h>
using namespace std;
long long a[222222];
long long abs(long long x)
{
    return x>0?x:-x;
}
//∏√Ã‚”–¥Ì
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        long long  minn=1111111111111111;
        for(int i=1;i<=n;i++)
        {
            scanf("%I64d",&a[i]);
        }
        if(n==2) printf("%I64d\n",abs(a[2]-a[1]));
        else
        {

            for(int i=1;i<=n/2;i++)
                if(a[i+n/2]-a[i]<minn) minn=a[i+n/2]-a[i];
            cout<<minn<<endl;
        }



    }
    return 0;
}

