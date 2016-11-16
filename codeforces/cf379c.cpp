#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
long long a[111111];
long long b[111111];
long long c[111111];
long long d[111111];

int main()
{
	long long n,m,k;
	long long ttt=1e11;
	scanf("%lld%lld%lld",&n,&m,&k);//n potion,m first type, k second type
	long long s=0,x=0;
	scanf("%lld%lld",&x,&s);//initial spend tim, can use
	for(int i=1;i<=m;i++)
		scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++)
	{	scanf("%lld",&b[i]);ttt=min(ttt,b[i]);}
	for(int i=1;i<=k;i++)//get immediatly
		scanf("%lld",&c[i]);
	for(int i=1;i<=k;i++)
		scanf("%lld",&d[i]);
	if(s<d[1]&&s<ttt) 			{printf("%lld\n",n*x);return 0;}

	else if(s<d[1])//不能用第二种
	{
		int flag1=0;
		long long ans=1<<21;
		for(int j=1;j<=m;j++)
			{
				long long temps=s;
				if(s<b[j]) continue;//尝试下一个
				temps-=b[j];
				long long tim=n*a[j];
				ans=min(ans,tim);
			}
		if(ans==1<<21)//什么都没用
			printf("%lld\n",n*x);
		else printf("%lld\n",ans);
		return 0;
	}
	else
	{
		int flag=0;
		long long t;
		long long ans=1<<21;
		for(int i=1;i<=k;i++)
		{
			long long tim=0;
			t=n;
			long long tmps=s;
			if(d[i]>s) //第二种不再可用
			{
				flag=2;break;
				
			}
		
			else
			{
				tmps-=d[i];
				t-=c[i];//number
				//cout<<t<<" :"<<tmps<<" ";
				if(t==0) {flag=1;break;}//need no tim
				for(int j=1;j<=m;j++)
				{
					long long ttmps=tmps;
					ttmps-=b[j];//cout<<b[j]<<" "<<ttmps<<" ";
					if(ttmps<0) tim=t*x;//第一种不可用
					else tim=t*a[j];
					//cout<<tim<<endl;
					ans=min(ans,tim);

				}
			}
		}
		if(flag==2)
		{
			for(int j=1;j<=m;j++)
				{
					long long tmps=s;
					long long tim=0;
					tmps-=b[j];
					if(tmps<0) tim=n*x;//第一种不可用
					else tim=t*a[j];
					ans=min(ans,tim);

				}
		}

		for(int i=1;i<=m;i++)//先做第一种
		{
			long long tim=0;
			t=n;
			long long tmps=s;
		
		
				tmps-=b[i];
				if(tmps<0) continue;
				//t-=c[i];//number
				//cout<<t<<" :"<<tmps<<" ";
				//if(t==0) {flag=1;break;}//need no tim
				for(int j=1;j<=k;j++)
				{
					//t-=c[j];
					long long ttmps=tmps;
					ttmps-=d[j];//cout<<b[j]<<" "<<ttmps<<" ";
					if(ttmps<0) tim=t*a[i];//第2种不可用
					else tim=(t-c[j])*a[i];
					//cout<<tim<<endl;
					ans=min(ans,tim);
					if(ttmps<0) break;
				}
			
		}

		

		if(flag==1) printf("0"\n);//cout<<"0"<<endl;
		else if(ans==1<<21)//什么都没用
			printf("%lld\n",n*x);
		else printf("%lld\n",ans);

	}
	return 0;
}