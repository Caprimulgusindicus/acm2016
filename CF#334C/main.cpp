#include <iostream>
#include <stdio.h>
using namespace std;
char a[111111];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int ans=0;
        getchar();
        for(int i=1;i<=n;i++)
            scanf("%c",&a[i]);

        int c0=0;
        int c1=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]=='0') c0++;
            if(a[i]=='1') c1++;

        }
        if(c0>=2||c1>=2) ans+=2;

       // for(int i=1;i<=n;i++)
        //    cout<<a[i];
        for(int i=1;i<n;i++)
            if(a[i]!=a[i+1]) ans++;
        cout<<ans+1<<endl;
    }
    return 0;
}
