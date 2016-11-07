#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
#define PI acos(-1.0)
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		double l;
		scanf("%lf",&l);
		double lala=l;
		l=1.0;
		double a=l; //c
		double b=l*sqrt(2)*0.5;//d
		double c=0.5*l;//b
		double s=0.5*(a+b+c);
		double s1=sqrt(s*(s-a)*(s-b)*(s-c));
		double beta=acos((a*a+b*b-c*c)/(2.0*b*a));
		double alpha=acos((b*b+c*c-a*a)/(2.0*b*c));

		double s21=beta*l*l*0.5;
		double s23=(PI-alpha)*c*c*0.5;
		double ans=4.0*(s23-(s21-s1));
		cout<<s1<<endl;
		cout<<s21<<endl;
		cout<<s23<<endl;
		cout<<alpha<<endl<<beta<<endl;
		//cout<<s21-s1<<endl;
		//cout<<s23<<endl;
		//cout<<s23-(s21-s1)<<endl;
		//cout<<a<<" "<<b<<" "<<" "<<c<<endl;
		printf("%.2lf\n",lala*lala*ans);
	}
	return 0;
}