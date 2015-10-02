#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100005];
int main()
{
    int ca;
    scanf("%d",&ca);
    for(int c=1;c<=ca;c++)
    {
        int n;int l;
        scanf("%d%d",&n,&l);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }

      //    for(int i=1;i<=n;i++)
      //  {
      //      printf("%d ",a[i]);
      //  }
      int Ans=0;
      int ans=0;
      for(int i=2;i<=n;i++)
        if(a[i]<a[i-1])
        {
            ans++;
            Ans=max(Ans,ans);
        }
      else ans=0;
        cout<<Ans+1<<endl;

    }
}
