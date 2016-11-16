#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
	char s[111111];

int main()
{
	long long a,b,c,d;//2,3,5,6
	long long ans=0;
	scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&d);
	long long k=min(a,c);
	k=min(c,d);
	ans+=k*256;
	a-=k,c-=k,d-=k;
	if(a>0&&b>0)
	{
		k=min(a,b);
		ans+=32*k;
	}
	cout<<ans<<endl;
	return 0;
}