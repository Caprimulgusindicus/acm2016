```cpp

#include <bits/stdc++.h>
using namespace std;
#define lalal puts("*******");
const double PI  =  acos(-1);

struct Round {
    double x, y;
    double r;
}c1,c2;

double dis(Round a, Round b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double solve(Round a, Round b)
{
    double d = dis(a, b);
    if (d >= a.r + b.r)  return 0;

    if (d <= fabs(a.r - b.r))
    {
        double r = a.r < b.r ? a.r : b.r;
        return PI * r * r;
    }

    double ang1 = acos((a.r * a.r + d * d - b.r * b.r) / 2. / a.r / d);
    double ang2 = acos((b.r * b.r + d * d - a.r * a.r) / 2. / b.r / d);
    double ret = ang1 * a.r * a.r + ang2 * b.r * b.r - d * a.r * sin(ang1);
    return ret;
}

int main()
{
    c1.x=0.0,c1.y=0.0,c1.r=1.0;
    c2.x=0.5,c2.y=0.5,c2.r=0.5;

    double s = solve(c1,c2);
    s = PI*0.5-s*2;
  //  printf("%.15lf\n",s);

    int _,n;
    scanf("%d",&_);
    while(_--)
    {
        scanf("%d",&n);
        printf("%.2lf\n",s*n*n);
    }
    return 0;
}

```