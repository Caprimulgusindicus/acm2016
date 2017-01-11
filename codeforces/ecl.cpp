#include <cstring>
#include <cstdio>
#include <iostream>
#include <queue>
#include <cmath>
int a[1111][1111];
using namespace std;
struct  point
{
	int x;
	int y;
	int v;
};

int pf(int x)
{
	return x*x;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++)
    { 
    	queue <point> q;
        memset(a,0,sizeof(a));
        int r,c;
        scanf("%d%d",&r,&c);
        printf("Case #%d: ",ca);
        int cnt=0;
        int x=0;int y=0;
        int c1i,c1j,c2i,c2j;
        int cou=0;
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
            {
                scanf("%d",&a[i][j]);
                if(cnt<2)
                {
                    if(a[i][j]!='?'&&cnt==0) cnt++,c1i=i,x=a[i][j],c1j=j;
                    if(a[i][j]!='?'&&cnt==1) cnt++,c2i=i,y=a[i][j],c2j=j;
                   
                }
                if(a[i][j]!='?') cou++; 
 				if(cou>=2)
 				{	
 					point aa;
                    aa.x=i,aa.y=j,aa.v=a[i][j];
                    q.push(aa);
				}
            }
        if(cou==0) puts("YES");
        else
        {
        	int flag=1;
	        int a=c2i-c1i;
	        int d1=(-(x+a-y)+sqrt(pf(x+a-y)-4*a*x))/(2*a);
	        int d2=(-(x+a-y)-sqrt(pf(x+a-y)-4*a*x))/(2*a);
	        if(d1<0||d2<0) {puts("NO");break;}
	        while(!q.empty())
	        {
	        	point jud=q.front();
	        	q.pop();
	        	if(jud.v!=((x+(jud.x-c1i)*d1)/d1*(d1+x))&&jud.v!=((x+(jud.x-c1i)*d2)/d2*(d2+x)))  {flag=0;puts("NO");break;}
	        }
	        if(flag) puts("YES"); 
    	}

        
    }
    return 0;
}