#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
    freopen("cl.in","r",stdin);
    freopen("outcl.txt","w",stdout);
    int tt;
    scanf("%d", &tt);
    for (int ti = 1; ti <= tt; ti++)
    {
        ll n, k;
        scanf("%lld%lld", &n, &k);
        ll i = 1;
        while (k >= (1ll << i)) i++;
        ll low1 = (n + 1 - (1 << (i - 1))) / (1 << (i - 1));
        ll hig1 = n / (1 << (i - 1));
        ll cnth1 = (n + 1 - (1 << (i - 1))) % (1 << (i - 1));
        k -= (1 << (i - 1));
        ll ans = (k < cnth1) ? (hig1 - 1) : (low1 - 1);
        printf("Case #%d: %lld %lld\n", ti, (ans + 1) / 2, ans / 2);
    }
    return 0;
}
