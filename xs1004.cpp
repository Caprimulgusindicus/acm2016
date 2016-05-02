#include <iostream>
#include <stdio.h>
#include <cstdio>
using namespace std;
int main()
{
    int n,a,b,c;
    freopen("10042.txt","w",stdout);
    while(~scanf("%d%d%d%d",&n,&a,&b,&c))
    {
        int sum=0;
        sum=n+a*400+b*100+c*100;
        int ans=0;
        ans=sum/800;
        sum-=ans*800;
        //cout<<sum<<endl;
        ans+=sum/400;
        cout<<ans<<endl;
    }
    return 0;
}
