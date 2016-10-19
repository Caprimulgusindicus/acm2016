#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,k,b;
int a[100010];
int flag[100010];
void init()
{
    for(int i=0;i<=n;i++)
    {
        flag[i]=0;
    }
    for(int i=1; i<=n; i++)
    {
        if(!flag[i])
        {
            int m=a[i];
            int num=1;
            while(m!=i)
            {
                m=a[m];
                num++;
            }
            flag[m]=num;
            for(int j=0;j<num;j++)
            {
                m=a[m];
                flag[m]=num;
            }
        }
    }
}
int main()
{
    scanf("%d %d",&n,&k);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&b);
        scanf("%d",&a[b]);
    }
    init();
    for(int i=1; i<=k; i++)
    {
        int loc,t;
        scanf("%d %d",&loc,&t);
        if(flag[loc]!=1&&t%flag[loc]>=1)
        {
            int m=a[loc];
            for(int j=0; j<t%flag[loc]-1; j++)
                m=a[m];
            printf("%d\n",m);
        }
        else
            printf("%d\n",loc);
    }
    return 0;
}