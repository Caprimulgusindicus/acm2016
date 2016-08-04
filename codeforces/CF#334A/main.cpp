#include <iostream>
#include <stdio.h>
using namespace std;
double  m1,m2,m3,m4,m5;
//500 1000 1500 2000 2500
int main()
{
   while(~scanf("%lf%lf%lf%lf%lf",&m1,&m2,&m3,&m4,&m5))
   {
       double w1,w2,w3,w4,w5=0;
       int a,b=0;
       double sum=0;

       scanf("%lf%lf%lf%lf%lf",&w1,&w2,&w3,&w4,&w5);
       scanf("%d%d",&a,&b);

      // cout<<m1<<m2<<m3<<m4<<m5<<w1<<w2<<w3<<w4<<w5<<a<<b<<sum<<endl;
       // cout<<(1-m1/250)*500-50*w1<<endl;
       sum+=max(0.3*500,(1-m1/250)*500-50*w1);
       //cout<<sum<<endl;
       sum+=max(0.3*1000,(1-m2/250)*1000-50*w2);
       //cout<<sum<<endl;
       sum+=max(0.3*1500,(1-m3/250)*1500-50*w3);
       //cout<<sum<<endl;
       sum+=max(0.3*2000,(1-m4/250)*2000-50*w4);
       //cout<<sum<<endl;
        sum+=max(0.3*2500,(1-m5/250)*2500-50*w5);
       // cout<<sum<<endl;
         sum+=a*100;
       sum-=b*50;
       //cout<<sum<<endl;
       printf("%d\n",int(sum));
   }
    return 0;
}
