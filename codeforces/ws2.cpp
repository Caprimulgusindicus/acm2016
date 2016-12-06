#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int dp[222222];
int h[222222];
int s[222222];
int m,n;

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				scanf("%d",&s[j]);
				if(j==1) dp[j]=s[j];
				else dp[j]=max(dp[j-2]+s[j],dp[j-1]);
			}
			h[i]=dp[m];
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
			if(i==1) dp[i]=h[1];
			else dp[i]=max(dp[i-2]+h[i],dp[i-1]);

		cout<<dp[n]<<endl;
	}
	return 0;
}