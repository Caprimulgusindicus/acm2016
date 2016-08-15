#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;
int maze[10][10];
int vis[10][10];
int fx[5]={0,1,0,-1};
int fy[5]={1,0,-1,0};

struct Node
{
	int x,y,step,prex,prey;
	friend bool operator < (Node a,Node b)
	{
		return a.step>b.step;
	}
};

Node path[5][5];
void fin(int ex,int ey)
{
	stack <Node> rec;
	Node now;
	now=path[ex][ey];
	rec.push(now);
	while(1)
	{
		now=path[now.prex][now.prey];
		rec.push(now);
		if(now.x==0&&now.y==0)
			break;
	}
	while(!rec.empty())
	{
		now=rec.top();
		rec.pop();
		printf("(%d, %d)\n",now.x,now.y);
	}
}

void bfs()
{
	priority_queue <Node> q;
	Node now,next;
	now.x=0,now.y=0,now.step=0;
	q.push(now);
	vis[now.x][now.y]=1;
	while(!q.empty())
	{
		now=q.top();
		q.pop();
		if(now.x==4&&now.y==4) {path[now.x][now.y]=now;break;}

		for(int i=0;i<4;i++)
		{
			next.x=now.x+fx[i];
			next.y=now.y+fy[i];
			int xx=next.x;
			int yy=next.y;
			next.step=now.step+1;
			if(next.x<0||next.x>=5||next.y<0||next.y>=5) continue;
			if(maze[xx][yy]!=0) continue;
			if(vis[xx][yy]!=0) continue;
			vis[next.x][next.y]=1;
			next.prex=now.x;
			next.prey=now.y;
			q.push(next);
			path[next.x][next.y]=next;
		}
	}
	fin(4,4);
}

int main()
{
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			scanf("%d",&maze[i][j]);//,res[i][j]=-1;
	//point init;
	//init.x=0;init.y=0;
	memset(vis,0,sizeof(vis));
	bfs();
	
	return 0;
}