#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

#define PII pair<int,int>
#define MP make_pair
typedef long long LL;
int ans[222222];
int x[222222][2],y[222222][2],n;
int z[222222];
pair<PII,PII>la[222222<<1];


inline int lowbit(int x) {return x & (-x);}

struct BIT 
{
    LL tree[222222+10];
    int n;
    void init(int m) 
    {
        n = m + 5;
        for (int i = 0; i <= n; i++)
            tree[i] = 0;
    }
    
    LL query(int w) 
    {
        LL ret = 0;
        for (w += 3; w > 0; w -= lowbit(w))
            ret += tree[w];
        return ret;
    }
    void update(int w, LL d) 
    {
        for (w += 3; w < n; w += lowbit(w))
            tree[w] += d;
    }
}bit;



int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
            int lala1=0,tmp=0;
            int n;
            long long ans=0;
            scanf("%d",&n);
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<2;j++)
                    scanf("%d%d",&x[i][j],&y[i][j]);
                if(x[i][0]>x[i][1])
                    swap(x[i][0],x[i][1]);
                if(y[i][0]>y[i][1])
                    swap(y[i][0],y[i][1]);
                for(int j=0;j<2;j++)
                    z[tmp++]=x[i][j];
            }

            sort(z,z+tmp);
            tmp=unique(z,z+tmp)-z;

            for(int i=0;i<n;i++)
            {
                if(x[i][0]==x[i][1])
                {
                    x[i][0]=lower_bound(z,z+tmp,x[i][0])-z;
                    la[lala1++]=(MP(MP(y[i][0]-1,1),MP(-1,x[i][0])));
                    la[lala1++]=(MP(MP(y[i][1],1),MP(1,x[i][0])));
                }
                if(y[i][0]==y[i][1])
                {
                    for(int j=0;j<2;j++)
                        x[i][j]=lower_bound(z,z+tmp,x[i][j])-z;
                    la[lala1++]=(MP(MP(y[i][0],0),MP(x[i][0],x[i][1])));
                }
            }
            sort(la,la+lala1);
            bit.init(tmp+2);

            for(int t=0;t<lala1;t++)
            {
                if(la[t].first.second)
                {
                    ans+=la[t].second.first*bit.query(la[t].second.second);
                }
                else 
                {
                    bit.update(la[t].second.first,1);
                    bit.update(la[t].second.second+1,-1);
                }
            }
            printf("%lld\n",ans);      
    }
    return 0;
}