//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int n,m;
int map[88][88];
int sum[88];
int vis[5555];
int viss[3]={0,2,0};

struct edge
{
    int from;
    int to;
    int now;
}ans[5555];

int init()
{
    memset(vis,0,sizeof(vis));
    memset(map,0,sizeof(map));
    memset(sum,0,sizeof(sum));
}

int solve(int now,int num)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i!=j&&!map[i][j]&&!map[j][i])
            {
                int tmp=now%3;
                
                if( (j>i&& ((sum[j]-sum[i]+3)%3==tmp) )||( (j<= i && (sum[i]-sum[j]+3+tmp)%3==0) ) )
                    {
                        map[i][j]=1;
                        ans[num].from=i;
                        ans[num].to=j;
                        ans[num].now=now;
                        return 1;
                    }
                
            }
        }
    }
    return 0;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        init();
       
        scanf("%d%d",&n,&m);
        sum[1]=0;
        for(int i=1;i<n;i++)
        {
            ans[i].from=i,ans[i].to=i+1,ans[i].now=i;
            vis[i]=1;
            map[ans[i].from][ans[i].to]=1;
            if(i!=1) sum[i]=(sum[i-1]+i-1)%3;
        }

        ans[n].from=n;
        ans[n].to=1;
        map[n][1]=1;
        ans[n].now=n+viss[n%3];
        vis[ans[n].now]=1;
        sum[n]=(sum[n-1]+n-1)%3;

        int num=n;
        int flag=1;

        for(int i=1;i<=m;i++)
        {
            if(!vis[i])
            {
                flag=solve(i,++num);
                if(!flag) break;
            }
        }

        printf("Case #%d:\n",ca);

        if(!flag)
        {
            printf("-1\n");
        }
        else for(int i=1;i<=m;i++)
        {
            printf("%d %d %d\n",ans[i].from,ans[i].to,ans[i].now);
        }
    }
    return 0;
}