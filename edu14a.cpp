#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int n;
	int a[1111];
	scanf("%d",&n);
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		if(k==0) flag++;//没有被扣住的个数
	}
	if(n==1)
	{
		if(flag==0) puts("YES");
		else puts("NO");
	}
	else
	{
		if(flag==1) puts("YES");
	else puts("NO");
	}
	
	return 0;
}