#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int a[50015];
int temp[50];
double ans[3];
int main()
{
    temp[0]=1;
    for(int i=1;i<31;i++)
            temp[i]=temp[i-1]*2;
    int ca;
    scanf("%d",&ca);
    for(int c=1;c<=ca;c++)
    {


        memset(ans,0,sizeof(ans));

        int n;
        double cnt;
        double t;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);


        //AND
        for(int i=0;i<33;i++)
        {
            cnt=0;
            t=0;
            for(int j=1;j<=n;j++)
            {
                if(a[j]&temp[i])
                {
                    cnt++;
                    t+=cnt;
                }
                else cnt=0;
            }
            ans[0]+=t*temp[i];
        }
        ans[0]=2*ans[0]/n/(n+1);

        //OR
        for(int i=0;i<33;i++)
        {
            cnt=0;
            t=0;
            for(int j=1;j<=n;j++)
            {
                if(a[j]&temp[i])
                {
                    t+=j;
                    cnt=j;
                }
                else t+=cnt;
            }
            ans[1]+=t*temp[i];
        }
        ans[1]=2*ans[1]/n/(n+1);

        //XOR
        for(int i=0;i<31;i++)
        {
            cnt=0;
            t=0;
            for(int j=1;j<=n;j++)
            {
                if(a[j]&temp[i])
                {
                    t+=j-cnt;
                    cnt=j-cnt;

                }
                else t+=cnt;
            }
            ans[2]+=t*temp[i];
        }
        ans[2]=2*ans[2]/n/(n+1);
        printf("Case #%d: %lf %lf %lf\n", c, ans[0], ans[1], ans[2]);
    }
    return 0;
}

