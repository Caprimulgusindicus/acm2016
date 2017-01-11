#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
struct people
{
	int vis=0;
	int maxi;
	ll min;
	ll max;
}a[222222];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int in;ll value;
		scanf("%d%lld",&in,&value);
		if(a[in].vis==0) a[in].min=value;
		else a[in].max=max(a[in].max,value),a[in].maxi=max(a[in].maxi,i);
	}
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int k;
		scanf("%d",&k);
		for(int i=1;i<=k;i++) 
			
	}
	return 0;
}