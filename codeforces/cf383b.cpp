#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int vis[1<<21];

int main()
{
	int n,x;
	scanf("%d%d",&n,&x);
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		int t;
		scanf("%d",&t);
		ans+=vis[t^x];
		vis[t]++;
	}	
	cout<<ans<<endl;
	return 0;
}