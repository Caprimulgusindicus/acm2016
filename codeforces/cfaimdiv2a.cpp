#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int a[111111];
int main()
{
	long long  n,b,d;
	scanf("%I64d%I64d%I64d",&n,&b,&d);
	long long waste=0;
	long long cnt=0;
	for(int i=1;i<=n;i++)
	{
		long long m;
		scanf("%I64d",&m);
		if(m<=b)
			waste+=m;
		if(waste>d) {cnt++;waste=0;}
	}	
	printf("%I64d\n",cnt);
	return 0;
}