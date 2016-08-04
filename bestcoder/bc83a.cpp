#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
long long a[33];
int main()
{
    int cas;
    scanf("%d",&cas);
    for(int ca=1;ca<=cas;ca++)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%I64d",&a[i]);
        sort(a+1,a+1+n);
        cout<<a[n]<<endl;
    }
}
