#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=1111111;
const int maxm=1111111;
int f[maxn];
int sum[maxn];
int dp[maxn];
int t,n,m,tol;
int cnt1,cnt2;

struct Edge
{
	int u,v,w;
}edge[maxn];

struct point
{
	int v,len;
};

vector <point> vet[n];

void addedge(int u,int v,int w)
{
	edge[tol].u=u;
	edge[tol].v=v;
	edge[tol++].w=w;
}

bool cmp(Edge a,Edge b)
{
	return a.w<b.w;
}
int find(int x)
{
	if(f[x]==-1) return x;
	else return f[x]=find(x);
}

int Kruskal()
{
	memset(f,-1,sizeof(f));
	sort(edge,edge+tol,cmp);
	int cnt=0;
	int ans=0;
	for(int i=0;i<tol;i++)
	{
		int u=edge[i].u;
		int v=edge[i].v;
		int w=edge[i].w;
		int t1=find(u);
		int t2=find(v);
		if(t1!=t2)
		{
			ans+=w;
			f[t1]=t2;
			cnt++;
		}
		if(cnt==n-1) break;
	}	
	vet[edge[i].u]=point(edge[i].v,w);
	vet[edge[i].v]=point(edge[i].u,w);
	
	vet[edge[i].u][cnt1].v=v;
	vet[edge[i].v][cnt2].u=u;
	vet[edge[i].v][cnt1].w=vet[edge[i].u][cnt2].w=w;
	cnt1++;cnt2++;
	if(cnt<n-1) return -1;
	else return ans;
}

void dfs(int root,int father)
{
	sum[root]=1;

}
int main()
{
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++)
	{
		cnt1=0;cnt2=0;
		scanf("%d%d",&n,&m);
		tol=m;
		for(int i=1;i<=m;i++)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			addedge(u,v,w);
		}
		int ans=Kruskal();
		dfs(0,1);
		cout<<ans<<endl;
	}
	return 0;
}