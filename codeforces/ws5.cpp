#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
int cnt;
struct node
{
    int x;
    int y;
    int v;
}a[111111];


bool judge()
{
    for(int i=1;i*i<=a[1].v;i++)
    {
        int flag=1;
        if(a[1].v%i==0)
        {
            if(i>=a[1].x&&a[1].v/i>=a[1].y)
            {
                for(int j=2;j<=cnt;j++)
                    if((i+a[j].x-a[1].x)*(a[1].v/i+a[j].y-a[1].y)!=a[j].v)  {flag=0;break;}
   
                if(flag) return true;
            }

            if(a[1].v/i>=a[1].x&&i>=a[1].y)
            {
                flag=1;
                for(int j=2;j<=cnt;j++)
                    if((a[1].v/i+a[j].x-a[1].x)*(i+a[j].y-a[1].y)!=a[j].v) {flag=0; break;}
               
                if(flag) return true;
            }
        }
    }
    return false;
}

int main()
{
    int T;
    int r,c;
    scanf("%d",&T);
    string s;
    for(int ca=1;ca<=T;ca++)
    {
    	cnt=0;
        scanf("%d%d",&r,&c);
        
        for(int i=1;i<=r;i++)
        {
            for(int j=1;j<=c;j++)
            {
                cin>>s;
                if(s!="?")
                {
                    int now=0;
                    for(int k=0;k<s.size();k++)  now=now*10+s[k]-'0';
                    cnt++;
                    a[cnt].x=i,a[cnt].y=j,a[cnt].v=now;
                }
            }
        }

        printf("Case #%d: ",ca);
        if(!cnt)
            puts("Yes");
        
        else if(cnt==1)
        {
            int flag=0;
            for(int i=1;i<=sqrt(a[1].v);i++)
            {
                if(a[1].v%i==0)
                {
                    if(i>=a[1].x&&a[1].v/i>=a[1].y) flag=1;
                    else if(i>=a[1].y&&a[1].v/i>=a[1].x) flag=1;
                }
            }
            if(flag) puts("Yes");
            else puts("No");
        }
        else
        {
            if(judge()) puts("Yes");
            else  puts("No");
        }
    }
    return 0;
}
