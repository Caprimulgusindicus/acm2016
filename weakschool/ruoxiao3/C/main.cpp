#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1111];
int main()
{
    int n,sum=0;
    float aver=0;
    int ans=0;
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
    aver=float(sum)/float(n);
    //cout<<aver;
    if(n==1) puts("0\n");
    else
    {
         for(int i=1;i<=n;i++)
        {
           if(a[i]>aver) ans++;
        }
        cout<<ans<<endl;
    }
    //for(int i=1;i<=n;i++)
    //    cout<<a[i]<<endl;
    return 0;
}
