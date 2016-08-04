#include<iostream>
#include<stdio.h>
#include<cmath>
#include<string.h>
#define INF 100000005
using namespace std;

double d[1111][1111];
double mat[1111][1111];
int vis[1111];
int lowcost[1111];
int lala[1111];
int t;
int n;

struct point
{
    double x;
    double y;
    int p;
}p[1111];

double pf(double a)
{
    return a*a;
}

double dis(point a,point b)
{
    return sqrt(pf(a.x-b.x)+pf(a.y-b.y));
}

void prim()
{

        double B=0;
        double A=0;
        vis[1]=1;lala[1]=-1;
        for(int i=1;i<n;i++)
        {
            int mid=INF;
            int k=-1;
            for(int j=1;j<=n;j++)
            {
                if(lala[j]!=-1&&lowcost[j]<mid)
                {
                    mid=lowcost[j];
                    k=j;
                }
            }
            int pre;
            if(k!=-1)
            {
                pre=lala[k];
                B+=d[k][lala[k]];
                mat[lala[k]][k]=mat[k][lala[k]]=d[k][lala[k]];
                lala[k]=-1;
                for(int j=1;j<=n;j++)
                {
                    if(lala[j]!=-1&&d[k][j]<lowcost[j])
                    {
                        lowcost[j]=d[k][j];
                        lala[j]=k;
                    }
                }
            }
            for(int j=1;j<=n;j++)//存下最小生成树
            {
                if(lala[j] ==-1&&j!=k)
                {
                    mat[j][k]=mat[k][j]=max(mat[j][pre], mat[pre][k]);
                }
            }
        }

        double ans=0;
        for(int i=1;i<=n;i++) //删边加点权
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j) continue;
                A=p[i].p+ p[j].p;
                ans=max(ans,A/(B-mat[i][j]));
            }
        }
        printf("%.2f\n", ans);
}

int main()
{

    scanf("%d",&t);
    while(t--)
    {
        memset(d,0,sizeof(d));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%lf%lf%d",&p[i].x,&p[i].y,&p[i].p);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
          {
               d[i][j]=d[j][i]=dis(p[i],p[j]);
               //cout<<d[i][j]<<endl;
               mat[i][j]=0;
          }
          memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            lowcost[i]=d[1][i];
            lala[i]=1;
        }
        prim();
    }
    return 0;
}
