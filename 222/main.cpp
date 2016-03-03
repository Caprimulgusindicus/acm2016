#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
  int n,m,k;
  int ma[5005][5005];
int main()
{

  while(~scanf("%d%d%d",&n,&m,&k))
  {
      memset(ma,0,sizeof(ma));
      int o=0;int r=0;int a=0;
      for(int i=1;i<=k;i++)
      {
          scanf("%d%d%d",&o,&r,&a);
          if(o==1)
          {
              for(int i=1;i<=m;i++)
                ma[r][i]=a;
          }
          else
          {
              for(int i=1;i<=n;i++)
                ma[i][r]=a;
          }
      }
      for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
      {
           {

               if(j==m)
                printf("%d",ma[i][j]);
                else
                    printf("%d ",ma[i][j]);
            }
            if(j==m) puts("");
      }

  }
    return 0;
}
