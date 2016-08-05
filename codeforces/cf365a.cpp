#include <iostream>
#include <stdio.h>
using namespace std;
int a[111];
int b[111];
int main()
{
	int n;
	int cnta=0;
	int cntb=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a>b) cnta++;
		else if(a<b) cntb++;

	}
	if(cnta==cntb) puts("Friendship is magic!^^");
	else if(cnta>cntb) puts("Mishka");
	else puts("Chris");
	return 0;
}