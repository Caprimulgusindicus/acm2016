#include <cstdio>
#include <iostream>
using namespace std;
int dp[1111111][1111111];

int main()
{
	int n,x,y;
	scanf("%d%d%d",&n,&x,&y);
	int cnt=0;
	int t=0;
	dp[0][0]=x;
	while(cnt!=n)
	{
		if(dp[][]>)
			dp[1][0]=
		else 

	}
	return 0;
}
for (int i = 1; i <= n; ++i) 
{
		dp[i * 2] = min(dp[i * 2], dp[i] + y);
		dp[i * 2 - 1] = min(dp[i * 2 - 1], dp[i] + y + x);
		dp[i + 1] = min(dp[i + 1], dp[i] + x);
	}