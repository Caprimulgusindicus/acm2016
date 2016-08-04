#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n,m;
    int a[1111];
    int ans=0;
    int sum=0;
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
        {
            if(sum>=m) break;
            sum+=a[i];
            //cout<<sum<<endl;
            ans++;

        }
    cout<<ans<<endl;
    return 0;
}
