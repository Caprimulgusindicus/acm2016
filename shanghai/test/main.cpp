#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int n,A,B,L;
int start,en;
int road[111111];


int main()
{
    int ca;
    scanf("%d",&ca);
    for(int k=1;k<=ca;k++)
    {
        memset(road,0,sizeof(road));
        int ans=0;
        int minn=111111;
        scanf("%d%d%d%d",&n,&A,&B,&L);

        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&start,&en);
            for(int j=en;j>start;j--)
                road[j]=1;
        }

        for(int i=1;i<=L;i++)
        {
            if(road[i]) ans-=A;
            else ans+=B;
            minn=min(ans,minn);
        }

        if(minn>=0) ans=0;
        else ans=-minn;
        printf("Case #%d: %d\n",k,ans);
    }
    return 0;
}
