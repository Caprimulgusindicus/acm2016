#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>
using namespace std;
int ma[11][11];
int fx={1,0,-1,0};
int fy={0,1,0,-1};

void bfs(int x,int y)
{
	queue <point> q;
}

int main()
{
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			scanf("%d",&ma[i][j]);

	bfs(0,0);
	for(int i=1;i<=lu;i++)
		printf("(%d, %d)\n",a[i].x,a[i].y);
	return 0;
}