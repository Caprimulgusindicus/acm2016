#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
struct lala
{
    long long m;
    long long s;
};

lala f[100010];

int cmp(const lala &a,const lala &b)
{
        return a.m<b.m;

}

int main()
{
    //freopen("1.txt","r",stdin);
    long long  d,n;long long maxx=0;long long s=1;
    scanf("%I64d %I64d",&n,&d);

    for(int i=1;i<=n;i++)
        scanf("%I64d %I64d",&f[i].m,&f[i].s);
    f[0].m=0;f[0].s=0;

    sort(f+1,f+n+1,cmp);

    //尺取法开端
    for(int i=1;i<=n;i++)
        f[i].s+=f[i-1].s;
    maxx=f[1].s;
    //枚举上下界，下界优先，上界满足条件则取，不满足则让上界移动。同时对d值进行比较。
    for(int i=2;i<=n;i++)
    {
        while(f[i].m-f[s].m>=d && s<=i)
            s++;
        maxx=max(maxx,f[i].s-f[s-1].s);
    }
    cout<<maxx<<endl;
    return 0;
}
