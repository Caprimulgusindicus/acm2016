#include <iostream>
#include <stdio.h>
using namespace std;
long long x;
long long res[111111];
int main()
{
    int n;
    long long h,k;
    x=0;
    long long ans=0;
    scanf("%d%I64d%I64d",&n,&h,&k);
    long long res=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&x);
        if(res+x<=h) res+=x;
        else res=x,ans++;
        ans+=res/k;
        res%=k;
        //cout<<res<<endl;
    }

  //  ans+=res/k,res%=k;
    //ans++;
    if(res>0) ans++;
    cout<<ans<<endl;
    return 0;
}
