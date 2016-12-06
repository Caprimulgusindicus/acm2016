#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
long long a[111];
int vis[111];


long long gcd(long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}

long long lcm(long long a,long long b)//求最小公倍数
{
    return a/gcd(a,b)*b;
}
int main()
{
	int  n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	
	long long ans=1;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		if(!vis[i])
		{
			long long k=i;
			long long s=0;
			//cout<<k<<endl;
			do
			{
				vis[k]=1;
				s++;
				k=a[k];
			}while(!vis[k]);
			if(k!=i)
			{
				puts("-1");return 0;
			}

			//cout<<s<<endl;
			if(s&1) ans=lcm(ans,s);
			else ans=lcm(ans,s/2);
		}
	cout<<ans<<endl;
	return 0;
}