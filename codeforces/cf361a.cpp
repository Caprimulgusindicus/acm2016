#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
#include <string.h>
using namespace std;
long long w[111111];
string s1[111111];
string s2[111111];
long long dp[111111][5];

int main()
{
	memset(w,0,sizeof(w));
	
	int n;
	scanf("%d",&n);
	for(int i=1;i<=111111;i++)
		dp[i][0]=1e15+10,dp[i][1]=1e15+10;
	for(int i=1;i<=n;i++)
		scanf("%I64d",&w[i]);
	getchar();
	for(int i=1;i<=n;i++)
	{
		cin>>s1[i];//,cout<<s[i]<<endl;
		s2[i]=s1[i];
		reverse(s2[i].begin(),s2[i].end());
	}	
	dp[1][0]=0;
	dp[1][1]=w[1];
	for(int i=2;i<=n;i++)
	{
		if(s1[i]>=s1[i-1])
			dp[i][0]=min(dp[i][0],dp[i-1][0]);
		if(s1[i]>=s2[i-1])
			dp[i][0]=min(dp[i][0],dp[i-1][1]);
		if(s1[i-1]<=s2[i])
			dp[i][1]=min(dp[i][1],dp[i-1][0]+w[i]);
		if(s2[i-1]<=s2[i])
			dp[i][1]=min(dp[i][1],dp[i-1][1]+w[i]);
	}
	long long ans=min(dp[n][0],dp[n][1]);
	//cout<<ans<<endl;
	if(ans<1e15+10)
		printf("%I64d\n",ans);
	else printf("-1\n");

	return 0;
}