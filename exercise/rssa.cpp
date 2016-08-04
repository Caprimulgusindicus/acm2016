#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
    int cas;
    scanf("%d",&cas);
    for(int i=1;i<=cas;i++)
    {
        double a,b;
        scanf("%lf%lf",&a,&b);
        printf("%.2lf\n",b/a);
    }
    return 0;
}
