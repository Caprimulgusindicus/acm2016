#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int main()
{
    int n,k;
    int a[111111],b[111111];
    char s[111111];
    scanf("%d %d",&n,&k);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    scanf(" %s",s);
    
    int cnta=1,cntb=1;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='a') a[cnta++]=i;
        if(s[i]=='b') b[cntb++]=i;
    }
    
    int ans1=b[k+1];
    int ans2=a[k+1];
    
    b[cntb]=n;
    a[cnta]=n;
    for(int i=k+2;i<=cntb;i++)
    {
        int tmp=b[i]-1-b[i-(k+1)];
        ans1=max(ans1,tmp);
    }
    
    
    for(int i=k+2;i<=cnta;i++)
    {
        int tmp=a[i]-1-a[i-(k+1)];
        ans2=max(ans2,tmp);
    }
    
    if((cnta-1)<=k||(cntb-1)<=k)
        cout<<n<<endl;
    else cout<<max(ans1,ans2)<<endl;
    
    return 0;
}