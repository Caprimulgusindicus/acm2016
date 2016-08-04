#include <iostream>
#include<stdio.h>
using namespace std;
int main()
{
	char a,b,c,t;
	while(~scanf("c%c%c%",&a,&b,&c)!=EOF)
	{
	    cout<<a<<endl;
	if(a>b)
	{t=a;a=b;b=t;}
	if(a>c)
	{t=a;a=c;c=t;}
	if(b>c)
	{t=b;b=c;c=t;}
	printf("%c %c %c",a,b,c);
	}
		return 0;
}


