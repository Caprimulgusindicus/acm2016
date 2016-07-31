#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
char x[222222];
long long axis[222222];
int main()
{
	int n;
	scanf("%I64d",&n);
	int flag=0;
	long long ans=1111111111;
	getchar();
	
	for(int i=1;i<=n;i++)
		scanf("%c",&x[i]);
	for(int i=1;i<=n;i++)
		scanf("%I64d",&axis[i]);

	for(int i=1;i<n;i++)
	{
		if(x[i]=='R'&&x[i+1]=='L')
		{
			flag=1;
			long long t=(axis[i+1]-axis[i])/2;
			ans=min(ans,t);
		}
	}
	if(flag==0) puts("-1");
	else printf("%I64d\n",ans);
	//printf("%d",1111111111);
	return 0;
}