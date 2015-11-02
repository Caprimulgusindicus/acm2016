#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>
using namespace std;
char aa[200005];
int main()
{
    int n;int m;
    while(~scanf("%d %d",&n,&m))
    {

        getchar();
        gets(aa);
        char ex[27];
        for(int i=0;i<26;i++)
                {ex[i]=97+i;}
        //cout<<aa<<endl;
        int vis[27];
        for(int i=1;i<=m;i++)
        {
            memset(vis,0,sizeof(vis));
            char from;
            char to;
            scanf("%c %c",&from,&to);
            getchar();
            int flag=0;
            for(int i=0;i<=26;i++)
            {
                if(ex[i]==from) {ex[i]=to;vis[i]=1;}
                if(ex[i]==to&&!vis[i]) {ex[i]=from;}
            }

        }
        //for(int i=0;i<27;i++)
        //    cout<<ex[i]<<endl;
            for(int i=0;i<n;i++)
                {
                    aa[i]=ex[aa[i]-97];
                }


        cout<<aa<<endl;
    }
    return 0;
}
