#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
long long a[1111111];
long long ab(long long x)
{
	if(x>0) return x;
	else return -x;
}

int main()
{
	long long n,aa;
	while(~scanf("%I64d%I64d",&n,&aa)){
	memset(a,0,sizeof(a));
	long long sum=0;
	long long pre1=0;
	long long pre2=0;
	for(long long i=1;i<=n;i++)
		{
			scanf("%I64d",&a[i]);
			
		}
	sort(a+1,a+1+n);

	if(n==1)
		printf("0\n");
	else if(n==2)
		if(aa==a[1]||aa==a[2]) puts("0");
		else printf("%I64d",min(ab(aa-a[1]),ab(aa-a[2])));
	
	else
	{
		
		
		long long ans;
		for(long long i=1;i<=n;i++)
			if(i>1) sum+=a[i]-a[i-1];//从一端走到另一端


		long long sum2=sum-(a[2]-a[1]);//2 to n
		long long sum1=sum-(a[n]-a[n-1]);//1 to n-1

		long long n1=ab(aa-a[n-1]);//aa to n-1
		long long n2=ab(aa-a[n]);//  aa to n
		long long n3=ab(aa-a[2]);//  aa to 2
		long long n4=ab(aa-a[1]);//  aa to 1

		if(aa<a[1]) ans=sum1+ab(aa-a[1]);
		else if(aa>a[n]) ans=sum2+ab(aa-a[n]);
		else 
		{
			ans=sum1+n1;
			ans=min(ans,sum2+n2);
			ans=min(ans,sum2+n3);
			ans=min(ans,sum1+n4);
		}
		
		printf("%I64d\n",ans);
	}
}
	return 0;
}