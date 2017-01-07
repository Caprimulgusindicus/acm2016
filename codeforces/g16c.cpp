#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
struct lala
{
    int a;
    int div;
}la[222222];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&la[i].a,&la[i].div);
    }
    if(n==1) puts("Infinity");
    else
    {
        int l=1;int r=3000;

        while(l<=r)
        {
            int mid=(l+r)/2;
            int i;
            int tmp=mid;
            for(i=1;i<=n;i++)
                if(la[i].div==1&&tmp<1900) {r=mid-1;break;}
                else if(la[i].div==2&&tmp>=1900) {l=mid;break;}
                else  tmp+=la[i].a;
            cout<<l<<" "<<r<<" "<<mid<<endl;
        }
       // cout<<l<<endl;
    }

    return 0;
}
