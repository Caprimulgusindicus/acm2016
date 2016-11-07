#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int sg[111];
int vis[111];//标记该状态是否出现过
void init()
{
	sg[0]=0;
	sg[1]=1;

	for(int i=2;i<=100;i++)
	{
		memset(vis,0,sizeof(vis));//对于每一个状态，找出它的所有后继状态
		for(int j=1;j<i;j++)
			for(int k=1;k+j<i;k++)
				vis[sg[j]^sg[k]^sg[i-j-k]]=1;//枚举每一种分成三堆，把出现过的sg函数标记
		for(int j=0;j<i;j++) vis[sg[j]]=1;//枚举每一种直接后继状态，把所出现过的sg函数进行标记
		int j;
	for(j=0;;j++) 
		if(!vis[j]) break;//找出后继状态中所没有出现过的最小非负整数
	sg[i]=j;

	}

}


int main()
{
	//init();
	int T;
	//cout<<int((1^2)&1)<<endl;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		long long k;
		long long t;
		//scanf("%lld",&k);
		long long a=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&k);
			if(k%8==0) t=k-1;
			else if((k+1)%8==0) t=k+1; 
			else t=k;
			a^=t;
			//cout<<a<<endl;
		}
		//cout<<t<<endl;
		if(a!=0) puts("First player wins.");
		else puts("Second player wins.");
	}
	return 0;
}