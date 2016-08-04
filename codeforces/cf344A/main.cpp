#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
   int n;
   long long c;
   long long d;
        scanf("%d",&n);
        scanf("%I64d",&c);
       for(int i=2;i<=n;i++)
        {
            long long a=0;
            scanf("%I64d",&a);
             c|=a;

        }
        scanf("%I64d",&d);
       for(int i=2;i<=n;i++)
        {
            long long b=0;
            scanf("%I64d",&b);
            d|=b;
        }

    cout<<c+d<<endl;


    return 0;
}
