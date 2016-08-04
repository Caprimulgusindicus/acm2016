#include <iostream>
#include <stdio.h>
#include  <algorithm>
using namespace std;
struct day
{
    int need;
    int price;
};
day a[111111];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int ans=0;
        for(int i=1;i<=n;i++)
            scanf("%d%d",&a[i].need,&a[i].price);
        int minn=a[1].price;
        for(int i=1;i<=n;i++)
        {
            if(a[i].price<minn)
                minn=a[i].price;
            ans+=a[i].need*minn;
        }
        cout<<ans<<endl;
    }
    return 0;
}
