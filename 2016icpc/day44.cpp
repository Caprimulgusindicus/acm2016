#include <cstdio>
#include <cstring>
#include <iostream>
#define rt return
typedef long long ll;
using namespace std;
bool v[111111];
ll cost[111111];
ll dis[111111][111111];
ll s[111111];

ll prim(int n)
{
	for (int i = 0; i < n; i++) {
		cost[i] = 111111ll;
		v[i] = false;
	}
	cost[0] = 0;//
	ll ans = 0;
	while (true) {
		int t = -1;
		for (int i = 0; i < n; i++) {
			if (!v[i] && (t == -1 || cost[i] < cost[t]))
				t = i;
		}
		if (t == -1)
			break;
		ans += cost[t];
		v[t] = true;
		for (int i = 0; i < n; i++) {
			cost[i] = min(cost[i], dis[t][i]);
		}
	}
	rt ans;
}

int main() {
	//fr;
	//detie;
	int n;
	while(~scanf("%d", &n))
	{
	for (int i = 0; i < n; i++)
		scanf("%lld", s + i);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dis[i][j] = dis[j][i] = s[i] ^ s[j];
	printf("%lld\n", prim(n));
}
	rt 0;
}