#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n,m;

    while(~scanf("%d%d",&n,&m))
    {
        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m*2;j+=2)
            {
                int x;int y;
                scanf("%d%d",&x,&y);
                if(x||y) ans++;
            }
        cout<<ans<<endl;

    }
    return 0;
}
