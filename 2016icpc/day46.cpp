#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
	int v[11111];
	int cost[11111];
	int dis[11111][11111];
	int s[11111];
int main()
{

	int n;
	while(~scanf("%d",&n))
	{
		memset(v,0,sizeof(v));
		memset(cost,0,sizeof(cost));
		memset(dis,0,sizeof(dis));
		memset(s,0,sizeof(s));
		for(int i=0;i<n;i++)
			scanf("%d",&s[i]);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				dis[i][j]=dis[j][i]=s[i]^s[j];

		for(int i=0;i<n;i++)
		{
			cost[i]=111111;
			v[i]=0;
		}
		cost[0]=0;
		int ans=0;
		while(1)
		{
			int t=-1;
			for(int i=0;i<n;i++)
			{
				if(!v[i]&&(t==-1||cost[i]<cost[t])) t=i;
			}
			if(t==-1) break;
			ans+=cost[t];
			v[t]=1;
			for(int i=0;i<n;i++)
				cost[i]=min(cost[i],dis[t][i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}