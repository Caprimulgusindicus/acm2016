#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
#define MOD 1000000007
ll r[2222];
ll lala[4444];

ll qpow(ll a, ll b)
{
    ll ans=1;
    while(b>0)
    {
        if(b%2==1)
        {
            ans=ans*a%MOD;
        }
        a=a*a%MOD;
        b>>=1;
    }
    return ans;
}

ll pre(ll m, ll n)
{
    ll ans = 1;
    if (m - n < n) n = m - n;
    for (ll i = 1; i <= n; i++)
        ans = ans * (m - n + i) % MOD * qpow(i, MOD - 2) % MOD;
    return ans;
}

int main()
{
    freopen("beach_umbrellas.txt", "r", stdin);
	freopen("outputd.txt", "w", stdout);
    int T;
    scanf("%d",&T);
    for (int ca = 1; ca <= T; ca++)
    {
        int n;
        ll m;
        scanf("%d%I64d", &n, &m);
        ll sum = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%I64d", r + i);
            sum += r[i];
        }
        if (n == 1)
        {
            printf("Case #%d: %I64d\n", ca, m);
            continue;
        }
        m--;
        ll base = 1;
        for (ll i = 1; i <= n - 2; i++)
        {
            base *= i;
            base %= MOD;
        }
        int cnt = 0;
        ll ans = 0, last;
        sum = m - sum * 2ll;
        //pre processing
        for (int i = 1; i <= 4007; i++)
        {
            if (sum + i < 0) lala[i] = 0;
            else lala[i] = pre(sum + i + n, n) * base % MOD;
        }
        //combination
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j) continue;
                ans = (ans + lala[r[i] + r[j]]) % MOD;
            }
        }
        printf("Case #%d: %I64d\n", ca, ans);
    }
    return 0;
}
