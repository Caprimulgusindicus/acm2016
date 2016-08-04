#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    int a[111];
    while(~scanf("%d",&n))
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]==1) ans++;
        }
        for(int i=2;i<n;i++)
        {
            if(a[i]==0&&a[i-1]==1&&a[i+1]==1)
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
