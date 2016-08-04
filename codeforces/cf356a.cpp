#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int a[111];
int main()
{
    int t1,t2,t3,t4,t5;
    scanf("%d%d%d%d%d",&a[1],&a[2],&a[3],&a[4],&a[5]);
    int ans=1111111;
    sort(a+1,a+1+5);


    if(a[5]==a[4]&&a[5]==a[3]&&a[4]==a[3]) ans=min(ans,a[2]+a[1]);
    if(a[4]==a[3]&&a[4]==a[2]&&a[2]==a[3]) ans=min(ans,a[5]+a[1]);
    if(a[3]==a[2]&&a[3]==a[1]&&a[2]==a[1]) ans=min(ans,a[4]+a[5]);
    if(a[5]==a[4]) ans=min(ans,a[1]+a[2]+a[3]);
    if(a[4]==a[3]) ans=min(ans,a[1]+a[2]+a[5]);
    if(a[3]==a[2]) ans=min(ans,a[1]+a[4]+a[5]);
    if(a[2]==a[1]) ans=min(ans,a[4]+a[5]+a[3]);
    ans=min(ans,a[1]+a[2]+a[3]+a[4]+a[5]);
    cout<<ans<<endl;

    return 0;
}
