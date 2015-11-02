#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

char str[555][2222];
int f[2222];
int len[2222];
int vis[2222];


void getfail(char s[])
{
    memset(f,0,sizeof(f));
    int temp=0;
    int len=strlen(s);
    for(int j=1;j<len;j++)
    {
        while(temp&&s[temp]!=s[j])
            temp=f[temp];
        if(s[temp]==s[j])
            temp++;
        f[j+1]=temp;
    }
}

int  match(char s[],char t[])
{
    int t1=0;
    getfail(t);
    int l1=strlen(s);
    int l2=strlen(t);
    for(int k=0;k<l1;k++)
    {

        while(t1&&s[k]!=t[t1])
            t1=f[t1];

        if(s[k]==t[t1]) t1++;
        if(t1==l2) return 1;
    }
    return 0;
}

int main()
{
    int t;
    scanf("%d", &t);
    for(int k=1;k<=t;k++)
    {
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%s",str[i]);

        memset(vis,0,sizeof(vis));
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            len[i]=strlen(str[i]);
            if(!i)  continue;

            for(int j=0;j<i;j++)
            {
                if(vis[j]==1) continue;
                int flag=match(str[i],str[j]);
                if(flag)  vis[j]=1;
                else ans =i+1;
            }
        }

        printf("Case #%d: ",k);
        cout<<ans<<endl;
    }
    return 0;
}
