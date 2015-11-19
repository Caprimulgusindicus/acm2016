#include <iostream>
#include <stdio.h>
using namespace std;
int a[33][33];
int b[33][33];
int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&a[i][j]);

        int ans1=0;
        int ans2=0;
        int ans3=0;
        int ans4=0;
        int ans=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                {
                    scanf("%d",&b[i][j]);
                    if(a[i][j]==b[i][j])
                        ans1++;
                }

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                {
                    if(a[i][j]==b[n-j+1][i])
                        ans2++;
                }

         for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                {
                    if(a[i][j]==b[n-i+1][n-j+1])
                        ans3++;
                }

        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                {
                    if(a[i][j]==b[j][n-i+1])
                        ans4++;
                }
        ans1=max(ans1,ans2);
        ans3=max(ans3,ans4);
        ans=max(ans1,ans3);
        cout<<ans<<endl;
    }
    return 0;
}
