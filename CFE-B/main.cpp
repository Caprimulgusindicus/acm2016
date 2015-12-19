#include <iostream>
#include <stdio.h>
using namespace std;
int a[100005*2];
int b;
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%I64d",&a[i]);

    for(int i=1;i<=m;i++)
    {
        scanf("%I64d",&b);
        int ans=0;
        for(int j=1;j<=n;j++)
        {
            if(a[j]<=b) ans++;
        }
        if(i!=m) printf("%d ",ans);
        else printf("%d",ans);
    }


    return 0;
}
