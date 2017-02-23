#include <cmath>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <math.h>
#include <algorithm>
using namespace std;
#define SQ(x) ((x) * (x))
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("outaa.txt", "w", stdout);
	const int ox = 50, oy = 50;
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		int p, x, y;
		scanf("%d%d%d", &p, &x, &y);
        if(p==0&&x==50&&y==50) printf("Case #%d: white\n", cas);
		else
        {double dis = sqrt(SQ(x - ox) + SQ(y - oy));
		double a = atan2(x - ox, y - oy) / acos(-1) * 180;
		if (a < 0.0) a += 360;
		if (dis <= 50.0 && a <= p / 100.0 * 360) printf("Case #%d: black\n", cas);
		else printf("Case #%d: white\n", cas);}
	}
	return 0;
}
