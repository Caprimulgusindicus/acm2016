#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <bitset>
#include <algorithm>
using namespace std;

long long dp[333][333], sum[333];
int n;

struct num
{
	int key;
	int value;
}a[333];

int gcd(int a,int b)
{
	if(b==0) return a;
	return gcd(b,a%b);
}

int main() 
{
    int T;
    scanf("%d",&T);
    while (T--) 
    {
    	memset(dp, 0, sizeof(dp));
        scanf("%d",&n);
        sum[0] = 0;
        for (int i = 1; i <= n; i++) 
        	scanf("%d",&a[i].key);

        for (int i = 1; i <= n; i++) 
        {
            scanf("%d",&a[i].value);
            sum[i] = sum[i - 1] + a[i].value;
        }

  	    a[0].key=1; 
  	    a[0].value=0;

   		 for (int l = 2; l <= n; l++) 
   		 {
           for (int i = 1; i<=n;i++) 
           {
	           	int j=i+l-1;
	            if (j<=n) 
	            {
		            for (int k=i;k<j;k++) 
		            {
		                dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
		            }
		            int ggcd=gcd(a[i].key, a[j].key);
		            if (ggcd>1) 
		            {
		                if (j==i+1) dp[i][j]=max(dp[i][j],(long long)(a[i].value + a[j].value));
		                else if (dp[i+1][j-1]==sum[j-1]-sum[i]) dp[i][j]=max(dp[i][j], (long long)(dp[i + 1][j - 1] + a[i].value + a[j].value));
		            }
            }
        }
    }
    printf("%lld\n",dp[1][n]);
    }
    return 0;
}