#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int mp[111][111];
int s[5555], d[5555];
int dp[5555][2];

int main()
{
    freopen("manic_moving.txt", "r", stdin);
	freopen("outputc.txt", "w", stdout);
    int tt;
    scanf("%d", &tt);
    for (int ti = 1; ti <= tt; ti++)
    {
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        memset(mp, 0x3f, sizeof(mp));
        memset(dp, -1, sizeof(dp));
        for (int i = 1; i <= m; i++)
        {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            mp[x][y] = z;
            mp[y][x] = z;
        }
        for (int l = 1; l <= n; l++)
        {
            for (int i = 1; i <= n; i++)
            {
                if (i == l) continue;
                for (int j = 1; j <= n; j++)
                {
                    if ((j == l) || (j == i)) continue;
                    mp[i][j] = min(mp[i][j], mp[i][l] + mp[l][j]);
                }
            }
        }
        for (int i = 1; i <= k; i++)
        {
            scanf("%d%d", s + i, d + i);
        }
        d[0] = 1;
        dp[0][0] = 0;
        dp[0][1] = 0x3f;
        for (int i = 1; i <= k; i++)
        {
            dp[i][0]=min(dp[i-1][1]+mp[d[i-1]][d[i]],
                         dp[i-1][0]+mp[d[i-1]][s[i]]+mp[s[i]][d[i]]);
            dp[i][1]=min(dp[i-1][1]+mp[d[i-1]][s[i+1]]+mp[s[i+1]][d[i]],
                         dp[i-1][0]+mp[d[i-1]][s[i]]+mp[s[i]][s[i+1]]+mp[s[i+1]][d[i]]);

        }
        if(dp[k][0])
        printf("Case #%d: %d\n", ti, dp[k][0]);
        else printf("Case #%d: %d\n", ti, -1);
    }
    return 0;
}
