#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	 int t;
	 while(~scanf("%d",&t))
	 {
	 	int n;
	 	for(int i=1;i<=n;i++)
	 	{
	 		scanf("%d",&n);
	 		if(n%2!=0) puts("Balanced");
	 		else puts("Bad");
	 	}	
	 }
	return 0;
}