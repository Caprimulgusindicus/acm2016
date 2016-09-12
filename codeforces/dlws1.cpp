#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <functional>
#include <cmath>
#include <cctype>
#include <cfloat>
#include <climits>
#include <complex>
#include <deque>
#include <list>
#include <set>
#include <utility>
#define rt return
#define fr freopen("in.txt","r",stdin)
#define fw freopen("out.txt","w",stdout)
#define ll long long
#define ull unsigned long long
#define detie ios_base::sync_with_stdio(false);cin.tie(false);cout.tie(false)
#define pii pair<int,int>
#define lowbit(x) x&(-x)
using namespace std;
#define maxi 0x3f3f3f3f
#define MAX 20010

int s[MAX];

int main()
{
    //fr;
    //detie;
    int T, b, re,su;
    while(~scanf("%d", &T))
    {
        while (T--)
        {
            su = 0;
            re = 0;
            scanf("%d", &b);
            for (int i = 0; i < b; i++) {
                scanf("%d", s + i);
                su += s[i];
            }
            if (su != b*(b - 1) || b == 0 || b == 1) {
                printf("%c\n", 'F');
                continue;
            }
            sort(s, s + b, greater<int>());
            bool flag = true;
            for (int i = 0; i < b&&flag; i++) {
                re += 2 * (b - i - 1);
                if (s[i] > re)
                    flag = false;
                re -= s[i];
            }
            if (flag)
                printf("%c\n", 'T');
            else
                printf("%c\n", 'F');
        }
    }
    rt 0;
}