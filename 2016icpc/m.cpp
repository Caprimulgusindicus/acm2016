#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
	long long n;
	while(~scanf("%lld",&n))
	{
		int flag=n%18;
		if(flag>9&&flag<18) puts("Stan wins.");
		else puts("Ollie wins.");
	}
	return 0;
}