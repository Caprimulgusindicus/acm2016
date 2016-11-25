#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
typedef long long ll;
//Bishop moves any number of cells diagonally, 
//Rook moves any number of cells horizontally or vertically, 
//Queen is able to move any number of cells horizontally, vertically or diagonally, 
using namespace std;
ll f(ll x) {return x*x;}

ll dis(ll x,ll y,ll x0,ll y0)
{
	return sqrt(f(x-x0)+f(y-y0));
}

int main()
{
	int n;
	scanf("%d",&n);
	ll x0,y0;
	scanf("%lld%lld",&x0,&y0);
	ll min_up=1e18;
	ll min_down=1e18;
	ll min_mainup=1e18;
	ll min_viceup=1e18;
	ll min_maindwon=1e18;
	ll min_vicedown=1e18;
	ll min_left=1e18;
	ll min_right=1e18;
	char minup='0';
	char mindown='0';
	char minleft='0';
	char minritht='0';
	char minmainup='0';
	char minmaindown='0';
	char minviceup='0';
	char minvicedown='0';
	for(int i=1;i<=n;i++)
	{
		getchar();
		char c;
		scanf("%c",&c);
		ll x,y;
		scanf("%lld%lld",&x,&y);
		if(x==x0 && y>y0 && (y-y0)<min_up) minup=c,min_up=y-y0;
		if(x==x0 && y<y0 && (y0-y)<min_down) mindown=c,min_down=y0-y;
		if(y==y0 && x>x0 && (x-x0)<min_right) minritht=c,min_right=x-x0;
		if(y==y0 && x<x0 && (x0-x)<min_left) minleft=c,min_left=x0-x;
		if(abs(x-x0)==abs(y-y0) && x>x0 && y>y0 && dis(x,y,x0,y0)<min_mainup)        minmainup=c,min_mainup=dis(x,y,x0,y0);
		if(abs(x-x0)==abs(y-y0) && x<x0 && y<y0 && dis(x,y,x0,y0)<min_maindwon)      minmaindown=c,min_maindwon=dis(x,y,x0,y0);
		if(abs(x-x0)==abs(y-y0) && x<x0 && y>y0 && dis(x,y,x0,y0)<min_viceup)        minviceup=c,min_viceup=dis(x,y,x0,y0);
		if(abs(x-x0)==abs(y-y0) && x>x0 && y<y0 && dis(x,y,x0,y0)<min_vicedown)      minvicedown=c,min_vicedown=dis(x,y,x0,y0);

	}
	if(minup=='R'||minup=='Q'||mindown=='R'||mindown=='Q'||minleft=='R'||
		minritht=='Q'||minleft=='Q'||minritht=='R'
		||minmainup=='Q'||minmainup=='B'||minmaindown=='Q'||minmaindown=='B'
		||minviceup=='Q'||minviceup=='B'||minvicedown=='Q'||minvicedown=='B')
		puts("YES");
	else puts("NO");

	return 0;
}