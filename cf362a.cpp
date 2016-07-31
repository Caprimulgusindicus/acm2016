#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	long long t,s,x;
	scanf("%I64d%I64d%I64d",&t,&s,&x);

	if(x==t+1) {puts("NO");return 0;}
	if((x>=t)&&((x-t)%s==0)) puts("YES");
	else if ((x>=t+1)&&(x-t)%s==1)
	{
		puts("YES");
	}	
	else puts("NO");
	return 0;
}