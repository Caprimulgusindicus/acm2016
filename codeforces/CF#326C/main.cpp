#include<stdio.h>
#include<string.h>
int a[1111111];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        memset(a,0,sizeof(a));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            a[x]++;
        }

        for(int i=1;i<1111111;i++)
            {
                a[i]+=(a[i-1]/2);
                a[i-1]%=2;
            }

        for(int i=0;i<1111111;i++)
            ans+=a[i];
        printf("%d\n",ans);
    }
    return 0;
}
