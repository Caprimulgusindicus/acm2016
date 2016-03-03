#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int tt[222222];
int cmp1( const int &a, const int &b ){
if( a > b )
    return 1;
else
    return 0;
}

int cmp2( const int &a, const int &b ){
if( a < b )
    return 1;
else
    return 0;
}

int main()
{
    int n,m;
    int a[222222];
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int t,r;

    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&t,&tt[i]);

    }

    if(t==1)
            sort(a+1,a+1+r,cmp2);
        else
            sort(a+1,a+1+r,cmp1);

    for(int i=1;i<=n;i++)
        if(i!=n) printf("%d ",a[i]);
            else printf("%d",a[i]);
    return 0;
}
