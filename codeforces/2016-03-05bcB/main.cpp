#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define mod 10000000000+7
using namespace std;
int a[11111];
int dis[11111][11111];
struct point
{
    int a;
    int b;
}p[4];

int main()
{
    int n;int m;
    int tt;


    scanf("%d",&tt);
    while(tt--)
    {
        memset(a,0,sizeof(a));
        scanf("%d%d",&n,&m);

        long long t=0;
        long long ans=0;
        for(int i=1;i<=3;i++)
        {
            scanf("%d%d",&p[i].a,&p[i].b);
            if(p[i].a>p[i].b) swap(p[i].a,p[i].b);

        }

        long long aaa=0;
        for(int i=1;i<=m;i++)
        {
            int flag=0;
            int a;int b;
            ans=0;
            scanf("%d%d",&a,&b);
            if(b<a) swap(a,b);
            for(int j=1;j<=3;j++)
            {
                t=0;
                if(a<=p[j].a&&b>=p[j].b&&p[j].a!=p[j].b)

                {
                    t=1-(p[j].b-p[j].a);
                    ans+=t;
                    ans+=b-a;
              //      cout<<ans<<" !!ans"<<endl;
                }
                else flag++;
            }
            if(flag==3) ans=b-a;
           // cout<<ans<<" ???ans"<<endl;
           aaa+=ans*i;
           // cout<<aaa<<"   "<<i<<endl;
            //ans+=ans*i;
        }
        //aaa=aaa%(mod);
         if(n==1) {printf("%d\n",0);}
       else printf("%I64d\n",aaa%(mod));
    }

    return 0;
}
