#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#pragma comment(linker, "/STACK:102400000,102400000")
using namespace std;
long long a[22222];
long long ans[22222];
long long aans;

int main()
{
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        memset(a,0,sizeof(a));
        memset(ans,0,sizeof(ans));
        int n,m;

        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%I64d",&a[i]);
        aans=0;

        for(int i=1;i<n;i++)
                for(int j=i+1;j<=n;j++)
                    {
                        long long x=a[i]+a[j];
                        ans[i]^=x;
                    }

        for(int i=1;i<=m;i++)
        {
            int x;long long y;
            scanf("%d%I64d",&x,&y);
            a[x]=y;

            cout<<aans<<endl;
        }
    }
    return 0;
}
