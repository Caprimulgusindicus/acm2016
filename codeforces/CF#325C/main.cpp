#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
//C
long long  v[4005];
long long  d[4005];
long long  p[4005];
long long  aans[4005];
long long  flag[4005];
int   main()
{
    int  n;

    while(~scanf("%d",&n))
    {
        memset(flag,0,sizeof(flag));
        for(int  i=1;i<=n;i++)
            scanf("%I64d%I64d%I64d",&v[i],&d[i],&p[i]);
        //for(long long  i=1;i<=n;i++)
        //    cout<<v[i]<<" "<<d[i]<<" "<<p[i]<<endl;
        int  ans=0;

        for(int  i=1;i<=n;i++)
        {
            if(p[i]<0) continue;

            aans[ans++]=i;
            long long  sum=0;
            long long minu=v[i];
            for(int   j=i+1;j<=n;j++)//
            {
                flag[j]=0;
                if(p[j]>=0)
                {
                    flag[j]=1;
                    //cout<<minu<<" ";
                    if(minu>0) p[j]-=minu;
                    //cout<<p[j]<<" !>"<<endl;
                    minu--;
                }

            }

            for(int  j=i+1;j<=n;j++)
            {
                if(p[j]>=0)
                    p[j]-=sum;
                if(p[j]<0&&flag[j])
                    sum+=d[j];

            }

        }
        printf("%d\n",ans);
        for(int i=1;i<=ans;i++)
            if(i==1) printf("%I64d",aans[i-1]);
                else printf(" %I64d",aans[i-1]);
        cout<<endl;
    }
    return 0;
}
