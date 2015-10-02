#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
const int N = 100000;
int n, L;
int a[N + 1];
int x[N + 10], y[N + 10];
int ax[N + 10], ay[N + 10];
int t[N + 1],tp;
void LDS()
{
    memset(t, 0, sizeof(t));
    tp = 0; ax[n + 1] = 2147483647;
    for (int i = n; i >= 1; i--)
    {
        int s = 0, e = tp - 1;
        while (s <= e)
        {
            int m = (s + e) >> 1;
            if (t[m] > a[i]) s = m + 1;
            else e = m - 1;
        }
        if (s >= tp) t[tp++] = a[i];
        else t[s] = a[i];
        x[i] = tp;
        ax[i] = t[tp - 1];
    }
}
void LIS()
{
    memset(t, 0, sizeof(t));
    tp = 0; ay[0] = -2147483647;
    for (int i = 1; i <= n; i++)
    {
        int s = 0, e = tp - 1;
        while (s <= e)
        {
            int m = (s + e) >> 1;
            if (t[m] < a[i]) s = m + 1;
            else e = m - 1;
        }
        if (s >= tp) t[tp++] = a[i];
        else t[s] = a[i];
        y[i] = tp;
        ay[i] = t[tp - 1];
    }
}
int main()
{
    // freopen("in", "r", stdin);
    int T;
    scanf("%d", &T);
    for (int dex = 1; dex <= T;dex++)
    {
        scanf("%d%d", &n, &L);
        memset(a,0,sizeof(y));
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        a[0] = -2147483647; a[n + 1] = 2147483647;
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        memset(ay, 0, sizeof(y));
        memset(ax, 0, sizeof(y));
        memset(t, 0, sizeof(y));
        tp=0;
        LDS(); LIS();
        int ans = 0;
        for (int i = 0; i <= n - L; i++)
            if (ay[i]<ax[i+L+1])
                ans = max(ans, x[i + L+1] + y[i]);
        printf("Case #%d: %d\n", dex, ans);
    }
//    system("pause");
    return 0;
}
