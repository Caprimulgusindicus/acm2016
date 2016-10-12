#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int p = 10007;

struct Matrix {
    int a[3][3];
};

Matrix multiply(Matrix a, Matrix b)
{
    Matrix c;
    memset(c.a,0,sizeof(c.a));
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
                c.a[i][j] = (c.a[i][j]+a.a[i][k]*b.a[k][j])%p;
    return c;
}

Matrix pow(Matrix a, int e)
{
    if (e == 1) return a;
    Matrix c = pow(a,e/2);
    c = multiply(c,c);
    if (e&1) c = multiply(c,a);
    return c;
}

int n,kases;

void solve()
{
    Matrix a;
    a.a[0][0] = 2;
    a.a[0][1] = 1;
    a.a[0][2] = 0;
    a.a[1][0] = 2;
    a.a[1][1] = 2;
    a.a[1][2] = 2;
    a.a[2][0] = 0;
    a.a[2][1] = 1;
    a.a[2][2] = 2;
    a = pow(a,n);
    printf("%d\n",a.a[0][0]);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("main.txt","r",stdin);
    #endif
    scanf("%d",&kases);
    for (int kase = 1; kase <= kases; ++kase)
    {
        scanf("%d",&n);
        solve();
    }
    return 0;
}