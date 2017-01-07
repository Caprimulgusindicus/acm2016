#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int mod = 1e9;
void update(int &a, int b) {
  a = (a + b) % mod;
}

int main() {
  int _T;
  scanf("%d", &_T);
  while(_T--) {
    int n, m;
    scanf("%d%d", &n, &m);
    vector< vector<int> >dp(n, vector<int>(1 << m, 0));
    for(int i = 0; i < 1 << m; i++) dp[0][i] = 1;
    int c; scanf("%d", &c);
    for(int j = 0; j * c < 1 << m; j++) dp[0][j * c] = 0;

    for(int i = 1; i < n; i++) {
      scanf("%d", &c);
      for(int mk = 0; mk < 1 << m; mk++) dp[i][mk] = dp[i - 1][((1 << m) - 1) ^ mk];
      for(int d = 0; d < m; d++)
        for(int mk = (1 << m) - 1; mk > -1; mk--) if(1 << d & ~mk) {
          update(dp[i][mk], dp[i][mk ^ (1 << d)]);
        }
      for(int j = 0; j * c < 1 << m; j++) dp[i][j * c] = 0;
    }
    int ans = 0;
    for(int mk = 0; mk < 1 << m; mk++) update(ans, dp[n - 1][mk]);
    cout << ans << endl;
  }
  return 0;
}
