#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <cstdio>
using namespace std;
int m[20][20];
int dp[20][1<<17];

int main()
{
    int ca;
    scanf("%d",&ca);
    for(int cc=1;cc<=ca;cc++)
    {
        memset(m,0,sizeof(m));
        memset(dp,0,sizeof(dp));
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&m[i][j]);
        int t= 1<<n;

        for(int i=0;i<n;i++)
            dp[0][1<<i]=m[0][i];

        for(int i=1;i<n;i++)
            for(int j=0;j<t;j++)
            {

                if(!dp[i-1][j]) continue;
                for(int k=0;k<n;k++)
                {
                           // cout<<"222"<<endl;

                    if(j&(1<<k)) continue;
                        cout<<dp[i][j|(1<<k)]<<" "<<dp[i][(1<<k)|j]<<" "<<m[i][k]<<endl;
                        dp[i][j|(1<<k)]=max(dp[i][(1<<k)|j],dp[i-1][j]+m[i][k]);

                        cout<<dp[i][j|(1<<k)]<<" "<<dp[i][(1<<k)|j]<<" "<<m[i][k]<<endl;
                        printf("%d\n",j|(1<<k));
                }
            }
           // cout<<dp[1][1]<<" "<<dp[1][2]<<" "<<dp[2][1]<<endl;
       printf("Case %d: %d\n", cc, dp[n-1][t-1]);
    }
    return 0;
}
