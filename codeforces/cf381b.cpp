#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int a[222];
int dp[111][111];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	//dp[1][0]=0;
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		int l,r;
		int t=0;
		scanf("%d%d",&l,&r);
		for(int j=l;j<=r;j++)
			t+=a[j];
		if(t>0) ans+=t;
	}
	cout<<ans<<endl;
	return 0;
}