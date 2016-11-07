#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct rtg
{
	long long e[3];
}a[111111];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&a[i].e[0],&a[i].e[1],&a[i].e[2]);
		sort(a[i].e,a[i].e+3);
	}
	return 0;
}