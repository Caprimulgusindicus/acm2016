#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int r[15];
int c[15];
int a[15];
int radius[15];
int vis[55][55];

int abs(int x)
{
    return x>0?x:-x;
}

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        if(n==0) break;
        int ans=2333;
        int k;
        scanf("%d",&k);
        for(int i=0;i < k;i++)
            scanf("%d%d",&r[i],&c[i]);

        for(int i=0;i<k;i++)
            scanf("%d",&radius[i]);

        for(int test=0;test<(1<<k);test++)
        {
            memset(vis,0,sizeof(vis));
            int temp=0;
            int flag=1;

            for(int i=0;i<k;i++)
              if(test&(1<<i))
              {
                  a[temp++]=i;
              }

            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                {
                    for(int x=0;x<k;x++)
                        if(i==r[x]&&j==c[x])
                            vis[i][j]=1;

                    if(vis[i][j]==1) continue;

                    for(int x=0;x<temp;x++)
                    {
                        if(abs(i-r[a[x]])+abs(j-c[a[x]])<=radius[a[x]])
                        {
                            vis[i][j]=1;
                            break;
                        }
                    }

                    if(vis[i][j]==0) flag=0;
                    if(!flag)break;
                }

            if(!flag) continue;
            if(ans>temp) ans=temp;
            ans=min(ans,temp);
        }
        if(ans>250)
            ans=-1;
        printf("%d\n",ans);
    }
    return 0;
}
