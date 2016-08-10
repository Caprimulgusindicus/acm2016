#include <cstdio>
#include <iostream>
using namespace std;
long long a[111111];
int main()
{
	int n;
	scanf("%d",&n);
	long long sum=0;
	int flag=0;//doushi 1
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		a[i]-=1;
		sum+=a[i];
		if(sum&1) puts("1");
		else puts("2");
		//cout<<sum<<endl;
		//if(!flag) puts("2");
		//else if(sum==0) puts("2");
		//else puts("1");
	}
	return 0;
}