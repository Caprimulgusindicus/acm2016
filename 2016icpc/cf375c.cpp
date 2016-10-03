#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e3 + 3;
int a[maxn], _a[maxn];
int cnt[maxn], _cnt[maxn];
int n, m;
bool check(int p)
{
    for(int i = 1; i <= n; i++) _a[i] = a[i];
    for(int i = 1; i <= m; i++) _cnt[i] = cnt[i];
    int now = 1;
    for(int i = 1; i <= n; i++)
        if(_a[i] > m || _cnt[_a[i]] > p)
        {
            while(now <= m && _cnt[now] >= p) now++;
            if(now > m) break;
            if(_a[i] <= m) _cnt[_a[i]]--;
            _a[i] = now;
            _cnt[now]++;
        }
    for(int i = 1; i <= m; i++) if(_cnt[i] < p) return 0;
    return 1;
}
int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if(a[i] <= m)
            cnt[a[i]]++;
    }
    int l = 0, r = n + 1;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(check(mid)) l = mid + 1;
        else r = mid;
    }
    l--;
    int ans = 0;
    check(l);
    for(int i = 1; i <= n; i++) if(a[i] != _a[i]) ans++;
    printf("%d %d\n", l, ans);
    for(int i = 1; i <= n; i++) printf("%d ", _a[i]);
    return 0;
}