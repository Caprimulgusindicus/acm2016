#include <cstdio>
#include <algorithm>
#include <utility>
using namespace std;
long long x[55], y[55];

pair<pair<long long, long long>, long long> ans[2222];
long long anc=0;

int main()
{
    freopen("inputb.txt", "r", stdin);
	freopen("outputb.txt", "w", stdout);
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    {
        long long n,r;
        scanf("%I64d%I64d",&n,&r);
        for(long long i=1;i<=n;i++)
            scanf("%I64d%I64d",x+i,y+i);
        anc=0;
        for(long long i=1;i<=n;i++)
        {
            for(long long j=1;j<=n;j++)
            {
                if((abs(x[i]-x[j])>r)||(abs(y[i]-y[j])>r))  continue;
                long long sx, sy;
                if(x[i]<=x[j])
                    sx=x[i];
                else sx=x[i]-r;

                if (y[j]<=y[i])
                    sy=y[j];
                else sy=y[j]-r;

                ans[anc].first.first=sx,ans[anc].first.second=sy,ans[anc].second=0;
                for(long long k=1;k<=n;k++)
                {
                    if((x[k]-sx>=0)&&(x[k]-sx<=r)&&(y[k]-sy>= 0)&&(y[k]-sy<=r))
                        ans[anc].second++;
                }
                anc++;
            }
        }

        long long ret=2;
        for(long long i=0;i<anc;i++)
        {
            for(long long j=i+1;j<anc;j++)
            {
                if((abs(ans[i].first.first-ans[j].first.first)>r)||(abs(ans[i].first.second - ans[j].first.second)>r))
                {
                    ret=max(ret, ans[i].second + ans[j].second);
                }
            }
        }
        printf("Case #%d: %I64d\n",ca,ret);
    }
    return 0;
}
