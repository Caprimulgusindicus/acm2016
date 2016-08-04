#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int a[111];
int main()
{
	for(int i=1;i<=5;i++)
		a[i]=i;
	do
	{
		for(int i=1;i<=5;i++)
			printf("%d",a[i]);
		printf("\n");
	}
	while(next_permutation(a+1,a+6));
	return 0;
}