#include <stdio.h>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;
long long a[111111];
long long b[111111];

int main()
{
	int n;
	long long sum=0;
	map <long long,long long> m;

	b[1]=2;

	for(int i=2;i<=30;i++)
		b[i]=b[i-1]*2;

	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		scanf("%I64d",&a[i]);
		for(int j=1;j<=30;j++)
		{
			if(b[j]-a[i]<0||m.count(b[j]-a[i])==0) continue;
			sum+=m[b[j]-a[i]];
			//cout<<sum<<endl;
		}
		m[a[i]]++;
	}
	printf("%I64d\n",sum);
	return 0;
}