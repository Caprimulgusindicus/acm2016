#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <vector>
#include <cstring>
#define MOD 20160519
#define LL long long
#define pb push_back
#define vec vector<LL>
#define mat vector<vec>
using namespace std;

mat mul(mat &a, mat &b, int mod)
{
    mat c(a.size(), vec(b[0].size()));
    for(int i = 0; i < a.size(); ++i)
        for(int k = 0; k < b.size(); ++k)
            for(int j = 0; j < b[0].size(); ++j)
            c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
    return c;
}

mat pow(mat a, LL n, int mod) {
    mat b(a.size(), vec(a.size()));
    for(int i = 0; i < a.size(); ++i)
        b[i][i] = 1;
    while (n > 0) {
        if (n & 1)
            b = mul(b, a, mod);
        a = mul(a, a, mod);
        n >>= 1;
    }
    return b;
}

int main() {
    int T;
    long long n;
    scanf("%d",&T);
    while (T--) {
        scanf("%lld",&n);
        mat A(2, vec(2));
        A[0][0] = 1, A[0][1] = 1;
        A[1][0] = 1, A[1][1] = 0;
        A = pow(A, n, 26880696);
        n = A[1][0];
        A[0][0] = 1, A[0][1] = 1;
        A[1][0] = 1, A[1][1] = 0;
        A = pow(A, n, MOD);
        cout << A[1][0] % MOD << endl;

    }
    return 0;
}