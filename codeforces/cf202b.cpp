#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int a[111111];
int main()
{
	int v;
	while(~scanf("%d",&v))
	{
		memset(a,0,sizeof(a));
		int minn=111111;int minni=10;
		for(int i=1;i<=9;++i)
		{
			scanf("%d",&a[i]);
			if(a[i]<=minn) minni=i,minn=a[i];
		}
		if(minn>v) {puts("-1");continue;}
		
		int cnt=v/minn;
		int rest=v-cnt*minn;

		int found=0;
		queue <int> q;
		for(int i=1;i<=cnt;i++)//位数
		{
			
			for(int j=9;j>=1;j--)
				if(rest+a[minni]-a[j]>=0)//去掉一个cost最小的后足以放下另一个
					{q.push(j),rest+=a[minni],rest-=a[j];found=1;break;}

		}			

		if(!found)
		{
			for(int i=1;i<=cnt;i++)
				printf("%d",minni);
			puts("");
		}
		else
		{
			while(!q.empty())
			{
				cout<<q.front();
				q.pop();
			}
			puts("");
		}
		
	}
	return 0;
}