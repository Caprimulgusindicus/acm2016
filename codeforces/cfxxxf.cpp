#include <iostream>
#include <cstdio>
using namespace std;
typedef long long LL; 
const double eps = 1e-10;
const long long linf =1LL<<60;

long long a,b;

int fd(double d)
{
    return d<-eps?-1:d>eps;
}

long long bin(long long l,long long r)
{
    long long res=-1;
    long long mid;
    double x;
    while (l<=r)
    {
      mid=(l+r)>>1;
      x=(a+b)*1.0/(2*mid);
    
      if (fd(x-b)>=0) 
      {
        l=mid+1;
        res=mid;
      }
      else
        r=mid-1;
    }
    return res;
}

int main()
{

  scanf("%I64d%I64d",&a,&b);
  long long k = bin(1LL,linf);
  if (a<b) cout<<-1<<endl;
  else
    printf("%.12f\n",(a+b)*1.0/(2.0*k));
    
    return 0;
}