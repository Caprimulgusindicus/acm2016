#include <stdio.h>
#include <iostream>
using namespace std;
long long a[111111];
int main()
{
	int n;
	int t=0;
	a[0]=0;
	int ans=-1;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]>a[i-1]) t++; 
		else t=1;
		ans=max(t,ans);
	}	
	cout<<ans<<endl;
	return 0;
}