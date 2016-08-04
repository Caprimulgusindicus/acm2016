#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[22222];
int b[22222];
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0) break;
		int ans=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=m;i++)
			scanf("%d",&b[i]);
		//cout<<a[1]<<endl;
		sort(a+1,a+1+n);
		sort(b+1,b+1+m);
		int cnt=n;
		int now=1;
		for(int i=1;i<=m;i++)
		{
			if(a[now]<=b[i]) now++,ans+=b[i];
			if(now==n) break;
		}
		if(now==n) cout<<ans<<endl;
		else cout<<"Loowater is doomed!"<<endl;
	}
	return 0;
}