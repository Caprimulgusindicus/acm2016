#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int n;
	int m; int k;
	freopen("subtle_sabotage.txt","r",stdin);
	freopen("outa.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int ca=1;ca<=T;ca++)
	{
		scanf("%d%d%d",&n,&m,&k);
		if(n>m) swap(n,m);
		int ans=-1;
		if(m>=2*k+3&&n>=k+1)
		{
			ans=(n+k-1)/k;
			if(n>=2*k+1)
			{
				if(k==1) ans=min(5,ans);
				else ans=min(4,ans);
			}
		}
		cout<<"Case #"<<ca<<": "<<ans<<endl;
	}
	return 0;
}