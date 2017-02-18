#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
long long f[1111111];
long long h[1111111];
long long g[1111111];

int main()
{
	long long n;
	long long m;
	while(~scanf("%lld",&n)){
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&f[i]);
		g[i]=f[i];
		h[i]=f[i];
	}
	long long flag=0;
	for(long long i=1;i<=n;i++)
		if(g[h[i]]!=i||h[g[i]]!=f[i]) flag=1;
	
	if(flag)
	{
		long long flag2=0;
		m=f[1];
		for(long long i=1;i<=n;i++) g[i]=1;
		for(long long i=1;i<=m;i++)
			if(g[h[i]]!=1) flag2=1;
		for (long long i=0;i<=n;i++)
		{
			if(h[g[i]]!=f[i]) flag2=1;
		}
		//cout<<flag2;
		if(!flag2) flag=2;
	}

	if(flag==1) puts("-1");
	else if(flag==2)
	{
		cout<<1<<endl;
		for(long long i=1;i<=n;i++)
			printf("%lld ",1);
		cout<<endl;
		cout<<m<<endl;
	}
	else 
	{
		cout<<n<<endl;
		for(long long i=1;i<=n;i++)
			printf("%lld ",f[i]);
		cout<<endl;
		for(long long j=1;j<=n;j++)
			printf("%lld ",f[j]);
		cout<<endl;
	}
}
	return 0;
}