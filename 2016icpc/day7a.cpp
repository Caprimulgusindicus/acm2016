#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

#define showtime printf("time = %.15f\n", clock() / (double)CLOCKS_PER_SEC);
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define cls system("cls");

const int maxn = 2005;
const int maxm = 1e5 + 5;
const double eps = 1e-8;
const int mod = 100000007;
const double pi = acos(-1.0);

long long X, Y, x, y, ans;
long long xd[maxn], yd[maxn];
long long C[maxn][maxn];

void init()
{
	C[0][0] = 1;
	for(int i = 1; i < maxn - 2; i++)
	{
		C[i][0] = 1;
		for(int j = 1; j <= i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
}

int main()
{
	init();
	int t;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld", &X, &Y, &x, &y);
		if(x == 0 && y == 0)
		{
			printf("1\n");
			continue;
		}
		long long j, k;
		memset(xd, 0, sizeof(xd));
		memset(yd, 0, sizeof(yd));
		long long a = x - 1, b = X - x, c = y, d = Y - y;
		if(x == 0) xd[0] = 1;
		if(y == 0) yd[0] = 1;
		for(int i = 1; i <= X + 1; i++)
		{
			j = (i - 1) / 2;
			k = (i - 1) - j;
			xd[i] = C[a][j] * C[b][k] % mod;
		}
		for(int i = 1; i <= Y + 1; i++)
		{
			j = (i - 1) / 2;
			k = (i - 1) - j;
			yd[i] = C[c][j] * C[d][k] % mod;
		}
		ans = yd[0] * xd[0];
		for(int i = 1; i <= X + 1; i++)
			ans = (ans + yd[i] * (xd[i] + xd[i - 1])) % mod;
		printf("%lld\n", ans);
	}

	return 0;
}