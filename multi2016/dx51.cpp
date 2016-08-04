#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
long long a[1111111];

int main()
{
	long long n;
	while(scanf("%I64d",&n)!=EOF)
	{
		memset(a,0,sizeof(a));
		long long ans=0;
		for(long long i=1;i<=n;i++)
		{
			scanf("%I64d",&a[i]);	
		}
		
		
		
			long long sum=0;
			for(long long i=n;i>=1;i--)
			{
				sum+=a[i];
				if(sum>=0) {ans++;sum=0;}
			}
		
		    printf("%I64d\n",ans);
		
	}
	return 0;
}