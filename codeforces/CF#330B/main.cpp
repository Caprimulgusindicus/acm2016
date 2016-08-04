#include <iostream>
#include <stdio.h>
const int mod=1e9+7;
using namespace std;
        long long a[111111];
        long long  b[111111];
        long long ans[111111];
int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k))
    {

        for(int i=1;i<=n/k;i++)
            scanf("%I64d",&a[i]);
        for(int i=1;i<=n/k;i++)
            scanf("%I64d",&b[i]);
        long long lala[15];
        lala[0]=1;
        for(int i=1;i<=10;i++)
            lala[i]=lala[i-1]*10;

        long long t1,t2,t3;
        for(int i=1;i<=n/k;i++)
        {
            t1=(lala[k]-1)/a[i]+1;
            t2=((b[i]+1)*lala[k-1]-1)/a[i]+1;
            if(b[i]==0)
                ans[i]=t1-t2;
            else
            {
                t3=(b[i]*lala[k-1]-1)/a[i]+1;
                ans[i]=t1-t2+t3;
            }
        }
        long long res=1;
        for(int i=1;i<=n/k;i++)
            res=(res*ans[i])%mod;
        printf("%I64d\n",res);
    }
    return 0;
}
