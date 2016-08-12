#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
double v[111111];
int x[111111];
int d[111111];
int cmp(double a,double b)
{
	return a<b;
}
int main()
{
	int t;
	int n;
	double c;
	scanf("%d",&t);
	while(t--)
	{
		memset(v,0,sizeof(v));
		memset(x,0,sizeof(x));
		memset(d,0,sizeof(d));

		scanf("%d %lf",&n,&c);
		for(int i=1;i<=n;i++)
			scanf("%lf%d%d",&v[i],&x[i],&d[i]);
		
		sort(v+1,v+1+n,cmp);
		

		int k;
		scanf("%d",&k);
		while(k--)
		{
			int t;int k;
			scanf("%d%d",&t,&k);
			double a=c/v[k];
			printf("%.3lf\n",sqrt(2*(c*t+0.5*v[k]*v[k])));
		}
	}
	return 0;
}