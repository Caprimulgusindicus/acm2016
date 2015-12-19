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

typedef long long  LL;

LL n;

LL solve(LL x) {
    if(x == 1) return 1;
    if(x % 2 == 0) return solve(x / 2) * 3 + 1;
    return solve(x / 2) * 3;
}

int main() {
    // freopen("in", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%I64d", &n);
        printf("%I64d\n", solve(n));
    }
    return 0;
}
