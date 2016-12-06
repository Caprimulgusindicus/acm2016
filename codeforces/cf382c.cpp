#include <cstdio>
#include <cstring>
#include <iostream>
#include<cmath>
using namespace std;
typedef long long ll;
ll cnt=0;

bool is_prime(ll a){
    if (a == 1) return false;
    for (ll i = 2; i <= ll(sqrt(a)); i++){
        if (a%i == 0) return false;
    }
    return true;
}
void dfs(ll n)
{
	//cout<<n<<" ";
	//if(is_prime(i)) return;
	//if(n<0) return;
	if(n==1) {cnt++;return;}
	if(n==0) {return;}
	for(ll i=n;i>0;i--)
		if(is_prime(i)) {//cout<<i<<" ";
			ll t=n-i;
			if(t==1) continue;
			n-=i,cnt++;break;}
	dfs(n);
}
int main()
{
	ll n;
	while(~scanf("%lld",&n))
	{
		cnt=0;
		if(n%2==0&&n!=2) puts("2");
		else
		{
		if(!is_prime(n)) dfs(n);
		else cnt=1;
		if(cnt==4) cnt=3;
		cout<<cnt<<endl;
	}
	}
	return 0;
}