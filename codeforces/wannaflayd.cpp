#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
const ll MOD=1e9+7;
ll a[25],f[25];
int n;
ll s;
ll cal(ll num,ll x)
{
	ll ans=1;
	while(x)
	{
		if(x&1) {ans*=num;ans%=MOD;}
		num*=num;
		num%=MOD;
		x>>=1;
	}
	return ans;
}


ll zh(ll n,ll m)
{
	if(n<m) return 0ll;
    if(n==m) return 1ll;
	ll ans=1;
    
	    
	    for(ll i=n;i>=(n-m+1);i--)
	    {
	    	ans*=f[n+1-i];
	    	ans%=MOD;
	    	ans*=i%MOD;
	    	ans%=MOD;
	    	
	    }
	    return ans;
    
}


int main()
{
	
	for(int i=1;i<=20;i++)
		f[i]=cal(i,MOD-2);
	while(~scanf("%d%lld",&n,&s))
	{
		for(int i=0;i<n;i++)
			scanf("%lld",&a[i]);

        int lala=1<<n;
        ll ans=zh(s+n-1,n-1);
        for(int i=1;i<lala;i++)
        {   
            int cnt=0;
            ll x=0;
            for(int j=0;j<n;j++)
                if((1<<j)&i) 
                {
                    x+=a[j]+1ll;
                    cnt++;
                }
            if(cnt&1)
            {
                ans-=zh(s+n-1-x,n-1);
                ans=(ans%MOD+MOD)%MOD;
            }
            else 
                ans+=zh(s+n-1-x,n-1),ans%=MOD;
            
        }
        //cout<<ans%MOD<<endl;
        printf ("%lld\n",ans);
	}
	return 0;
}


