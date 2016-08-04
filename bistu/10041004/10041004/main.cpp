#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
#define SIZE 1000005

int main()
{
    int n,a,b,c;
    while(scanf("%d%d%d%d",&n,&a,&b,&c)!=EOF)
    {
        int ans=a+c,sum=a+b+c;
        ans+=n/800;
        sum+=n/800;
        n%=800;
        int tmp=ans;
        for(int i=0; i<=b; i++)
        {
            int now=tmp;
            int nn=100*i+n;
            int add=nn/800;
            nn%=800;
            int db=b-i+nn/400;
            if(now+add>ans)
            {
                ans=now+add;
                sum=ans+db;
            }
            else if(now+add==ans&&ans+db>sum)
            {
                ans=now+add;
                sum=ans+db;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
