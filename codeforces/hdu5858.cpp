#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
#define PI acos(-1.0)
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		double l;
		scanf("%lf",&l);
		double ll=l;
		l=1.0;

		double b=0.5*l;
		double c=l*0.5*sqrt(2);

		double cosa=acos((l*l+c*c-0.5*l*0.5*l)/(2.0*l*c));
		double cosb=acos((0.5*l*0.5*l+c*c-l*l)/(2.0*0.5*l*c));
		double p=0.5*(l+0.5*l+c);

		double s1=sqrt(p*(p-l)*(p-0.5*l)*(p-c));
		double s2=l*l*cosa*0.5;
		double s3=(PI-cosb)*0.5*l*0.5*l*0.5;
		double s=s2-s1;
		s=s3-s;
		s*=4.0;
		s=s*ll*ll;
		printf("%.2lf\n",s);
	}
	return 0;
}