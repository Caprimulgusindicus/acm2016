#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	for(int ca=1;ca<=T;ca++)
	{
		double a,b;
		scanf("%lf%lf",&a,&b);
		double ans=0;
		if(b*2==a) ans=0.01;
		else if(b==0.01||b==0.1||b==1||b==10) ans=0.02;
		else ans=0.01;
		printf("Case #%d: %.2f\n",ca,ans);
	}
	return 0;
}