#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
  int n,m,k;
  int ma[5005][5005];
  int r[5555];int c[5555];int a[5555];int b[5555];
int main()
{

  while(~scanf("%d%d%d",&n,&m,&k))
  {
      memset(ma,0,sizeof(ma));
      int o=0;int x=0;int y=0;
      for(int i=1;i<=k;i++)
      {
          scanf("%d%d%d",&o,&x,&y);
          if(o==1)
          {
              r[x]=y,a[x]=i;
          }
          else
          {
              c[x]=y,b[x]=i;
          }
      }
      for(int i=1;i<=n;i++)
      {
           for(int j=1;j<=m;j++)
                if(a[i]>b[j])
                    printf("%d ",r[i]);
                else printf("%d ",c[j]);
            puts("");
      }

  }
    return 0;
}

