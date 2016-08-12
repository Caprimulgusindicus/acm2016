#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
char nam[11];
//int before[111];
//int after[111];

int main()
{
	int n;
	int flag=0;
	scanf("%d",&n);
	getchar();
	for(int i=1;i<=n;i++)
	{
		int before,after;
		scanf("%s",nam);
		scanf("%d %d",&before,&after);
		if(before>=2400&&after>before)
			flag=1;
	}
	if(flag) puts("YES");
	else puts("NO");
	return 0;
}