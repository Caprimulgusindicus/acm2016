#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <climits>
#include <complex>
#include <fstream>
#include <cassert>
#include <cstdio>
#include <bitset>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <set>
#include <map>
#include <cmath>

using namespace std;

const int maxn = 1110;

int keys[11][258];
int n, m, ans;
int cnt, kcnt, hcnt;
bool pos[9];
bool msr[maxn][9];
bool kirai[maxn][9];
char notes[maxn][9];
char tmp[maxn];

void init() {
	keys[4]['D']=0,keys[4]['F']=1,
	keys[4]['J']=2,keys[4]['K']=3;

	keys[5]['D']=0,keys[5]['F']=1,
	keys[5][' ']=2,keys[5]['J']=3,keys[5]['K']=4;

	keys[6]['S']=0,keys[6]['D']=1,keys[6]['F']=2,
	keys[6]['J']=3,keys[6]['K']=4,keys[6]['L']=5;

	keys[7]['S']=0,keys[7]['D']=1,keys[7]['F']=2,
	keys[7][' ']=3,keys[7]['J']=4,keys[7]['K']=5,keys[7]['L']=6;
}

void solve(int k) {
	for(int i = m - 1; i >= 0; i--) {
		memset(pos, 0, sizeof(pos));
		cnt = 0;
		for(int j = 0; j < k; j++) {
			if(notes[i][j] == '_') {
				pos[j] = 1; cnt++;
			}
		}
		for(int j = 0; j < k; j++) {
			if(pos[j]) msr[kcnt][j] = 1;
		}
		kcnt++;
	}
	for(int i = 0; tmp[i]; i++) {
		if(tmp[i] == '(') {
			int j = i + 1;
			for(; tmp[j] != ')'; j++) {
				kirai[hcnt][keys[k][tmp[j]]] = 1;
			}
			i = j; hcnt++;
			continue;
		}
		kirai[hcnt++][keys[k][tmp[i]]] = 1;
	}
	int cur = 0;
	for(int i = 0; i < m; i++) {
		bool flag = 0;
		for(int j = 0; j < k; j++) {
			if(msr[i][j] == 1 && kirai[i][j] == 0) {
				flag = 1;
				break;
			}
		}
		if(!flag) {
			cur++;
			ans = max(ans, cur);
		}
		else cur = 0;
	}
}


int main() {
	// freopen("in.txt", "r", stdin);
	init();
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &n, &m);
		memset(tmp, 0, sizeof(tmp));
		memset(msr, 0, sizeof(msr));
		memset(kirai, 0, sizeof(kirai));
		kcnt = 0; hcnt = 0; ans = 0;
		for(int i = 0; i < m; i++) {
			scanf("%s", notes[i]);
		}
		getchar();
		gets(tmp);
		solve(n);
		printf("%d\n", ans);
	}
	return 0;
}