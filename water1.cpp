#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int cnt;
	while(~scanf("%d",&cnt))
	{
		int k=1;
		int init=1;
		for(int x=1;x<=100;x++)
			for(int k=2;k<=100;k++)
			{
				cout<<x<<" "<<x*k<<" "<<x*k*k<<" "<<x*k*k*k<<endl;
			}
	} 
	return 0;
}