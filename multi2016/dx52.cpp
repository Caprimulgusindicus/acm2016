#include <stdio.h>
#include <iostream>
using namespace std;
#define MOD 1000000007
long long a[1111];
long long b[1111];
long long dp[1111][1111];
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=1;i<=n;i++)
			scanf("%I64d",&a[i]);
		for(int i=1;i<=m;i++)
			scanf("%I64d",&b[i]);
		dp[0][0]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + (a[i]==b[j]?dp[i - 1][j - 1] + 1 : 0)%MOD;
			}
		printf("%I64d\n",dp[n][m]%MOD);
//		cout<<dp[n][m]<<endl;
	}
	return 0;
}

