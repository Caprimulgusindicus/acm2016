#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int flag=1;
        for(int i=1;i<=n;i++)
        {
            int x,y;
            scanf("%d",&x);
            y=(int)sqrt(x);
            if (x!=y*y)
                flag=0;

        }
        if(!flag) printf("No\n");
            else printf("Yes\n");
    }
    return 0;
}
