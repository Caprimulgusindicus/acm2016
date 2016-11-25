#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
long long a[222222];
long long b[222222];
long long c[222222];
long long d[222222];

int main()
{
	long long n,m,k;
	scanf("%lld%lld%lld",&n,&m,&k);//n potion,m first type, k second type
	long long s=0,x=0;
	scanf("%lld%lld",&x,&s);//initial spend tim, can use
	for(int i=1;i<=m;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)
	{	scanf("%lld",&b[i]);}
//ttt=min(ttt,b[i]);}
	for(int i=1;i<=k;i++)//get immediatly
		scanf("%lld",&c[i]);
	for(int i=1;i<=k;i++)
		scanf("%lld",&d[i]);
	

	
		long long ans=x*n;
		
		for(int i=1;i<=m;i++)//先做第一种
		{
			long long t=s-b[i];
			if(t<0) continue;//如果不能做第一种，就继续下一个
			//long long money2=s-b[i];//剩下的钱等于总钱数减去只做第一种的
			long long tans=a[i]*n;

			int t2=upper_bound(d+1,d+1+k,t)-d-1;//最后一个可做第二种的位置，即减去最多的数量
			if(t2>0) 
			{
				tans-=min(c[t2],n)*a[i];
			}
			ans=min(tans,ans);//如果剩下的钱还可以做第二种，取更小的

		}
		


		//只做第二种
		int tt3=upper_bound(d+1,d+1+k,s)-d-1;
		if(tt3>0) ans=min(x*(n-min(c[tt3],n)),ans);
		
		printf("%lld\n",ans);

	
	return 0;
}