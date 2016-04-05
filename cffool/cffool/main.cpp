#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    long long  ans=1;
    while(n--)
        ans*=2;
    cout<<ans<<endl;
    return 0;
}