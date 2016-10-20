#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
int a[44];
const int maxn= 1<<20 ;
ll dp[44][maxn+5];

int main()
{
	int T;
	scanf("%d",&T);
	for(int ca=1;ca<=T;ca++)
	{
		memset(dp,0,sizeof(dp));
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		dp[0][0]=1ll;
		
		for(int i=1;i<=n;i++)
			for(int j=0;j<=maxn-5;j++)//异或和为j的时候存在的方案数
			{
				dp[i][j]=max(dp[i][j],dp[i-1][j]+dp[i-1][j^a[i]]);
			}
		long long ans=0;
		for(int i=m;i<=maxn-5;i++)
			ans+=dp[n][i];
		cout<<"Case #"<<ca<<": ";
		cout<<ans<<endl;
	}
	return 0;
}