#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	long double ans;
	int n;
	double r;
	while(~scanf("%lf%d",&r,&n))
	{
		double(ans)=pow(r,n);
		printf("%llf\n",ans);
	}
	cout<<n<<endl;
	return 0;
}