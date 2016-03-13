#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    while(~scanf("%d%d%d%d",&sx,&sy,&ex,&ey),sx,sy,ex,ey)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            if(x1>x2)
                swap(x1,x2);
            if(y1>y2)
                swap(y1,y2);


        }
    }
    return 0;
}
