#include<cstdio>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
int w[111111];
int f[111111];
int n;

int judge(int a,int b,int c)
{
    if(b<=c)    
        return b-a+1;
    if(a>c)     
        return 0;
    return c-a+1;
}

int solve(int a,int b,int c,int d,int K)
{
    int le=1,re=n;
    while(re>=le)
    {
        if(re-le<=1)
        {
            int me=le;
            int fm=judge(a,b,f[me])+judge(c,d,f[me]);
            if(fm>=K)return le;
            else return re;
        }
        int me=(le+re)/2;
        int fm=judge(a,b,f[me])+judge(c,d,f[me]);
        if(fm>=K)re=me;
        else le=me;
    }
}

int main()
{
    int T=1;
    scanf("%d",&T);
    while(T--)
    {
        
    int q;
    scanf("%d%d",&n,&q);
    
    for(int i=1;i<=n;i++)
       scanf("%d",&w[i]); 
    f[n]=n;
    for(int i=n-1;i>=1;i--)
    {
        if(w[i]==w[i+1])f[i]=f[i+1];
        else f[i]=i;
    }
    while(q--)
    {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);

        int tmp=b-a+1+d-c+1;
        LL ans=0;
        if(tmp&1)
            ans+=w[solve(a,b,c,d,(tmp+1)/2)]*2LL;
        else 
        {
            ans+=w[solve(a,b,c,d,tmp/2)]*2LL;
            ans+=w[solve(a,b,c,d,tmp/2+1)]*2LL;
            ans/=2;
        }

        if(ans<0)
            putchar('-'),ans=-ans;
        if(ans==0)
            cout<<"0.0\n";
        else if(ans%2==0)
            cout<<ans/2<<".0\n";
        else cout<<ans/2<<".5\n";
    }
    }
    return 0;
}