#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int main()
{
	int a,vs,vc;
	while(~scanf("%d%d%d",&a,&vc,&vs))
	{
		if(a)
		{
			if(vc<=vs) puts("Infinity");
			else
			{
				double t=double(vc*a)/double(vc*vc-vs*vs);
				printf("%.8lf\n",t);
			}
		}
		else printf("%.8lf\n",0);
		
	}
		
	return 0;
}