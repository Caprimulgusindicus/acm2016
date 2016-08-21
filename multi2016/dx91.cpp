#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,k;
long long l,t[222],pay[222],pro[222];
queue <int> iindex[222];
int maxday[222];
int vis[222];//一个工厂是否需要建造
int planted[222];//一个工厂是否已经建造
long long day=0;


struct plant
{
	int pay;
	int t;
	int i;
};
int cmp(plant p1,plant p2)
{
	return p1.t<p2.t;
}
plant p[222];

int main()
{
	int T;
	scanf("%d",&T);
	for(int ca=1;ca<=T;ca++)
	{
		for(int i=0;i<=222;i++)
		while(!iindex[i].empty()) iindex[i].pop();
		//加一堆memset
		memset(t,0,sizeof(t));
		memset(vis,0,sizeof(vis));
		memset(maxday,0,sizeof(maxday));
		memset(planted,0,sizeof(planted));
		memset(pro,0,sizeof(pro));
		memset(pay,0,sizeof(pay));
		long long sum=0;
		scanf("%d%d%lld",&n,&m,&l);

		for(int i=1;i<=n;i++)//工厂所需要的时间和金钱
			scanf("%d%d",&p[i].pay,&p[i].t),p[i].i=i;

		for(int i=1;i<=m;i++)//商店能赚的钱
		{
			scanf("%lld%d",&pro[i],&k);//每个商店可获得的利润
			for(int j=1;j<=k;j++)
			{	
					int a;
					scanf("%d",&a);
					vis[a]++;//第a个工厂需要被建造
					iindex[i].push(a);//第i个商店所需要的所有工厂
			}
		}
		//cout<<"ddd"<<endl;
		long long tmp=0;
		long long earn=0;
		sort(p+1,p+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			if(vis[p[i].i]!=0) planted[p[i].i]=1;//如果还有商店需要这个工厂，建造它
			tmp=p[p[i].i].pay; //花钱建厂
			
			for(int j=1;j<=m;j++)
			{
				int flag=0;//当前商店是否可以盈利
				while(!iindex[j].empty())
				{
					int inde=iindex[j].front();//对第j个商店，取出它所需要的
					if(!planted[inde]) {flag=1;break;}
					iindex[j].pop();
				}
				if(!flag) //如果当前商店盈利
					earn+=pro[j];	
			}
			vis[p[i].i]--;
			//if(!vis[p[i].i]&&earn<tmp) sum=sum;
			//else  
				sum=sum+earn-tmp;
			day=p[p[i].i].t;
			if(sum>=l) break;
		}

		if(sum<l) printf("Case #%d: impossible\n",ca);
		else
			printf("Case #%d: %lld %lld\n",ca,day,sum);
	}
	return 0;
}