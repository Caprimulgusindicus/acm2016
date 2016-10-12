#include<string.h>
#include<stdio.h>
#include<math.h> 
int main() 
{ 
   int f[30],i,a,n;
   f[1]=f[2]=f[3]=0;
   f[4]=f[5]=1;
   for(i=6;i<=20;i++)
   {
       if(i==5||i==8||i==13)
         f[i]=f[i-1];
         else
         f[i]=f[i-1]+1;
   }
   while(~scanf("%d",&a)){
  
   printf("Case #%d: %d\n",i,f[a]);
}
    return 0; 
} 