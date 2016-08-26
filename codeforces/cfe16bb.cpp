#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
long long a[333333];
long long dis[333333];
long long ab(long long x)
{
	if(x>0) return x;
	else return -x;
}

int main()
{
	memset(a,0,sizeof(a));
	memset(dis,0,sizeof(dis));
	int n;
	while(~scanf("%d",&n)){
		long long minn=0x3f3f3f3f;

	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j) dis[i]+=ab(a[j]-a[i]);
	int index=1;

	for(int i=1;i<=n;i++)
		if(dis[i]<minn) minn=dis[i],index=i;
	printf("%d\n",a[index]);}
	return 0;
}