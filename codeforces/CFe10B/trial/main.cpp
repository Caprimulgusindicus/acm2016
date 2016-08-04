#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
long long a[1111];
long long b[1111];//jishu
long long oushu[1111];
int cmp(long long a,long long b)
{
    return a>=b;
}
int main()
{
    long long n;
    scanf("%lld",&n);
    
    memset(a,0,sizeof(a));
    memset(oushu,0,sizeof(oushu));
    memset(b,0,sizeof(b));
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        //cout<<a[i]<<endl;
    }
    
    sort(a+1,a+n+1);
    
    
    int p=1;
    for(int i=1;i<=n;i+=2) b[i]=a[p++];
    
    for(int i=2;i<=n;i+=2) b[i]=a[p++];
    
    for(int i=1;i<=n;i++) cout<<b[i]<<" ";
    puts("");
    
    return 0;
}
