#include <iostream>
#include <stdio.h>
using namespace std;
long long a[111111];
long long cap[111111];
int main()
{
	long long ans=0;
	long long sum=0;
	long long m,n;
	scanf("%I64d%I64d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		sum+=a[i];
	}
	for(int i=1;i<=m;i++)
		scanf("%I64d",&cap[i]);//,cout<<a[cap[i]]<<endl;

	for(int i=1;i<n;i++)
		ans+=a[i]*a[i+1];
	ans+=a[1]*a[n];
	//cout<<ans<<endl;
	if(n>3)
	{
		for(int i=1;i<=m;i++)
		{
			long long t=cap[i];//cap位置
			//cout<<t<<endl;
			if(t==1)//如果位置是1 
				ans+=(sum-a[n]-a[t]-a[2])*a[t];//,cout<<ans<<endl;
			else if(t==n)
				ans+=(sum-a[t]-a[1]-a[n-1])*a[t];
			else 
				ans+=(sum-a[t]-a[t+1]-a[t-1])*a[t];
			sum-=a[t];
			a[t]=0;
		}
		
	}
	
	printf("%I64d\n",ans);
	return 0;
}