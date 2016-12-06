#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int cas;
    scanf("%d",&cas);
    for(int c=1;c<=cas;c++)
    {
        double ans=0;
        int n,b,q;
        scanf("%d%d%d",&n,&b,&q);
        if(q==10||q==100||q==1000)
        {
            if (b==n||b/10==n||b/100==n||b/1000==n||b*10==n||b*100==n||b*1000==n) 
				ans=1; 
	        else ans=0;

        }
        else if(q==1) 
      		{
      			if (b==n||b/10==n||b/100==n||b/1000==n)  ans=1;
        		else	ans=0;
        	}
        else ans=log10((double)(n+1)/double(n));

        printf("Case #%d: %.5lf\n",c,ans);
    }
    return 0;
}