#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
long long l[111111];
long long r[111111];
int ab[111111];
struct cm
{
	int index;
	long long value;	
}a[111111];

bool cmp(cm a,cm b)
{
	if(a.value==b.value) return a.index<b.index;
	else return a.value<b.value;
}
int main()
{
	int n;
	int maxx=-1;int maxi=0;
	long long left=0;
	long long right=0;
	scanf("%d",&n);

	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&l[i],&r[i]);
		left+=l[i];
		right+=r[i];
	}
	long long ans=abs(left-right);
	int cnt=0;
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		left=left-l[i]+r[i];
		right=right-r[i]+l[i];
		long long t=abs(left-right);
		if(t>ans) a[cnt].index=i,a[cnt++].value=t,flag=1;
		left=left-r[i]+l[i];
		right=right-l[i]+r[i];
	}

	sort(a,a+n,cmp);

	if(!flag) cout<<0<<endl;
	else cout<<a[n-1].index<<endl;
	return 0;
	
}