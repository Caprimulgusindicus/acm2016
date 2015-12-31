#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int n,m;
    //int a[111111];
    int b[111];
    int ans;
    while(~scanf("%d%d",&n,&m))
    {
        memset(b,0,sizeof(b));
        ans=0;
        for(int i=1;i<=n;i++)
        {
            int a;
            scanf("%d",&a);
            b[a]++;
           // cout<<b[a]<<endl;
        }
        for(int i=1;i<=10;i++)
        {
            for(int j=i+1;j<=10;j++)
             {
                 ans+=b[i]*b[j];
                //cout<<b[i]<<" "<<ans<<endl;
             }
        }
        cout<<ans<<endl;

    }
    return 0;
}
