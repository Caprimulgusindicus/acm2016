#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
	long long k,a,b;
	//for(long long k=1;k<=40;k++)
	//for(long long a=0;a<=20;a++)
	//	for(long long b=0;b<=20;b++)
	while(~scanf("%lld%lld%lld",&k,&a,&b))
	{
		//cout<<k<<" "<<a<<" "<<b<<" ";
		int flag=0;
		if(a<k&&b<k) flag=1;
		long long resa=a%k;
		long long resb=b%k;
		long long sum=a/k+b/k;
		if(a>=k&&b<k&&resa!=0) flag=1;
		if(b>=k&&a<k&&resb!=0) flag=1;

		if(flag) cout<<-1<<endl;
		else printf("%lld\n",sum);
	}
	return 0;
}