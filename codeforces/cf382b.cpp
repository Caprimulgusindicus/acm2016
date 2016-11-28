#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long double ll;
ll a[111111];
int main()
{
	int n,n1,n2;
	while(~scanf("%d%d%d",&n,&n1,&n2))
	{
		if(n1>n2) swap(n1,n2);//n2 is bigger
		for(int i=1;i<=n;i++)
			scanf("%Lf",&a[i]);
		sort(a+1,a+1+n);
		ll sum1=0,sum2=0;
		int i,cnt;
		for(i=n,cnt=n1;cnt>0;i--,cnt--)
		{
		//	cout<<a[i]<<" ";
			sum1+=a[i];
		}
		//cout<<endl;
		for(cnt=n2;cnt>0;i--,cnt--)
		{
		//	cout<<a[i]<<" ";
			sum2+=a[i];
		}
		printf("%Lf\n",sum1/ll(n1)+sum2/ll(n2));
	}
	return 0;
}