#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 1e2 + 10, INF = 0x3f3f3f3f, MOD = 1e9 + 7;

typedef long long LL;

int n, q;
LL d[N][N];
int e[N], s[N];

double f[N][N];

int main() 
{
    freopen("cccc.in","r",stdin);
    freopen("cout.txt","w",stdout);
    ios_base::sync_with_stdio(0);

    int t; scanf("%d", &t);
    while(t--) {
        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; ++i) scanf("%d%d", e + i, s + i);

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                scanf("%lld", d[i] + j);
                if(d[i][j] == -1) d[i][j] = ~0ull >> 2;
            }
        }

        for(int k = 1; k <= n; ++k) {
            for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= n; ++j) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }

        for(int i = 1; i <= n; ++i) {
            for(int j = 1; j <= n; ++j) {
                f[i][j] = d[i][j] > e[i] ? 1e18 : 1.*d[i][j] / s[i];
            }
        }
        for(int k = 1; k <= n; ++k) {
            for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= n; ++j) {
                    f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                }
            }
        }

        static int kase = 0;
        printf("Case #%d:", ++kase);
        while(q--) {
            int src, des; scanf("%d%d", &src, &des);
            printf(" %.12f", f[src][des]);
        }
        puts("");
    }
    return 0;
}
