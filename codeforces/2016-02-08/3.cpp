#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    long long a,b,c,sum;
    while(~scanf("%I64d%I64d%I64d%I64d",&sum,&a,&b,&c))
   {

        long long ans=0;
      if(sum>=b&&b-c<=a)
      {
          ans+=(sum-b)/(b-c)+1;
          sum-=ans*(b-c);
      }
      ans+=sum/a;
       printf("%I64d\n",ans);
  }
  return 0;
}
