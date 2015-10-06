#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;
int a[11111],b[11111];
int main()
{
    int n,k,num,x;
    while(~scanf("%d%d",&n,&k))
    {
        memset(b,0,sizeof(b));
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&a[i],&num);
            for(int j=0;j<num;j++)
            {
                scanf("%d",&x);
                b[i]|=(1<<x);//状态压缩
            }
        }
        int q;
        scanf("%d",&q);
        while(q--)
        {
            int id=0;
            int cur=0;
            int ran=1;
            scanf("%d%d",&id,&num);
            id--;
            for(int i=0;i<num;i++)
            {
                scanf("%d",&x);
                cur|=(1<<x);//对所查询的特性进行状态压缩
            }
            for(int i=0;i<n;i++)
            {
                if((b[i]&cur)==(b[id]&cur)&&a[i]>a[id])
                    ran++;
            }
            cout<<ran<<endl;
        }
    }
    return 0;
}
