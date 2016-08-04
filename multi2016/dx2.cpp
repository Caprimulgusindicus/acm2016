#include <iostream>
#include <stdio.h>
#include <cmath>
#include <cstring>
using namespace std;
int range[1111111];

struct point
{
	int first;
	int second;
}zb[111111];


int main()
{
	int t;
	scanf("%d",&t);
	for(int ii=1;ii<=t;ii++)
	{
		memset(range,0,sizeof(range));
		int flag=0;
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			int dis;
			scanf("%d%d",&zb[i].first,&zb[i].second);
			for(int j=i-1;j>=1;j--)
					{
						int x1=zb[i].first;
						int y1=zb[i].second;
						int x2=zb[j].first;
						int y2=zb[j].second;
						if(x1<x2) swap(x1,x2);
						if(y1<y2) swap(y1,y2);
						dis=x1-x2+(y1-y2);
						range[dis]++;
						//cout<<dis<<endl;
						if(range[dis]>=2) {flag=1;break;}

					}
		}

		if(flag==0)
			puts("NO");
		else puts("YES");
	}
	return 0;
}