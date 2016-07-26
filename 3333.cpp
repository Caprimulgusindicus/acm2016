#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int n;
double cou[1111];
double cou2[1111];
int h[1111];
int c[1111];
int main()
{

	//cout<<7*6*5*4*3*2<<endl;
	while(~scanf("%d",&n))
	{
		
		double ans=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&c[i]);
			if(i==1||i==n) ans+=double(c[i])/double(2);
			else ans+=double(c[i])/double(3);
		}
		//cout<<c[1];
		if(n==1) printf("%.8f\n",double(c[1]));
		else if(n==2) printf("%.8f\n",double(c[2]+c[1])/double(2));
		else 
		printf("%.8lf\n",ans);
	}
	return 0;
}