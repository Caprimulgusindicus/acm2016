#include <cstdio>
#include <cmath>

using namespace std;

const int maxn = 50;
const int maxm = 50010;
const int maxp = 166666;
const int maxl = 400010;

#define chkbit(ar, i) (((ar[(i) >> 6]) & (1 << (((i) >> 1) & 31))))
#define setbit(ar, i) (((ar[(i) >> 6]) |= (1 << (((i) >> 1) & 31))))

using namespace std;

long long dp[maxn][maxm];
unsigned int ar[(maxl >> 6) + 5] = {0};
int len = 0, primes[maxp], counter[maxl];

void eddie ( ) {
    setbit (ar, 0);
    setbit (ar, 1);
    for (int i = 3; (i * i) < maxl; i++, i++) {
        if (!chkbit (ar, i)) {
            int k = i << 1;
            for (int j = (i * i); j < maxl; j += k)
                setbit (ar, j);
        }
    }
    for (int i = 1; i < maxl; i++) {
        counter[i] = counter[i - 1];
        if ( (( (i) && ((i)&1) && (!chkbit(ar, (i)))) || ((i) == 2))) {

            primes[len++] = i;
            counter[i]++;
        }
    }
}

long long phi (long long m, int n) {
    if (n == 0) return m;
    if (primes[n - 1] >= m) return 1;
    if (m < maxm && n < maxn) return dp[n][m];
    return phi (m, n - 1) - phi (m / primes[n - 1], n - 1);
}

long long gao (long long m) {
    if (m < maxl) return counter[m];
    long long w, res = 0;
    int i, a, s, c, x, y;
    s = sqrt (0.9 + m), y = c = cbrt (0.9 + m);
    a = counter[y];
    res = phi (m, a) + a - 1;
    for (i = a; primes[i] <= s; i++)
        res = res - gao (m / primes[i]) + gao (primes[i]) - 1;
    return res;
}

int main ( ) {
    eddie ( );
    for (int n = 0; n < maxn; n++) {
        for (int m = 0; m < maxm; m++) {
            if (!n) dp[n][m] = m;
            else dp[n][m] = dp[n - 1][m] - dp[n - 1][m / primes[n - 1]];
        }
    }
    long long n, res;
    int ii;
    ii++;
    while (scanf("%lld", &n) == 1) {
        printf ("%lld\n", gao (n));
    }
    return 0;
}