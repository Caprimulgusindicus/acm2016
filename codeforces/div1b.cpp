#include <cstdio>
#include <iostream>
using namespace std;

int s[111111];

int main()
{
   int a,b,c,d,i;
   int z,o;

   scanf("%d%d%d%d",&a,&b,&c,&d);
   
   if(a==0 && b==0 && c==0 && d==0)
   {
      printf("0\n");
      return 0;
   }

   if(a==0)
   {
      if(b==0 && c==0) z=0;
      else z=1;
   }
   else z=sqrt(a*2)+1;

   
   if(d==0)
   {
      if(b==0 && c==0) o=0;
      else o=1;
   }
   else o=sqrt(d*2)+1;

   if(z*(z-1) != a*2 || o*(o-1) != d*2 || z*o != (b+c))
   {
      printf("Impossible\n");
      return 0;
   }

   for(i=0;i<z;i++)
   {
      if(b>o)
      {
         b-=o;
         s[i]=o;
      }
      else s[i]=b, b=0;
   }

   for(i=0;i<z;i++)
   {
      while(s[i]<o)
      {
         o--;
         printf("1");
      }
      printf("0");
   }
   while(o)
   {
      o--;
      printf("1");
   }

   cout<<endl;

   return 0;
}