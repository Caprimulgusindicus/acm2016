#include <cstdio>
#include <cstring>
#include <cmath>

typedef long long ll;
ll n, m, k;
ll min(ll a, ll b) {
        return a > b ? b : a;
}

int main()
{
        while (~scanf("%lld%lld%lld", &n, &m, &k))
        {
                if (k == 0 || k == 2)
                { puts("0"); continue; }
                ll a = min(n, (k - 1) / 2);
                ll i = 1, sum = 0;
                for (; i <= a; i++)
                {
                        ll tem = k / 2 - i;
                        if (tem > m) tem = m;
                        sum += tem * (2 * m - tem + 1) / 2 * (n - i + 1);
                }
                printf("%lld\n", sum);
        }
        return 0;
}
