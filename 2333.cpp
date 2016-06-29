#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
char a[11];
int x[88];

int main()
{
    while(gets(a))
    {
        int len=strlen(a);
        for(int i=0;i<len;i++)
       {
           memset(x,0,sizeof(x));
           int cou=0;
           int lala=a[i];
           int t=0;
           int ii=0;
           for(ii=0;lala!=0;ii++)
           {
               x[ii]=lala%2;
               lala/=2;
           }
           //cout<<ii<<endl;

           for(int k=ii-1;k!=(-1);k--)
             if(x[k]==1) cou++;
           if(cou%2!=0)
            x[7]=0;
           else x[7]=1;
           if(ii==6&&cou%2!=0) x[7]=0,ii++;
           else if(ii==6&&cou%2==0) x[7]=1,ii++;
           for(int k=ii;k!=(-1);k--)
            printf("%d",x[k]);
           cout<<endl;
       }
           // printf("%d",a[i]);
    }
    return 0;
}