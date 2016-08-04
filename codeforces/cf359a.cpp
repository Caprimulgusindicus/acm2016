#include <iostream>
#include <stdio.h>
using namespace std;
int n;long long x;int num=0;
int main()
{
    scanf("%d%I64d",&n,&x);
    for(int i=1;i<=n;i++)
    {
        getchar();
        char c;
        int tmp;
        scanf("%c%d",&c,&tmp);
        if(c=='+') x+=tmp;
        else if(c=='-')
        {
            if(x>=tmp) x-=tmp;
            else num++;
        }

    }
    printf("%I64d %d",x,num);

    return 0;
}
