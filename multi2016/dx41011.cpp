#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int a[111111];
int vis[111111];


int main()
{
    int T;
    scanf("%d",&T);
    for(int tt=1;tt<=T;tt++)
    {
        
        int n;
        int cnt=0;
        scanf("%d",&n);
        if(n<=0) continue;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            vis[a[i]]=0;
        }    

        int flag=1;
        int lastpos=1;int lasttmp=1;
        for(int i=1;i<n;i++)
        {
            
            for(int j=i+1;j<=n;j++)
                {
                    if(a[i]>a[j])
                    {
                        cnt++;
                        vis[a[i]]++;
                        vis[a[j]]++;
                    }    
                }
        }
        
        printf("Case #%d: ",tt);
        if(n==1||cnt==0)
        printf("0\n");
        else for(int i=1;i<=n;i++)
        {
            if(i!=n) printf("%d ",vis[i]);
            else printf("%d\n",vis[i]);
            
        }
            
        
    }

    return 0;
}