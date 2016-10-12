#include <cstdio>
#include <iostream>
using namespace std;

long long f(int i)
{
	if(i==0) return 0;
	if(i==1) return 1;
	else return f(i-1)+f(i-2);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long n;
		scanf("%lld",&n);
		cout<<f(f(n))<<endl;
	}
	return 0;
}