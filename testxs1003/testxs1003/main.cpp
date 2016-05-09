#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
struct Point
{
    double x, y;
};

struct line
{
    double x1,y1,x2,y2;
}l[1111];

bool between(double a, double X0, double X1)
{
    double temp1= a-X0;
    double temp2= a-X1;
    if ( ( temp1<1e-8 && temp2>-1e-8 ) || ( temp2<1e-6 && temp1>-1e-8 ) )
    {
        return true;
    }
    else
    {
        return false;
    }
}

double determinant(double v1, double v2, double v3, double v4)  // ––&#161;–&#160;Ω
{
        return (v1*v4-v2*v3);
}

bool intersect3(Point aa, Point bb, Point cc, Point dd)
{
        double delta = determinant(bb.x-aa.x, cc.x-dd.x, bb.y-aa.y, cc.y-dd.y);
        if ( delta<=(1e-6) && delta>=-(1e-6) )  // delta=0￡¨±ì&#160;&#230;&#161;Ω&#339;&#64258;&#8706;&#338;÷&#255;∫&#339;aú&#8710;Ω––
            {
                    return false;
                }
        double namenda = determinant(cc.x-aa.x, cc.x-dd.x, cc.y-aa.y, cc.y-dd.y) / delta;
        if ( namenda>1 || namenda<0 )
            {
                    return false;
                }
        double miu = determinant(bb.x-aa.x, cc.x-aa.x, bb.y-aa.y, cc.y-aa.y) / delta;
        if ( miu>1 || miu<0 )
            {
                    return false;
                }
        return true;
}


int main()
{
    //freopen("1003.txt","r",stdin);
    //freopen("1003out.txt","w",stdout);
    int n;
    while(~scanf("%d",&n))
    {
        memset(l,0,sizeof(l));
        
        int ans=0;
        for(int i=1;i<=n;i++)
            scanf("%lf%lf%lf%lf",&l[i].x1,&l[i].y1,&l[i].x2,&l[i].y2);
        for(int i=1;i<=n;i++)
            for(int j=2;j<=n;j++)
            {
                if(i==j) continue;
                Point p1, p2, p3, p4;
                p1.x = l[i].x1;
                p1.y = l[i].y1;
                p2.x = l[i].x2;
                p2.y = l[i].y2;
                p3.x = l[j].x1;
                p3.y = l[j].y1;
                p4.x = l[j].x2;
                p4.y = l[j].y2;
                
                
                //    int i=0, j=0;
                bool flag = 0;
                flag = intersect3(p1, p2, p3, p4);
                
                if(flag==1) {ans++;break;}
                //cout<<flag<<endl;
            }
        cout<<ans<<endl;
    }
    
    return 0;
}
