#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int a[222];

int ab(int n)
{
    if(n<0) return -n;
    else return n;
}
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int maxx=-1;int minn=11111;
        int maxi=0;int mini=0;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]>maxx) {maxx=a[i];maxi=i;}
            if(a[i]<minn) {minn=a[i];mini=i;}
        }
        cout<<maxi<<" "<<mini<<endl;
        int ans1;int ans2;
        ans1=max(ab(1-maxi),ab(1-mini));
        ans2=max(ab(n-maxi),ab(n-mini));
        cout<<max(ans1,ans2)<<endl;
    }
    return 0;
}
