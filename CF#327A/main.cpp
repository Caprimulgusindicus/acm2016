#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    double l;
    double a,b;
    while(~scanf("%lf%lf%lf",&l,&a,&b))
    {
        cout<<l/(a+b)*a<<endl;
    }
    return 0;
}
