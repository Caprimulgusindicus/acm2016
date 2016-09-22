bool vis[MAX];
int val[MAX];
int du[MAX];
int main() {
	fr; 
	detie;
	int m, n, T;
	scanf("%d", &T);
	while (T--){
		int a, b;
		memset(vis, 0, sizeof vis);
		memset(du, 0, sizeof du);
		scanf("%d %d", &n, &m);
		for (int i = 1; i <= n;i++){
			scanf("%d", val + i);
		}
		for (int i = 1; i <= m;i++){
			scanf("%d %d", &a, &b);
			du[a]++;
			du[b]++;
			vis[a] = vis[b] = true;
		}
		int ji=0;
		int ans = 0;
		int maxx = 0;
		for (int i = 1; i <= n&&ji <= 2; i++) {
			if(vis[i])
			{
				int t = du[i] / 2;
				if (du[i] % 2 == 1) {
					ji++;
					t++;
				}
				if (t % 2)
					ans ^= val[i];
			}
		}
		if (ji > 2||ji==1) {
			printf("Impossible\n");
			continue;
		}
		else if (ji == 2) {
			printf("%d\n", ans);
			continue;
		}
		else {
			for (int i = 1; i <= n; i++) {
				if (vis[i]) {
					maxx = max(maxx, ans^val[i]);
				}
			}
			printf("%d\n", maxx);
		}
	}
	rt 0;
}