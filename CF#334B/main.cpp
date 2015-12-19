#include <iostream>
#include <stdio.h>
using namespace std;
int n;
int k;
int a[111111];
int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        int ans=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        int tmp=n-k;
        int cnt=n;
        int j=1;
        while(tmp--)
        {
            j+=2;
        }
        ans=max(a[j-1]+a[j-2],a[n]);
        //ans=max(ans,a[n]);
        cout<<ans<<endl;
    }
    return 0;
}
