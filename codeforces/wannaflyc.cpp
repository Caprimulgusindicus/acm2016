#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
char s[111111];
int main()
{
	int n;
	ll sx,sy,ex,ey;
	while(~scanf("%d%lld%lld%lld%lld",&n,&sx,&sy,&ex,&ey))
	{
		getchar();
		char need1,need2;
		ll dir1=ex-sx;ll dir2=ey-sy;
		ll t1=0;ll t2=0;
		ll cnt1=abs(dir1);ll cnt2=abs(dir2);
		if(dir1>0) need1='E';
		else need1='W';
		if(dir2>0) need2='N';
		else need2='S';
		scanf("%s",s);
		ll ans=0;
		if(dir1==0&&dir2==0) cout<<0<<endl;
		else
		{
			for(int i=0;i<n;i++)
			{
				if(s[i]=='E'&&need1=='E') t1++;
				if(s[i]=='W'&&need1=='W') t1++;
				if(s[i]=='N'&&need2=='N') t2++;
				if(s[i]=='S'&&need2=='S') t2++;
				if(t1==cnt1&&t2==cnt2) {ans=i+1;break;}
			}
			if(t1==cnt1&&t2==cnt2) cout<<ans<<endl;
			else cout<<-1<<endl;
		}
		
	}
	return 0;
}