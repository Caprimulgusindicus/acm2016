#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int n, m, t;
int vis[25][25][1<<10];//取得钥匙的状态 

struct node
{
    int x;
    int y;
    int s;
    int step;
};

char M[25][25];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int gao(int x,int k) //x的k+1位是1还是0 
{
    return (x>>k)&1;
}

int bfs(node s) 
{
    queue <node> q;
    q.push(s);
    memset(vis,0,sizeof(vis));
    vis[s.x][s.y][0]=1;
    while(!q.empty()) 
    {
        node u=q.front();
        q.pop();
        if(M[u.x][u.y]=='^') 
            return u.step;
        
        for(int i=0;i<4;i++) 
        {
            int xx=u.x+dx[i];
            int yy=u.y+dy[i];
            if(xx<0||xx>=n||yy<0||yy>=m) continue;
            if(M[xx][yy]=='*') continue;
            if(M[xx][yy]>='A'&&M[xx][yy]<='J'&&!(gao(u.s,M[xx][yy]-'A'))) 
            	continue;
            //遇到门没钥匙 
            node next=u;
            if(M[xx][yy]>='a'&&M[xx][yy]<='j') 
            {    
            	//遇到钥匙 
                if(!gao(u.s,M[xx][yy]-'a')) 
                {         
                	//没钥匙 
                    next.x=xx,next.y=yy,next.step++;
					next.s|=(1<<(M[xx][yy]-'a'));
                    if(next.step<t&&!vis[xx][yy][next.s]) 
                    {
                        vis[xx][yy][next.s]=1;
                        q.push(next);
                    }
                }
                else 
                {                                    
                //有钥匙 
                    next.x=xx,next.y=yy,next.step++;
                    if(!vis[xx][yy][u.s]&&next.step<t) 
                    {
                        vis[xx][yy][next.s]=1;
                        q.push(next);    
                    }
                }
            }
            else 
            {                                        
            	//没遇到钥匙 
                next.x=xx,next.y=yy,next.step++;
                if(next.step<t&&!vis[xx][yy][next.s]) 
                {
                    vis[xx][yy][next.s]=1;
                    q.push(next);
                }
            }
        }
    }
    return -1;
}

int main() 
{
    while(~scanf("%d%d%d",&n,&m,&t)) 
    {
        for(int i=0;i<n;i++)
            scanf("%s",M[i]);

        node s;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(M[i][j]=='@')
                    s.x=i,s.y=j;

        s.s=s.step=0;
        int ans=bfs(s);
        printf("%d\n",ans);
    }
    return 0;
}