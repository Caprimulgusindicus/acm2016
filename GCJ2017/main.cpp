#include <map>
#include <set>
#include <tuple>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <cstdio>
#include <memory>
#include <cctype>
#include <bitset>
#include <string>
#include <vector>
#include <climits>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>
#define fuck(x) cout<<"["<<x<<"]";
#define FIN freopen("input.txt","r",stdin);
#define FOUT freopen("outputb.txt","w+",stdout);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int MX = 1e4 + 5;

char S[MX];
bool ok[MX];

int main() {
    // FIN;
    freopen("blar.in", "r", stdin);
    FOUT;
    int T, ansk = 0;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", S + 1);
        printf("Case #%d: ", ++ansk);

        int len = strlen(S + 1);
        ok[1] = 1;
        for(int i = 2; i <= len; i++) {
            if(ok[i - 1] && S[i - 1] <= S[i]) ok[i] = 1;
            else ok[i] = 0;
        }

        if(ok[len]) {
            printf("%s\n", S + 1);
            continue;
        }
        S[0] = '0';

        bool sign = false;
        for(int p = len - 1; p >= 1; p--) {
            if(S[p] > '0' && S[p] - 1 >= S[p - 1]) {
                for(int i = 1; i < p; i++) printf("%c", S[i]);
                if(p != 1 || S[p] - 1 != '0') printf("%c", S[p] - 1);
                for(int i = p + 1; i <= len; i++) printf("9");
                sign = true; break;
            }
        }
        printf("\n");
    }
    return 0;
}