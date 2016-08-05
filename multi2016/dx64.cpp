#include <stdio.h>



long long mod = 1000000007;


long long qpow(long long a, long long b)
{
    a %= mod;
    long long rtn = 1;
    while (b){
        if (b & 1) rtn = (rtn * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return rtn;
}

int lala(long long n, long long m)
{
    if (n == 0) return 1;
    //m^n + m^(n-1) + m^(n-2) .. + 1
    //= (m^(n+1) - 1) / (m-1)
    long long ans;
    ans = qpow(m, n+1);
    ans = (ans + mod - 1) % mod;    
    ans = ans * qpow(m-1, mod-2) % mod;
    return ans % mod;
}


int main()
{
    int T, n, m;
    scanf ("%d", &T);
    while (T--)
    {
        scanf ("%d%d", &n, &m);
        printf ("%d\n", lala(n, m));
    }
    return 0;
}