#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int a[55];
int b[55];
int c[55];
int path[55];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        for(int i=1;i<n;i++)
            scanf("%d",&a[i]);

        for(int i=1;i<n;i++)
        {
            a[i]+=a[i-1];
        }
        a[n]=0;
        for(int i=1;i<n;i++)
            scanf("%d",&b[i]);
        for(int i=n-1;i>=1;i--)
        {
            b[i]+=b[i+1];
            //cout<<i<<" "<<b[i]<<endl;
        }
        b[n]=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&c[i]);

        for(int i=0;i<n;i++)
        {
            path[i]=a[i]+b[i+1]+c[i+1];
            //cout<<path[i]<<endl;
        }

        sort(path,path+n);

        cout<<path[0]+path[1]<<endl;
    }
    return 0;
}
