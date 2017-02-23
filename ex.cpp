#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define eps 1e-6
#define MAXN 1000010
#define MAXM 100
#define dd {cout<<"debug"<<endl;}
#define pa {system("pause");}
#define p(x) {printf("%d\n", x);}
#define pd(x) {printf("%.7lf\n", x);}
#define k(x) {printf("Case %d: ", ++x);}
#define s(x) {scanf("%d", &x);}
#define sd(x) {scanf("%lf", &x);}
#define mes(x, d) {memset(x, d, sizeof(x));}
#define do(i, x) for(i = 0; i < x; i ++)
#define dod(i, x, l) for(i = x; i >= l; i --)
#define doe(i, x) for(i = 1; i <= x; i ++)
struct edge
{
	LL u;
	LL v;
	LL w;
};
struct edge E[MAXN];
vector <LL> V[MAXN];
LL n, m;
LL fa[MAXN];
bool vis[MAXN];
LL sum;

bool cmp(struct edge x, struct edge y)
{
	return x.w < y.w;
}

LL _find(LL u)
{
	return u == fa[u] ? u : fa[u] = _find(fa[u]);
}

bool _union(LL x, LL y)
{
	x = _find(x);
	y = _find(y);

	if(x == y) return false;

	fa[x] = y;
	return true;
}

LL kruskal()
{
	LL ans = 0;
	LL num = 0;
	for(LL i = 0; i < m; i ++)
	{
		if(_union(E[i].u, E[i].v))
		{
			V[E[i].u].push_back(E[i].v);
			V[E[i].u].push_back(E[i].w);
			V[E[i].v].push_back(E[i].u);
			V[E[i].v].push_back(E[i].w);
			ans += E[i].w;
			num += 1;
		}
		if(num == n - 1)
			return ans;
	}
	return ans;
}

LL dfs(LL pos)
{
	vis[pos] = true;
	LL res = 0;
	for(LL i = 0; i < V[pos].size(); i += 2)
		if(!vis[V[pos][i]])
		{
			LL u = V[pos][i];
			LL w = V[pos][i + 1];
			LL num = dfs(u);
			res = res + num;
			sum = sum + res * (n - res) * w;
		}
	return res + 1;
}

int main()
{
    freopen("1.in","r",stdin);
	int T;
	scanf("%d", &T);
	while(T --)
	{
		scanf("%I64d %I64d", &n, &m);
		for(LL i = 1; i <= n + 1; i ++) fa[i] = i;
		for(LL i = 1; i <= n + 1; i ++) V[i].clear();
		for(LL i = 0; i < m; i ++)
			scanf("%I64d %I64d %I64d", &E[i].u, &E[i].v, &E[i].w);

		sort(E, E + m, cmp);
		printf("%I64d ", kruskal());
		sum = 0;

		for(LL i = 1; i <= n; i ++)
			if(V[i].size() == 2)
			{
				dfs(i);
				break;
			}
		double ans = sum * 2.0 / (n * 1.0 * (n - 1.0));
		printf("%.2f\n", ans);
	}
	return 0;
}
