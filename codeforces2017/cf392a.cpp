#include <cstdio>
#include <iostream>
#include <bitset>
using namespace std;
typedef long long ll;
int n;
bitset <555555> ma[66];
void gauss()
{
    int j=0;
    for(int i=0;i<n;i++)
    {
        int now=j;
        for(int k=j;k<60;k++)
            if(ma[k][i]) now=k;

        if(!ma[now][i]) continue;
        swap(ma[j],ma[now]);
        for(int k=j+1;k<60;k++)
            if(ma[k][i]) ma[k]^= ma[j];
        j++;
        if(j>=60) break;
    }
}

int main()
{
    scanf("%d",&n);
    ll s=0;
    for(int i=0;i<n;i++)
    {
        ll a,b;
        scanf("%lld%lld",&a,&b);
        s^=a;
        b^=a;
        for(int j=0;j<60;j++)
            ma[j][i]=(b>>j&1);
    }
    for(int j=0;j<60;j++)
        ma[j][n]=(s>>j&1);
    gauss();

    int t=60;
    for(int j=0;j<60;j++)
    {
        int flag=0;
        for(int i=0;i<n;i++)
            flag|=ma[j][i];
        if(!flag)
        {
            if(ma[j][n])
                {printf("1/1\n");return 0;}
            else t--;
        }
    }
    ll fz=(1ll<<t)-1;
    ll fm=1ll<<t;
    printf("%lld/%lld\n",fz,fm);
    return 0;
}