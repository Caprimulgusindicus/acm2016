#include <iostream>
#include <stdio.h>
using namespace std;
long long a[1111111];
long long vis[1111111];
long long counum(long long iNum)
{
long long iCount=0;
while (iNum)
{
iCount+=iNum%2;
iNum/=2;
}
return iCount;
}

int main()
{
	int n;
	int t;
	scanf("%d",&t);
	for(int cc=1;cc<=t;cc++)
	{
		scanf("%d",&n);
		long long sum=0;
		long long cnt=0;
		for(int i=1;i<=n;i++)
		{
				scanf("%lld",&a[i]);
				//a[i]%=3;
				sum^=a[i];
				//if(a[i]>3) cnt++;
				//cout<<counum(a[i])<<endl;
				//if(a[i]>3&&a[i]%2==0) cnt++;
				cnt+=(counum(a[i])/3);
				//if(a[i]==4) cnt++;
		}
		if(n==1) puts("First player wins.");
		else
		{
				
			//cout<<sum<<endl;
			if(sum>0) puts("First player wins.");
			//else if(sum==0&&cnt%2!=0) puts("First player wins.");
			//else if(sum==0&&cnt%2==0) 
			else puts("Second player wins.");
			//else if(sum>0&&cnt%2!=0)  puts("First player wins.");
			}
		
	}
	return 0;
}