#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
int p[2333][2333];
int q[2333][2333];
int w[2333];
int ans;
void dfs(int dep)
{
    int temp=0;
    if(dep>=n)
    {
        for(int i=1;i<=n;i++)
            temp+=p[i][w[i]]*q[w[i]][i];
        if(temp>ans)
            ans=temp;
    }
    else
    {
        for(int j=dep;j<=n;j++)
        {
            swap(w[dep],w[j]);
            dfs(dep+1);
            swap(w[dep],w[j]);
        }
    }
}
int main()
{
    while(~scanf("%d",&n))
    {
        ans=0;
        for(int i=1;i<=n;i++)
            w[i]=i;

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&p[i][j]);

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&q[i][j]);

        dfs(1);
        cout<<ans<<endl;
    }
    return 0;
}
