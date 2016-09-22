#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <bitset>
using namespace std;
#define RT return
typedef long long LL;
const LL mod = (LL)1e9+7;
int n, m, k;
LL f[1111111], inv[1111111];

LL mul(LL x, LL y) 
{
	LL ret = 1;
	while(y) 
	{
		if(y&1)ret=(x*ret)%mod;
		y>>=1;
		x=(x*x)%mod;
	}
	return ret;
}

long long C(long long x, long long y) 
{
	return f[x+y-1]*inv[x]%mod*inv[y-1]%mod;
}

int main() 
{
	
	int T;
	scanf("%d",&T);
	f[0] = inv[0] = 1;
	for(int i= 1;i< 1111111;i++) f[i] = f[i-1] * i % mod;
	inv[1000000] = mul(f[1000000], mod-2);
	for(int i = 999999; i >= 1; i--) {
		inv[i] = inv[i+1] * (i + 1) % mod;
	}
	while(T--) 
	{
		scanf("%d%d%d", &n,&m,&k);
		LL ret = 0;
		if(m == 1) ret = n;
		else if(n < m * (k + 1)) ret = 0;
		else {
			ret = (C(n-m*(k+1), m+1) + C(n-m*(k+1), m) * k) % mod;
		}
		printf("%I64d\n", ret);
	}
	RT 0;
}