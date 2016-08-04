#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
int ans;int n;

bool solve(int a,int y)
{
    long long q=y/a;
    long long  sum=a;
    long long temp=a;
    while(1)
    {
        temp=temp*q;
        sum+=temp;
        if(sum==n) return 1;if(sum>n) return 0;
    }

}
int main()
{
    //int n;
    while(~scanf("%d",&n))
    {
        ans=0;
        for(int i=1;i<=n;i++)
            if(n%i==0)
                for(int q=i;q<=n;q+=i)
                    if(solve(i,q)) ans++;
        printf("%d\n",ans);
    }
}
