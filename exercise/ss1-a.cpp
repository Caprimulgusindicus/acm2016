#include <iostream>
#include <stdio.h>
using namespace std;
char ma[10][10];
int vis[10];
int ans;

void dfs(int n)
{

}

int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k))
    {
        if(n<0&&k<0) break;
        getchar();
        ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                scanf("%c",&ma[i][j]);
            getchar();
        }

    }
    return 0;
}
