#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int vis[11111];
int dp[111][2222];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(dp,0,sizeof(dp));
		int n;
		dp[0][0]=1;

		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			int kk;
			scanf("%d",&kk);
			for(int j=0;j<=2000;j++)
			{
				if(!dp[i-1][j]) continue;
				dp[i][j]=dp[i-1][j];
				dp[i][j+kk]=1;
				if(j>kk) dp[i][j-kk]=1;
				else dp[i][kk-j]=1;
			}
		}
			
		int m;
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			int q;
			scanf("%d",&q);
			if(dp[n][q]) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}


	}
	return 0;
}