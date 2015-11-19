#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int n,m;
    int a[233][233];
    while(~scanf("%d%d",&n,&m))
    {
        int ans=0;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m*2;j++)
                scanf("%d",&a[i][j]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m*2;j+=2)
                if(a[i][j]==1||a[i][j+1]==1) ans++;
        cout<<ans<<endl;

    }
    return 0;
}
