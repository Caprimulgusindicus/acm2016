#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n,k,ans;
int a[11111];
int main()
{
    while(~scanf("%d%d",&n,&k))//k个加油站,加满油可走n
    {
        ans=0;
        int sum=0;
        for(int i=1;i<=k+1;i++)
            scanf("%d",&a[i]);

        for(int i=1;i<=k+1;i++)
        {
            sum+=a[i];
            if(sum>n)
            {
                ans++;
                sum=a[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
