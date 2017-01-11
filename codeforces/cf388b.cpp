#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
struct point
{
	int x,y;
};

int main()
{
	point a,b,d;
	point c1,c2,c3;
	scanf("%d%d",&a.x,&a.y);
	scanf("%d%d",&b.x,&b.y);
	scanf("%d%d",&d.x,&d.y);
	
		c1.x=b.x+d.x-a.x,c1.y=b.y+d.y-a.y;
		c2.x=a.x+d.x-b.x,c2.y=a.y+d.y-b.y;
		c3.x=a.x+b.x-d.x,c3.y=a.y+b.y-d.y;
	cout<<3<<endl;
	cout<<c1.x<<" "<<c1.y<<endl;
	cout<<c2.x<<" "<<c2.y<<endl;
	cout<<c3.x<<" "<<c3.y<<endl;

	return 0;
}