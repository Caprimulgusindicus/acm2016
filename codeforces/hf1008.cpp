#include <cstring>
#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
int a[111];
int aa[111];
int x;
int dp[111][111];
int minn;
int n,m;
int abs(int n)
{
    return n>0?n:-n;
}



int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        minn=2222;
        memset(a,0,sizeof(a));
        memset(aa,0,sizeof(aa));
        memset(dp,0,sizeof(dp));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);

        scanf("%d",&m);
       

        for(int i=1;i<=n;i++)
            dp[i][i]=a[i];
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
			{	
			//	cout<<i<<" "<<j<<" ";
                dp[i][j]=dp[i][j-1]^a[j];//cout<<dp[i][j]<<endl;
			}

      

        for(int k=1;k<=m;k++)
        {
        	scanf("%d",&x);
        	int len=0;minn=1e9;
   			 for(int i=1;i<=n;i++)
        		for(int j=i;j<=n;j++)
        		{
            		int t=abs(x-dp[i][j]);
            	//cout<<i<<" "<<j<<" "<<abs(x-dp[i][j])<<" ";
		            if(t<=minn)
		            {
		                if(t==minn) len=max(len,j-i+1);
		                else len=j-i+1;
		                minn=t;
		            //    cout<<len<<" "<<minn<<" ";
		            }
            //cout<<endl;
        		}
        		cout<<len<<endl;
        }
        cout<<endl;
    }
    return 0;
}