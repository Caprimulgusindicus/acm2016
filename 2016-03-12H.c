#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
bool zero(double x)
{
    if(fabs(x)<=eps)
        return true;
    return false;
}
int sign(double x)
{
    if(zero(x))
        return 0;
    if(x>0)
        return 1;
    return -1;
}
struct point3
{
    double x,y,z;
    point3() {}
    point3(double xx,double yy,double zz)
    {
        x=xx;
        y=yy;
        z=zz;
    }
};
struct line3
{
    point3 a,b;
};
struct plane3
{
    point3 a,b,c;
};
//计算 cross product U x V
point3 xmult(point3 u,point3 v)
{
    point3 ret;
    ret.x=u.y*v.z-v.y*u.z;
    ret.y=u.z*v.x-u.x*v.z;
    ret.z=u.x*v.y-u.y*v.x;
    return ret;
}
//计算 dot product U . V
double dmult(point3 u,point3 v)
{
    return u.x*v.x+u.y*v.y+u.z*v.z;
}
//矢量差 U - V
point3 subt(point3 u,point3 v)
{
    point3 ret;
    ret.x=u.x-v.x;
    ret.y=u.y-v.y;
    ret.z=u.z-v.z;
    return ret;
}
//取平面法向量
point3 pvec(plane3 s)
{
    return xmult(subt(s.a,s.b),subt(s.b,s.c));
}
point3 pvec(point3 s1,point3 s2,point3 s3)
{
    return xmult(subt(s1,s2),subt(s2,s3));
}
//两点距离,单参数取向量大小
double dist(point3 p1,point3 p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y)+(p1.z-p2.z)*(p1.z-p2.z));
}
//向量大小
double vlen(point3 p)
{
    return sqrt(p.x*p.x+p.y*p.y+p.z*p.z);
}
double num[5][5];
point3 rot(double x,double y,double z,double d,point3 p)
{
    double l=sqrt(x*x+y*y+z*z);
    x/=l;
    y/=l;
    z/=l;
    num[0][0]=x*x+(1.0-x*x)*cos(d);
    num[0][1]=x*y*(1.0-cos(d))-z*sin(d);
    num[0][2]=x*z*(1.0-cos(d))+y*sin(d);
    num[1][0]=x*y*(1.0-cos(d))+z*sin(d);
    num[1][1]=y*y+(1.0-y*y)*cos(d);
    num[1][2]=y*z*(1.0-cos(d))-x*sin(d);
    num[2][0]=x*z*(1.0-cos(d))-y*sin(d);
    num[2][1]=y*z*(1.0-cos(d))+x*sin(d);
    num[2][2]=z*z+(1.0-z*z)*cos(d);
    num[3][3]=1.0;
    point3 ans;
    ans.x=num[0][0]*p.x+num[0][1]*p.y+num[0][2]*p.z;
    ans.y=num[1][0]*p.x+num[1][1]*p.y+num[1][2]*p.z;
    ans.z=num[2][0]*p.x+num[2][1]*p.y+num[2][2]*p.z;
    return ans;
}
//两直线夹角 cos 值
double angle_cos(point3 u1,point3 u2,point3 v1,point3 v2)
{
    return dmult(subt(u1,u2),subt(v1,v2))/vlen(subt(u1,u2))/vlen(subt(v1,v2));
}

