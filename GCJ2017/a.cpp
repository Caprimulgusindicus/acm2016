#include <cstring>
#include <cstdio>
#include <string>
#include <string.h>
#include <iostream>
using namespace std;
char s[1111];
int f[1111];
int ff[1111];
int len;
int cal(int k)
{
    memset(ff,0,sizeof(ff));
    int res=0;
    int sum=0;
    for(int i=0;i+k<=len;i++)
    {
        if((f[i]+sum)%2!=0)
            {res++;ff[i]=1;}
        sum+=ff[i];
        if(i-k+1>=0) sum-=ff[i-k+1];
    }

    for(int i=len-k+1;i<len;i++)
    {
        if((f[i]+sum)%2!=0) return -1;
        if(i-k+1>=0) sum-=ff[i-k+1];
    }
    return res;
}

int main()
{
    freopen("alarge.in","r",stdin);
    freopen("outlargea.txt","w",stdout);
    int cas;
    scanf("%d",&cas);

    getchar();
    for(int ca=1;ca<=cas;ca++)
    {
        memset(s,0,sizeof(s));
        scanf("%s",s);
        //cout<<s<<endl;
        int k;
        scanf("%d",&k);
        len=strlen(s);
        for(int i=0;i<len;i++)
            if(s[i]=='+') f[i]=0;
            else f[i]=1;
        
        int ans=cal(k);
       
         //   cout<<ans<<endl;
        if(ans==-1)     printf("Case #%d: IMPOSSIBLE\n",ca);

        else printf("Case #%d: %d\n",ca,ans);
    }
    return 0;
}