#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	long long a;
	long long ans=0;
	scanf("%lld",&a);
	for(long long i=1;i<=a;i++)
		if(i&1)//jishu
			ans-=i;
		else ans+=i;
	printf("%lld\n",ans);
	return 0;
}