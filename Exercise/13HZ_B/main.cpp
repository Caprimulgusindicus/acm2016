#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <queue>
#include <string.h>
#include <algorithm>
using namespace std;
char ma[111][111];
int vis[111][111];
int ans;
int dir[4][2] = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
int path[10][10];
int n;
int m;
int k;

struct node
{
    int x;
    int y;
};

node point[11];
int bfs(node start,node to)//算两点间的最短路
{
    queue <node> q;
    memset(vis,-1,sizeof(vis));
    q.push(start);
    vis[start.x][start.y]=0;
    while(!q.empty())
    {
        node u=q.front();
        q.pop();

        if(u.x==to.x&&u.x==to.y)
            return vis[u.x][u.y];
        for(int i=0;i<4;i++)
        {
            int xi=u.x+dir[i][0];
            int yi=u.y+dir[i][1];
            if(xi>n||xi<=0) continue;
            if(yi>m||yi<=0) continue;
            if(vis[xi][yi]!=-1||ma[xi][yi]=='#') continue;

            node next;
            next.x=xi;
            next.y=yi;
            q.push(next);
            vis[xi][yi]=vis[u.x][u.y]+1;
        }
    }
    return -1;
}

bool judge()
{
    memset(path,0,sizeof(path));

    for(int i=0;i<=k;i++)
        for(int j=i+1;j<=k;j++)
        {
            int t=bfs(point[i],point[j]);
            if(t==-1) return false;
            path[i][j]=path[j][i]=t;
        }
    return true;
}

int dfs()
{
    int pos[11];
    for (int i = 0; i <= k; i++)
    pos[i] = i;

  int ans = 0x3f3f3f3f;
  do {
    int sum = 0;
    for (int i = 0; i < k; i++)
      sum += path[pos[i]][pos[i+1]];
    ans = min (ans, sum);
  } while(next_permutation(pos + 1, pos + k + 1));

  return ans;
}

int main()
{

    while(~scanf("%d%d",&n,&m))
    {
        memset(ma,0,sizeof(ma));
         for (int i = 1; i <= n; i++) {
            scanf("%s", ma[i] + 1);
    for (int j = 1; j <= m; j++)
      if (ma[i][j] == '@') {
        point[0].x = i;
        point[0].y = j;
      }
  }
        //cout<<point[0].x<<" "<<point[0].y<<endl;
        //for(int i=1;i<=n;i++){
        //    for(int j=1;j<=m;j++)
        //        cout<<ma[i][j];
        //cout<<endl;}
        scanf("%d",&k);
        for(int i=1;i<=k;i++)
        {
            scanf("%d%d",&point[i].x,&point[i].y);

        }

        if(judge()) cout<<dfs()<<endl;
            else cout<<"-1"<<endl;

    }
    return 0;
}
