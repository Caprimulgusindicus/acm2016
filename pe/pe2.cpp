#include <cstdio>
#include <iostream>
using namespace std;
long long vis[4444444];
int main()
{
	long long ans=2;
	long long a=1;
	long long b=2;
	for(long long i=3;i<=33;i++)
	{
		long long t=a+b;
		
		a=b;
		b=t; 
		if(b%2==0&&b<=4000000)
			vis[t]=1;
		//cout<<b<<" "<<ans<<endl;
	}
	for(int i=1;i<=4000000;i++)
		if(vis[i]==1) ans+=i;
	//ans+=2;
printf("%lld\n",ans);
	return 0;
}