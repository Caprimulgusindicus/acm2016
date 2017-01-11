#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
int a[1005];
int l[1005];
int r[1005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	
	int sum=0;
	int cnt=0;
	int cal=0;
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		if(!a[i]) cal++;
		if(!flag)
		{
			if(a[i]!=0) l[cnt]=i,r[cnt]=i,cnt++;
			else if(a[i]==0) flag=1,l[cnt]=i;
		}
		if(flag)
		{
			sum+=a[i];
			if(sum!=0) flag=0,r[cnt]=i,cnt++,sum=0;
		}
	}
	if(cal==n) puts("NO");	
	else
	{
		if(sum==0&&flag)
		r[cnt-1]=n;
		
		puts("YES");
		cout<<cnt<<endl;
		for(int i=0;i<cnt;i++)
			cout<<l[i]<<" "<<r[i]<<endl;
	}
	return 0;
}