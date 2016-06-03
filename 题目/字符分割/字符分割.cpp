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

const int maxn = 110;
const int dx[9] = {1, -1, 0, 0, 1, 1, -1, -1};
const int dy[9] = {0, 0, 1, -1, 1, -1, 1, -1};
int n, m, ans;
char G[maxn][maxn];

bool ok(int x, int y) {
    return x >= 0 && y >= 0 && x < n && y < m;
}
void dfs(int x, int y) {
    G[x][y] = '.';
    for(int i = 0; i < 8; i++) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(ok(xx, yy) && G[xx][yy] != '.') {
            dfs(xx, yy);
        }
    }
}
int main() {
    // freopen("in", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--) {
        ans = 0;
        memset(G, 0, sizeof(G));
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++) {
            scanf("%s", G[i]);
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(G[i][j] != '.') {
                    ans++;
                    dfs(i, j);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}