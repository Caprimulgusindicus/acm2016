#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int s[99];
	int a[99];
	//01234567891011121314151413121110987654321012345678910
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(n==1&&a[1]!=0&&a[1]!=15) puts("-1");
	else if(n==1&&a[1]==0) puts("UP");
	else if(n==1&&a[1]==15) puts("DOWN"); 
	else if(a[n]!=0&&n!=1&&a[n]!=15)
	{
		
		if(a[n]>a[n-1]) puts("UP");
		else puts("DOWN");
	}
	else if(a[n]==0&&n!=1)
	{
		puts("UP");
	}
	else if(a[n]==15&&n!=1)
		puts("DOWN");
	else puts("-1");
	return 0;
}