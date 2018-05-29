#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    freopen("inal.in","r",stdin);
    freopen("outal.txt","w",stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        int n;
        double d, ans = 1e20;
        scanf("%lf%d", &d, &n);
        for (int i = 1; i <= n; i++)
        {
            double k, s;
            scanf("%lf%lf", &k, &s);
            ans = min(ans, k * s / (d - k) + s);
        }
        printf("Case #%d: %.7f\n", cas, ans);
    }
    return 0;
}