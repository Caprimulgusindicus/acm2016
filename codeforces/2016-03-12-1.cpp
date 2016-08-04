#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int n;
    int a;
    while(~scanf("%d",&n)&&n)
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a);
            ans+=a*a;
        }
        printf("%d\n",ans);
    }
    return 0;
}
