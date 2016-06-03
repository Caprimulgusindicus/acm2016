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

const int maxn = 1010;
char str[maxn];

int main() {
	// freopen("in", "r", stdin);
	int T;
	scanf("%d", &T);
	getchar();
	while(T--) {
		gets(str);
		int n = strlen(str);
		for(int i = 0; i < n; i++)
			str[i] = tolower(str[i]);
		strstr(str, "skillful") != NULL ? 
			printf("touma is a little 3\n") :
			printf("oh my little zz\n");
	}
	return 0;
}