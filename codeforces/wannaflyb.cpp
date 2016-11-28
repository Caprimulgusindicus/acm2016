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
		//char need1,need2;
		ll dir1=sx-ex;ll dir2=sy-ey;
		ll t1=0;ll t2=0;
		
		scanf("%s",s);
		ll ans=-1;
		
			for(int i=0;i<n;i++)
			{
				if(s[i]=='E'&&dir1<0) dir1++;
				if(s[i]=='W'&&dir1>0) dir1--;
				if(s[i]=='N'&&dir2<0) dir2++;
				if(s[i]=='S'&&dir2>0) dir2--;
				if(dir1==0&&dir2==0) {ans=i+1;break;}
			}
			cout<<ans<<endl;
			//else cout<<-1<<endl;
		}
		
	return 0;
}