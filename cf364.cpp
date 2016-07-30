//a
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
struct num
{
    int val;
    int pos;
};

int cmp(num a1,num a2)
{
    return a1.val<a2.val;
}

int main()
{
    while(~scanf("%d",&n))
    {
        num a[1111];
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i].val);
            sum+=a[i].val;
            a[i].pos=i;
        }
        int pai=sum/2;
        sort(a+1,a+1+n,cmp);
        //for(int i=1;i<=n;i++)
        //    cout<<a[i].val<<endl;
        for(int i=1;i<=n/2;i++)
        {
            int la=n-i+1;
            printf("%d %d\n",a[i].pos,a[la].pos);
        }
    }
    return 0;
}
