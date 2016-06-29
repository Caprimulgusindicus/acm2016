#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int vis[10];
int main()
{
    int n;int m;
    int ans=0;
    scanf("%d%d",&n,&m);
    //cout<<7%7<<endl;
    for(int i=0;i<n;i++)
        {
            int flag=0;int ii=i;
            memset(vis,0,sizeof(vis));
            if(n>=7&&i<7) vis[0]++;
            else if(i==0) vis[0]++;
            //if(i==0) vis[0]++;
            else while(ii)
            {
                int x=ii%7;
                ii/=7;
                vis[x]++;
                cout<<x<<" x!";
                if(vis[x]>1) break;

            }
            for(int k=0;k<7;k++)
                if(vis[k]>1) flag=1;

            if(flag==1) continue;
            else
            for(int j=0;j<m;j++)
            {
               //if(j==0) vis[0]++;
               int jj=j;
                if(m>=7&&j<7) vis[0]++;
                else if(j==0) vis[0]++;
                else while(jj)
                {
                    int xx=jj%7;
                    jj/=7;
                    vis[xx]++;
                    cout<<xx<<endl;
                    if(vis[xx]>1) break;
                }

                for(int kk=0;kk<7;kk++)
                    if(vis[kk]>1) {flag=1;break;}
                if(!flag) cout<<i<<" "<<j<<" ",ans++;
            }
        }

        cout<<ans<<endl;

    return 0;
}
