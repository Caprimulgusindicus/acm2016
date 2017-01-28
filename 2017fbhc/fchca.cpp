#include <cstdio>
#include <iostream>
#include <cmath>
#include <math.h>
#include <algorithm>
using namespace std;
struct vec
{
	int x;int y;
};
int pf(int x)
{return x*x;}
int dist(int x,int y)
{
	if(pf(x-50)+pf(y-50)>50*50) return 1;
	else return 0;
}
double get(double x1, double y1, double x2, double y2)
{
    const double epsilon = 1.0e-6;
    const double nyPI = acos(-1.0);
    double dist, dot, degree, angle;

 // normalize
    dist = sqrt( x1 * x1 + y1 * y1 );
    x1 /= dist;
    y1 /= dist;
    dist = sqrt( x2 * x2 + y2 * y2 );
    x2 /= dist;
    y2 /= dist;
// dot product
    dot = x1 * x2 + y1 * y2;
    if ( fabs(dot-1.0) <= epsilon )
    angle = 0.0;
    else if ( fabs(dot+1.0) <= epsilon )
    angle = nyPI;
    else {
        double cross;

        angle = acos(dot);
  //cross product
        cross = x1 * y2 - x2 * y1;
  // vector p2 is clockwise from vector p1
  // with respect to the origin (0.0)
        if (cross < 0 ) {
            angle = 2 * nyPI - angle;
        }
    }
    degree = angle *  180.0 / nyPI;
    return degree;
}

int main()
{
	int t;
	//int n;
		freopen("ina.txt","r",stdin);
	freopen("outa.txt","w",stdout);
	scanf("%d",&t);
	for(int ca=1;ca<=t;ca++)
	{

		int p,x,y;
		scanf("%d%d%d",&p,&x,&y);
		cout<<"Case #"<<ca<<": ";

		if(dist(x,y)) puts("white");
		else
		{
			vec a;
			a.x=0,a.y=50;
			vec b;
			b.x=x-50,b.y=y-50;
			double k=get(b.x,b.y,a.x,a.y);
			//double kk=atan(b.x,b.y);
			//double an1=atan2(a.y,a.x);
			//cout<<an1<<endl;
			//double an2=atan2(b.y,b.x);
			//double aaan=an1-an2;
			//cout<<aaan<<" "<<aaan*180.0/acos(-1.0)<<endl;
			//cout<<"k: "<<k;
			double pers=k/360.0*100.0;
			//cout<<"pers: " <<pers<<endl;
			if(pers>p) puts("white");
			else puts("black");
			//<<cnt<<endl;
		}
	}
}