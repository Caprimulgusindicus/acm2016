#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string.h>
#include <algorithm>
#define eps 1e-8
using namespace std;

struct point//dian
{
    double x;
    double y;
}p[20];

struct tra//sanjiaoxing
{
    double A;
    double B;
}tr[11111];

double pf(double a)
{
    return a*a;
}

double dis(point a,point b)
{
    return sqrt(pf(a.x-b.x)+pf(a.y-b.y));
}

bool  cj(point a,point b,point c)
{
    return (b.x-a.x)*(c.y-b.y)-(c.x-b.x)*(b.y-a.y);

}



bool judge(tra a,tra b)
{
   return (fabs(a.A-b.A)<=eps&&fabs(a.B-b.B)<=eps) ;// 妈个鸡 窝这里括号加错了
}


int main()
{
    int n;
    int mat[222][222];
    int vis[11111];
    while(~scanf("%d",&n)&&n)
    {
        int ans=0;
        memset(vis,0,sizeof(vis));
        memset(mat,0,sizeof(mat));//quchong
        for(int i=0;i<n;i++)
        {
          scanf("%lf%lf",&p[i].x,&p[i].y);
          if(mat[(int)p[i].x+2][(int)p[i].y+2])
          {
              i--;
              n--;
          }
          mat[(int)p[i].x+2][   (int)p[i].y+2]=1;
        }

      int num=0;
      double a[4];
      for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            for(int k=j+1;k<n;k++)//baoli
            {
                if(!cj(p[i],p[j],p[k])) continue;
                a[0]=dis(p[i],p[j]);
                a[1]=dis(p[i],p[k]);
                a[2]=dis(p[k],p[j]);
                sort(a,a+3);
                double aa=a[0];double bb=a[1];double cc=a[2];
                tr[num].A=(bb*bb+cc*cc-aa*aa)/bb/cc;
//double yuxian(double b,double c,double a)
//{
//    return (b*b+c*c-a*a)/b/c;
//}
                tr[num].B=(aa*aa+cc*cc-bb*bb)/aa/cc;//yuxian(aa,cc,bb);

                num++;
            }

        for(int i=0;i<num;i++)
        {
            if(vis[i]) continue;
            int t=1;
            for(int j=i+1;j<num;j++)
            {
                if(vis[j]) continue;
                if(judge(tr[i],tr[j]))
                {
                    t++;
                    vis[j]=1;
                }
            }
            if(t>ans)
                ans=t;
        }
        printf("%d\n",ans);
    }
    return 0;
}
