#include<cstring>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
struct P
{
    int x,y;
}
an[105],tr[105];

int n,a[105];

int sqr(int x)
{
    return x*x;
}

double dis(P a,P b)
{
    return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}

bool cross(P a1,P a2,P b1,P b2)
{
    if(dis(a1,a2)+dis(b1,b2)>dis(a1,b2)+dis(b1,a2)) return true;
    return false;
}

int main()
{
    int i,j;
    bool flag;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&an[i].x,&an[i].y);
        a[i]=i;
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&tr[i].x,&tr[i].y);
    }

    while(1)
    {
        flag=1;
        for(i=1;i<=n;i++)
         {
            for(j=1;j<=n;j++)
                if(i!=j)
                {
                    if(cross(an[i],tr[a[i]],an[j],tr[a[j]]))
                    {
                        swap(a[i],a[j]);
                        flag=0;
                    }
                }
        }
        if(flag) break;
    }

    for(i=1;i<=n;i++)
    {
        printf("%d\n",a[i]);
    }
}
