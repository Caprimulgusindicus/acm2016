#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	long long n;
	cin>>n;	
	long long a=1234567,b=123456,c=1234;
	int flag=0;
	for(int i=0;i*a<=n;i++)
		for(int j=0;;j++)
		{
			if(a*i+j*b>n) break;
			if((n-a*i-b*j)%c==0)
				{flag=1;}
		}
	if(!flag) puts("NO");
	else puts("YES");
	return 0;
}