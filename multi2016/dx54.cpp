#include <iostream>
#include <stdio.h>
using namespace std;
double dist[2222][2222];
struct point
{
	long long x;
	long long y;
}p[2222];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++)
			scanf("%lld%lld",&p[i].x,&p[i].y);
		printf("%d\n",0);
	}
	return 0;
}