#include<set>
#include<map>
#include<stack>
#include<queue>
#include<ctime>
#include<cmath>
#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#define X first
#define Y second
#define sc scanf
#define pr printf
#define MP make_pair
#define PB push_back
#define lson l,m,i<<1
#define rson m+1,r,i<<1|1
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;

typedef double db;
typedef long long ll;

const int N=120;

ll a[N][N],b[N][N],c[N][N];

int main()
{
    int n,m,k;
    while(~sc("%d%d%d",&n,&m,&k))
    {
        if(n==0 && m==0 && k==0) break;

        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                a[i][j]=(i==j);

        while(k--)
        {
            int x,y;
            char s[5];
            sc("%s",s);
            if(s[0]=='g')
            {
                sc("%d",&x);
                a[x-1][n]++;
            }
            if(s[0]=='s')
            {
                sc("%d%d",&x,&y);
                for(int i=0;i<=n;i++)
                    swap(a[x-1][i],a[y-1][i]);
            }
            if(s[0]=='e')
            {
                sc("%d",&x);
                for(int i=0;i<=n;i++)
                    a[x-1][i]=0;
            }
        }

        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                c[i][j]=(i==j);




        while(m)
        {
            if(m&1)
            {
                mem(b,0);
                for(int i=0;i<=n;i++)
                    for(int j=0;j<=n;j++)
                        if(c[i][j])
                            for(int k=0;k<=n;k++)
                                b[i][k]+=c[i][j]*a[j][k];

                for(int i=0;i<=n;i++)
                    for(int j=0;j<=n;j++)
                        c[i][j]=b[i][j];
            }

            mem(b,0);

            for(int i=0;i<=n;i++)
                for(int j=0;j<=n;j++)
                    if(a[i][j])
                        for(int k=0;k<=n;k++)
                            b[i][k]+=a[i][j]*a[j][k];

            for(int i=0;i<=n;i++)
                for(int j=0;j<=n;j++)
                    a[i][j]=b[i][j];

            m/=2;
        }


        mem(b,0);
        b[n][0]=1;

        mem(a,0);
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                if(c[i][j])
                    for(int k=0;k<=n;k++)
                        a[i][k]+=c[i][j]*b[j][k];

        pr("%lld",a[0][0]);

        for(int i=1;i<n;i++)
            pr(" %lld",a[i][0]);
        puts("");
    }

    return 0;
}