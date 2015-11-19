#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int i;
    int n;
    double res;
    double tmp;
    while(cin>>n)
    {
        cin>>tmp;
        res=1.0*n*tmp;
        cin>>tmp;
        res+=tmp;
        for(int i=1;i<=n;i++)
            scanf("%lf",&tmp),res-=2.0*(n+1-i)*tmp;
        printf("%.2lf\n",res/(n+1));
    }
    return 0;
}
