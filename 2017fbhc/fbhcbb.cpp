#include <cstdio>
#include <algorithm>

using namespace std;

int a[107];

int main()
{
    int tt;
    scanf("%d", &tt);
    for (int ti = 1; ti <= tt; ti++)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i <= n - 1; i++)
        {
            scanf("%d", a + i);
        }
        sort(a, a + n);
        int ans = 0;
        for (int i = n - 1, j = 0; i >= j; i--)
        {
            int k = 50 / a[i];
            if (50 % a[i] != 0) k++;
            j += k - 1;
            //printf("%d %d\n", j, k);
            if (j > i) break;
            ans++;
        }
        printf("Case #%d: %d\n", ti, ans);
    }
    return 0;
}