struct point
{
    double x,y;
    double tht;
    point() {}
    point(double xx,double yy)
    {
        x=xx;
        y=yy;
    }
    void output()
    {
        printf("(%f,%f)\n",x,y);
    }
    void input()
    {
        scanf("%lf%lf",&x,&y);
    }
    point operator -(const point &b)
    {
        return point(x - b.x, y - b.y);
    }
    point operator +(const point &b)
    {
        return point(x + b.x, y + b.y);
    }
    double operator ^(const point &b)
    {
        return x*b.y - y*b.x;
    }
    double operator *(const point &b)
    {
        return x*b.x + y*b.y;
    }
};
//两点距离
double dist(point p1,point p2)
{
    return sqrt((p1-p1)*(p1-p2));
}
//两点距离平方
double dist2(point p1,point p2)
{
    return (p1-p2)*(p1-p2);
}
bool cmp1(point a,point b)
{
    if(zero(a.y-b.y))
        return a.x+eps<b.x;
    return a.y+eps<b.y;
}
point ttt;
bool cmp2(point a,point b)
{
    if(zero(a.tht-b.tht))
        return dist2(ttt,a)+eps<dist2(ttt,b);
    return a.tht+eps<b.tht;
}
point tubao[55];
int tbnum;
void gettubao(vector <point> p)
{
    int siz=p.size();
    memset(tubao,0,sizeof(tubao));
    sort(p.begin(),p.end(),cmp1);
    for(int i=1; i<siz; i++)
        p[i].tht=atan2(p[i].y-p[0].y,p[i].x-p[0].x);
    ttt=p[0];
    sort(++p.begin(),p.end(),cmp2);
    if(siz==1)
    {
        tbnum=1;
        tubao[0]=p[0];
        return ;
    }
    else if(siz==2)
    {
        tbnum=2;
        tubao[0]=p[0];
        tubao[1]=p[1];
        return ;
    }
    tbnum=2;
    tubao[0]=p[0];
    tubao[1]=p[1];
    for(int i=2; i<siz; i++)
    {
        while(tbnum>1)
        {
            if(((tubao[tbnum-1]-tubao[tbnum-2])^(p[i]-tubao[tbnum-2]))<=eps)
            {
                tbnum--;
            }
            else
                break;
        }
        tubao[tbnum++]=p[i];
    }
}
point3 p3[55];
point3 np[55];
int n;
double ptoplane(point3 p,point3 s1,point3 s2,point3 s3)
{
    return fabs(dmult(pvec(s1,s2,s3),subt(p,s1)))/vlen(pvec(s1,s2,s3));
}
int main()
{
    while(scanf("%d",&n),n)
    {
        double H=0.0,S=1e9;
        for(int i=0; i<n; i++)
        {
            scanf("%lf%lf%lf",&p3[i].x,&p3[i].y,&p3[i].z);
        }
        for(int i=0; i<n; i++)for(int j=i+1; j<n; j++)for(int k=j+1; k<n; k++)
                {
                    int flag1=0,flag2=0;
                    point3 fxl=pvec(p3[i],p3[j],p3[k]);
                    for(int t=0; t<n; t++)
                    {
                        if(t==i||t==j||t==k)
                            continue;
                        double costht=angle_cos(point3(0.0,0.0,0.0),fxl,p3[i],p3[t]);
                        if(sign(costht)==1)
                            flag1|=1;
                        if(sign(costht)==-1)
                            flag2|=1;
                        if(flag1&&flag2)
                            break;
                    }
                    if(flag1&&flag2)
                        continue;
                    if(zero(fxl.x)&&zero(fxl.y))
                    {
                        for(int t=0;t<n;t++)
                        {
                            np[t]=p3[t];
                        }
                    }
                    else
                    {
                        point3 xzz=pvec(point3(0.0,0.0,0.0),fxl,point3(0.0,0.0,1.0));
                        double xztht=acos(angle_cos(point3(0.0,0.0,0.0),fxl,point3(0.0,0.0,0.0),point3(0.0,0.0,1.0)));
                        for(int t=0; t<n; t++)
                        {
                            np[t]=rot(xzz.x,xzz.y,xzz.z,xztht,p3[t]);
                        }
                    }
                    double nh=0.0,ns=0.0;
                    for(int t=0; t<n; t++)
                        nh=max(nh,ptoplane(np[t],np[i],np[j],np[k]));
                    vector <point>vec;
                    for(int t=0; t<n; t++)
                        vec.push_back(point(np[t].x,np[t].y));
                    gettubao(vec);
                    for(int i=1; i<tbnum; i++)
                        ns=ns+((tubao[i]-tubao[0])^(tubao[(i+1)%tbnum]-tubao[0]));
                    ns=fabs(ns);
                    if(sign(nh-H)==1)
                    {
                        H=nh;
                        S=ns;
                    }
                    else if(sign(nh-H)==0&&sign(ns-S)==-1)
                    {
                        H=nh;
                        S=ns;
                    }
                }
        printf("%.3f %.3f\n",H,S/2.0);
    }
    return 0;
}
