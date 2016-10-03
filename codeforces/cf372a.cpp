#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
ll a[111111];
int main()
{
	ll n,c;
	scanf("%I64d%I64d",&n,&c);
	if(n!=1){
		for(int i=1;i<=n;i++){
			scanf("%I64d",&a[i]);
		}
		ll cnt=0;
		for(int i=2;i<=n;i++){
			if(a[i]-a[i-1]<=c) cnt++;
			else cnt=0;
		}
		cout<<cnt+1<<endl;
	}
	else cout<<1<<endl;
	return 0;
}