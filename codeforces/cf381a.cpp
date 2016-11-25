#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
	ll n,a,b,c;
	scanf("%lld%lld%lld%lld",&n,&a,&b,&c);
	ll rest=0;
	ll ans=1e18;
	/*(n%4==1) rest=3;//3 7 11 15 
	else if(n%4==2) rest =2;//2 6 10 14
	else if(n%4==3) rest=1;//5 9 13 17
	else if(n%4==0) rest=0;
	if(rest==3) {ans=min(a*3,a*1+b*2);ans=min(ans,c*1);ans=min(2*c+a,ans);ans=min(3*b+a,ans);}
	if(rest==2) {ans=min(b*1,a*2);ans=min(ans,c*2);ans=min(ans,b*3);ans=min(ans,a+b+c);}
	if(rest==1) {ans=min(a*1,b+c);ans=min(2*b+a,ans);ans=min(ans,c*3);}
	if(rest==0) ans=0;//1 2 3
*/
	for(int i=0;i<=100;i++)
		for(int j=0;j<=100;j++)
			for(int k=0;k<=100;k++)
				if((n+i*1+j*2+k*3)%4==0) ans=min(a*i+b*j+k*c,ans);
	cout<<ans<<endl;

	return 0;
}