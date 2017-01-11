#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int par[111111];
int cnt[111111];
int vis[111111];
int rk[111111];
int la[111111];
int k[111111];
int maxx=0;
int maxi=0;
int n;
void init()
{
	for(int i=1;i<=n;i++)
		par[i]=i;
}

int find(int x)
{
	return par[x]==x?x:par[x]=find(par[x]);
}

void unite(int x,int y)
{
	x=find(x);
	y=find(y);
	if(x==y) return;
	if(rk[x]>rk[y]) 
	par[y]=x;
    else
    {
		par[x]=y;
		if(rk[x]==rk[y]) rk[y]++;
    }
}

int main()
{
	int m,k;
	scanf("%d%d%d",&n,&m,&k);
	init();
	for(int i=1;i<=k;i++)
	{
		int t;
		scanf("%d",&t);
		vis[t]=1;//government
	}	
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		unite(a,b);
		k[a]++;k[b]++;
	}
	for(int i=1;i<=n;i++)
		la[far[i]]+=k[i];

	for(int i=1;i<=n;i++)
	{
		int num=par[i];
		cout<<i<<" "<<par[i]<<endl;
		cnt[num]++;
		cout<<num<<" "<<cnt[num]<<endl;
		if(cnt[num]>maxx) maxx=cnt[num],maxi=num;//找出联通最大的政府，确定是哪个政府
	}
	for(int i=1;i<=n;i++)
	{
		ll b=cnt[i];//点数
	}

	int ccnt=0;
	//算出对于连通数最多的政府，它可以连多少个点
	for(int i=1;i<=n;i++)
	{
		if(par[i]!=maxi&&vis[par[i]]!=0) //如果它不属于maxi的分支
		{
			//它连了其他政府
				continue;
			
		} 
		else ccnt++;
	}


	cout<<ccnt<<endl;cout<<maxi<<endl;
	long long ans=ccnt*(ccnt-1)/2;
	long long b=la[maxi];

	cout<<la[maxi]<<endl;
	ans-=b;
	cout<<ans<<endl;
	return 0;
}