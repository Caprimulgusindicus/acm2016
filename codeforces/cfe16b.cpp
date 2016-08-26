#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
struct point
{
	int index;
	long long val;
};
point a[333333];

void find(long long x)
{
	for(int i=0;i<n;i++)
		if(a[i].val==x) 
			{
				printf("%I64d\n",a[i].val);break;}
}

bool cmp(point a1,point a2)
{
	if(a1.val!=a2.val)
		return a1.val<a2.val;
	else return a1.index<a2.index;
}

int main()
{
	
	memset(a,0,sizeof(a));
	scanf("%d",&n);
	
	for(int i=0;i<n;i++)
		scanf("%I64d",&a[i].val),a[i].index=i+1;
	sort(a,a+n,cmp);
	//for(int i=0;i<n;i++)
	//cout<<a[i].index<<" "<<a[i].val<<endl;
	if(n>2){
	if(n%2==0)
	find(a[n/2-1].val);
	else find(a[n/2].val);}

	else printf("%I64d\n",a[0].val);
	return 0;
}

