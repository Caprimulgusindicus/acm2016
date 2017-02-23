#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a[333][333],f[333][333],b[333][333];

int main()
{
    freopen("input.txt", "r", stdin);
	freopen("outputa.txt", "w", stdout);
    int T;
    scanf("%d",&T);
    for (int ca=1;ca<=T;ca++)
    {
        int n, m;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
                scanf("%I64d",&a[i][j]);
        }
        for(int i=1;i<=n;i++)
        {
            sort(a[i]+1,a[i]+(m+1));
            b[i][0]=0;
            for (int j=1;j<=m;j++)
                b[i][j]=b[i][j-1]+a[i][j];
            for (int j=1; j<=m;j++)
                b[i][j]+=j*j;

        }
        memset(f,0x7f,sizeof(f));
        f[0][0]=0;
        for(int i=1;i<=n;i++)
        {
            for (int j=i-1;j<=n;j++)
            {
                if (f[i-1][j]==0x7f7f7f7f7f7f7f7fll) continue;
                for (int k=0;k<=min(n-j,m); k++)
                    f[i][k+j]=min(f[i][k+j],f[i-1][j]+b[i][k]);
            }
        }
        printf("Case #%d: %I64d\n",ca,f[n][n]);
    }
    return 0;
}
