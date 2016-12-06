#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
int a[222222];
int main()
{
	int T,n,m,k;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		ll ans=0;
		ll t[222222];
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]>=m)
			{
				cnt++;
				t[cnt]=i;
				//cout<<t[cnt]<<" ";
				if(cnt==k) ans+=t[1]*(n-i+1);
				else if(cnt>k) ans+=(t[cnt-k+1]-t[cnt-k])*(n-i+1);
				//cout<<t[cnt-k+1]<<" "<<t[cnt-k]<<endl;
			}
		}

		cout<<ans<<endl;
	}

	return 0;
}