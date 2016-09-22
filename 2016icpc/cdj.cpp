#include <iostream>
#include <algorithm>
#include <cstdio>
#define a1 (m-t1+p)%p
#define a2 (t2-m+p)%p
#define lala (cnt2-cnt1+1)*(cnt2-cnt1)/2*p
typedef long long ll;
using namespace std;
ll gcd(ll x,ll y)
{
    ll temp;
    do{
        temp=x%y;
        x=y;
        y=temp;
    }
    while(temp!=0);
    return x;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        ll a,b,c,d,m,p;
        scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&p,&m);
        ll ans=0;
        if(b+c<=a+d)
        {
            ll t1=(b+c)%p;
            ll t2=(a+d)%p;
            ll cnt1=(b+c+a1-m)/p;
            ll cnt2=(a+d-a2-m)/p;
            ans+=(cnt2-cnt1+1)*(b-a+1);
            t1=(a+d+1)%p;
            t2=(b+d)%p;
            cnt1=(a+d+1+a1-m)/p;
            cnt2=(b+d-a2-m)/p;
            ans+=(cnt2-cnt1+1)*(a2+1)+lala;
            t1=(a+c)%p;
            t2=(b+c-1)%p;
            cnt1=(a+c+a1-m)/p;
            cnt2=(b+c-1-a2-m)/p;
            ans+=(cnt2-cnt1+1)*(a1+1)+lala;
        }
        else
        {
            ll t1=(a+d)%p;
            ll t2=(b+c)%p;
            ll cnt1=(a+d+a1-m)/p;
            ll cnt2=(b+c-a2-m)/p;
            ans+=(cnt2-cnt1+1)*(d-c+1);

            t1=(b+c+1)%p;
            t2=(b+d)%p;
            cnt1=(b+c+1+a1-m)/p;
            cnt2=(b+d-m-a2)/p;
            ans+=(cnt2-cnt1+1)*(a2+1)+lala;

            t1=(a+c)%p;
            t2=(a+d-1)%p;
            cnt1=(a+c+a1-m)/p;
            cnt2=(a+d-1-a2-m)/p;
            ans+=(cnt2-cnt1+1)*(a1+1)+lala;

        }

        ll sum=(b-a+1)*(d-c+1);
        ll gc=gcd(ans,sum);
        ans/=gc;
        sum/=gc;
        printf("Case #%d: %lld/%lld\n",ca,ans,sum);
    }
    return 0;
}