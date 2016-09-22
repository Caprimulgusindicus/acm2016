#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>
using namespace std;
typedef long long ll;
ll *biubiubiu, *v;
ll q = 1, p = 1;

ll pi(ll n, ll biubiubiu[], ll len)
{
    ll i = 0, mark = 0;
    for (i = len - 1; i > 0; i--) {
        if (biubiubiu[i] < n) {
            mark = 1;
            break;
        }
    }
    if (mark)
        return i + 1;
    return 0;
}

ll phi(ll x, ll a, ll m)
{
    if (a == m)
        return (x / q) * p + v[x % q];
    if (x < biubiubiu[a - 1])
        return 1;
    return phi(x, a - 1, m) - phi(x / biubiubiu[a - 1], a - 1, m);
}

ll prime_counter(ll n)
{
    char *mark;
    ll mark_len;
    ll teemo = 0;
    ll i, j, m = 7;
    ll sum = 0, s = 0;
    ll len, len2, len3;

    mark_len = (n < 10000) ? 10002 : ((ll)exp(2.0 / 3 * log(n)) + 1);

    mark = (char *)malloc(sizeof(char) * mark_len);
    memset(mark, 0, sizeof(char) * mark_len);
    for (i = 2; i < (ll)sqrt(mark_len); i++) {
        if (mark[i])
            continue;
        for (j = i + i; j < mark_len; j += i)
            mark[j] = 1;
    }
    mark[0] = mark[1] = 1;
    for (i = 0; i < mark_len; i++)
        if (!mark[i])
            teemo++;
    biubiubiu = (ll *)malloc(sizeof(ll) * teemo);
    j = 0;
    for (i = 0; i < mark_len; i++)
        if (!mark[i])
            biubiubiu[j++] = i;

    if (n < 10000)
        return pi(n, biubiubiu, teemo);

    len = pi((ll)exp(1.0 / 3 * log(n)), biubiubiu, teemo);
    len2 = pi((ll)sqrt(n), biubiubiu, teemo);
    len3 = pi(mark_len - 1, biubiubiu, teemo);
    j = mark_len - 2;
    for (i = (ll)exp(1.0 / 3 * log(n)); i <= (ll)sqrt(n); i++) {
        if (!mark[i]) {
            while (i * j > n) {
                if (!mark[j])
                    s++;
                j--;
            }
            sum += s;
        }
    }
    free(mark);
    sum = (len2 - len) * len3 - sum;
    sum += (len * (len - 1) - len2 * (len2 - 1)) / 2;

    if (m > len)
        m = len;
    for (i = 0; i < m; i++) {
        q *= biubiubiu[i];
        p *= biubiubiu[i] - 1;
    }
    v = (ll *)malloc(sizeof(ll) * q);
    for (i = 0; i < q; i++)
        v[i] = i;
    for (i = 0; i < m; i++)
        for (j = q - 1; j >= 0; j--)
            v[j] -= v[j / biubiubiu[i]];

    sum = phi(n, len, m) - sum + len - 1;
    free(biubiubiu);
    free(v);
    return sum;
}

int main()
{
    ll n;
    ll teemo;
int h;
while(scanf("%lld", &n)!=EOF){
if (n == 2) {
puts("1");
} else {
printf("%lld\n", prime_counter(n+1));
}
}
    return 0;
}