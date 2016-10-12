#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
ll dp[22][11][3];
ll f[22];
int a[22];

ll dfs(int p,int x,int l,int flag)
{
	ll ans=0;int num=0;
	if(p<=1) return 1;
	if(dp[p][x][l]!=-1&&!flag) 
		return dp[p][x][l];
	num=flag?a[p-1]:9;
	for(int i=0;i<=num;i++)
	{
		int flag2=0;
		if(num==i&&flag) flag2=1;
		if(x==i&&l==0) ans+=dfs(p-1,i,0,flag2);
		if(x<=i&&l==1) ans+=dfs(p-1,i,1,flag2);
		if(x>=i&&l==2) ans+=dfs(p-1,i,2,flag2);
	}
	if(!flag) dp[p][x][l]=ans;
	return ans;
}

ll solve(ll x)
{
	memset(a,0,sizeof(a));
	ll p=0;		
	ll ans=0;

	while(x)//将每一位拆出来
	{
		p++;
		a[p]=x%10;
		x/=10;
	}

	for(int i=1;i<a[p];i++)
		ans+=dfs(p,i,1,0)+dfs(p,i,2,0)-dfs(p,i,0,0);
	ans+=dfs(p,a[p],1,1)+dfs(p,a[p],2,1)-dfs(p,a[p],0,1);
	return ans+f[p-1];
}

int main()
{
	int T;
	ll l,r;
	memset(dp,-1,sizeof(dp));
	ll x=0;
	for(int i=1;i<=18;i++)
	{
		x=x*10+9;
		f[i]=solve(x);
	}

	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&l,&r);
		ll anss=solve(r)-solve(l-1);
		printf("%lld\n",anss);
	}
}