#include <stdio.h>
#include <iostream>
using namespace std;
int a[11111];
int main()
{
    int n,h;
    int ans=0;
    scanf("%d%d",&n,&h);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);

    }
    for(int i=1;i<=n;i++)
    {
         if(a[i]>h) ans+=2;
            else ans+=1;
    }
    printf("%d\n",ans);
    return 0;
}
