#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
//int r[1111],o[1111],y[1111],g[1111],b[1111],v[1111];
int a[7];
int main()
{
	freopen("bs.in","r",stdin);
	freopen("bs.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++)
	{
		//cout<<cas<<endl;
		int n;//,r,o,y,g,b,v;
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		//scanf("%d%d%d%d%d%d%d",&n,&r,&o,&y,&g,&b,&v);
		for(int i=0;i<6;i++)
			scanf("%d",&a[i]);
		char c[7]="ROYGBV";
		string ans;
		while(n)
		{
			for(int i=0;i<6;i++)
				if(a[i]>0) ans+=c[i],n--,a[i]--;
			//,cout<<a[i]<<" "<<i<<endl;
		}
		int flag=0;
		int len=ans.length();
		for(int i=1;i<ans.length();i++)
			if(ans[i]==ans[i-1]) flag=1;
		if(ans[0]==ans[len-1]&&len!=1) flag=1;
		printf("Case #%d: ",cas);
		if(flag||!ans.length()) cout<<"IMPOSSIBLE"<<endl;
		else cout<<ans<<endl;
	}
	return 0;	
}