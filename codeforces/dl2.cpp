int ant[100010];
int s[100010];
ll a[100010];
ll ans, k;
int n;

void find(int x)
{
	int t = x;
	ll m = k / a[x];
	if (ant[x] == -1) {
		ant[x]++;

		while (s[t] != t)
		{
			t = s[t];
			if (a[t] <= m)
				ant[x]++;
		}
	}
	ans += ant[x];
}

int main()
{
	fr;
	detie;
	int T, t1, t2;
	scanf("%d", &T);
	while (T--)
	{
		memset(ant, -1, sizeof ant);
		memset(s, 0, sizeof s);
		memset(a, 0, sizeof a);
		ans = 0;
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= n; i++)
			scanf("%I64d", a + i);
		s[1] = 1;
		for (int i = 1; i < n; i++){
			scanf("%d %d", &t1, &t2);
			s[t2] = t1;
		}
		for (int i = 1; i <= n; i++)
			find(i);
		printf("%I64d\n", ans);
	}
	rt 0;
}