#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
	int a,b,c,d,e,f;
	scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
	int aa=a*a;int cc=c*c;int ee=e*e;
	int total=(a+b+c)*(c+d+e);
	cout<<total-aa-cc-ee<<endl;

	return 0;
}