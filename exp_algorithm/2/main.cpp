#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int n;
int dp[222][222];

int main()
{
    //freopen("input.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
                scanf("%d",&dp[i][j]);
        }

        for(int k=2;k<n;k++)
            for(int i=1;i<=n-k;i++)
        {
            int j=k+i;
            for(int l=i+1;l<=j;l++)
            {
                if(dp[i][j]>dp[i][l]+dp[l][j])
                    dp[i][j]=dp[i][l]+dp[l][j];
            }
        }
        cout<<dp[1][n]<<endl;
    }
    return 0;
}
