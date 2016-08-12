#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int pf(int x)
{
	return x*x;
}
int main()
{
	int a,b;
	double ans=23333333;
	scanf("%d%d",&a,&b);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		double dist=sqrt(pf(x-a)+pf(y-b));
		double t=dist/double(v);
		ans=min(t,ans);
	}
	printf("%.8lf\n",ans);
	return 0;
}