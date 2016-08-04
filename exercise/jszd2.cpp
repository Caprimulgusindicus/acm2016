#include <iostream>
#include <stdio.h>
using namespace std;
long long sec;
int main()
{
    long long n,m;
    scanf("%lld%lld",&n,&m);
    sec=1;
    for(long long i=n;i>=m;i--)
        sec=sec*i,cout<<i<<endl;
    cout<<sec<<endl;
    return 0;
}