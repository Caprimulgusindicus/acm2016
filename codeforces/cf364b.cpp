#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int vish[111111];
int visl[111111];
//int vis[111111][111111];
long long an[111111];
int main()
{
    long long n,m;
    long long counth,countl;
    while(~scanf("%I64d%I64d",&n,&m))
    {
        memset(vish,0,sizeof(vish));
        memset(visl,0,sizeof(visl));
        long long ans=n*n;
        counth=0;countl=0;
        for(int i=1;i<=m;i++)
            {
                long long a,b;
                scanf("%I64d%I64d",&a,&b);
                //cout<<a<<" "<<b<<endl;

                if(i==1) ans-=(2*n-1),vish[a]=1,visl[b]=1,countl++,counth++;
                else
                {
                    if((vish[a]!=0)&&(visl[b]==0)) countl++,ans-=(n-counth),vish[a]=1,visl[b]=1;
                    else if((vish[a]==0)&&(visl[b]!=0)) counth++,ans=ans-(n-countl),vish[a]=1,visl[b]=1;
                    else if(vish[a]!=0&&visl[b]!=0) ans=ans,vish[a]=1,visl[b]=1;
                    else ans=ans-(n-countl)-(n-counth)+1,vish[a]=1,visl[b]=1,countl++,counth++;
                }
                if(ans>=0) an[i]=ans;
                else an[i]=0;
            }

            for(int i=1;i<=m;i++)
                if(i!=m)
                    printf("%I64d ",an[i]);
                else printf("%I64d\n",an[i]);
    }
    return 0;
}
