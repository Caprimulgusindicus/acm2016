#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int k=n/2;
	if(n&1)
	{
		printf("%d\n",k);
		for(int i=1;i<k;i++) printf("2 ");
		printf("3\n");
		
	}
	else
	{

		printf("%d\n",k);
		for(int i=1;i<k;i++) printf("2 ");
		printf("2\n");


	}
	return 0;
}