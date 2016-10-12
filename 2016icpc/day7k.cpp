#include <cstdio>
#include <iostream>
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define cls system("cls");

const int maxn = 5005;
const int maxm = 1e5 + 5;
const double eps = 1e-8;
const int mod = 10007;

unsigned long long f[maxn], t[maxn];

void init()
{
    f[0] = f[1] = f[2] = 1;
    t[0] = t[1] = t[2] = 1;
    for(int i = 3; i < maxn - 2; i++)
    {
        f[i] = 0;
        for(int j = 2; j < i; j++)
            f[i] += t[j] * t[i - j + 1];
        t[i] = f[i];
        for(int j = 2; j < i - 1; j++)
            t[i] += t[j] * f[i - j + 1];
    }
}

int main()
{
    init();
    int n;
    while(scanf("%d", &n) != EOF)
        cout << t[n] << endl;

    return 0;
}