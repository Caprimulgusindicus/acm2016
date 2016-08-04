#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int a[555];
int ans;
int n;

void init()
{
    for(int i=1;i<n-1;i++)
        a[i]=1;
    a[n-1]=2;
    a[n]=n;
}

void dfs()
{
    if(a[n]==1&&a[n-1]==1) return;
    if(a[])
}

int main()
{
    freopen("1.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        ans=0;
        if(n==1||n==2)
        {
            cout<<1<<endl;
            continue;
        }

        init();
        dfs();
        cout<<ans<<endl;
    }
    return 0;
}
