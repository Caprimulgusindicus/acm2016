#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	printf("I hate ");
	if(n==1)
		printf("it\n");
	else
	{
		for(int i=2;i<=n;i++)
		{
			if(i&1) printf("that I hate ");
			else printf("that I love ");
			if(i==n) printf("it\n");
		}	


	}
	return 0;
}