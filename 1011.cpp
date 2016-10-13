#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#define fur(i,a,b) for(int i=(a);i<=(b);i++)
#define furr(i,a,b) for(int i=(a);i>=(b);i--)
#define cl(a) memset((a),0,sizeof(a))

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
const int inf=0x3f3f3f3f;
const double eps=1e-8;
const int mod=1000000007;
const double pi=acos(-1.0);
inline void gn(long long&x){
    int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');c=='-'?(sg=-1,x=0):(x=c-'0');
    while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';x*=sg;
}
inline void gn(int&x){long long t;gn(t);x=t;}
inline void gn(unsigned long long&x){long long t;gn(t);x=t;}
ll gcd(ll a,ll b){return a? gcd(b%a,a):b;}
ll powmod(ll a,ll x,ll mod){ll t=1ll;while(x){if(x&1)t=t*a%mod;a=a*a%mod;x>>=1;}return t;}

const int maxn = 1111;
struct Edge{
	int from;
	int to;
	int cost;
}edge[11111*2];
vector<int>E[maxn];
vector<int>pre[maxn];
bool in[1111];
int n,m,cnt;



void addEdge(int f, int t, int c)
{
	cnt++;edge[cnt].from = f;edge[cnt].to = t;edge[cnt].cost=c;E[f].push_back(cnt);
}

void bfs(){
	int dis[1111];
	fur(i,2,n) dis[i]=2222,in[i]=false;
	dis[1]=0;in[1]=true;
	queue<int>q;q.push(1);
	int now;
	while(!q.empty()){
		now = q.front();
		//dbg(now);
		in[now]=false;
		q.pop();
		int sz = E[now].size();
		for(int i = 0; i < sz; ++i){
			int nxt = edge[E[now][i]].to;
			if(dis[now]+1 == dis[nxt]){
				pre[nxt].push_back(E[now][i]);
				if(!in[nxt]){
					in[nxt]=true;
					q.push(nxt);
				}
			}else if(dis[now]+1 < dis[nxt]){
				dis[nxt]=dis[now]+1;
				pre[nxt].clear();
				pre[nxt].push_back(E[now][i]);
				if(!in[nxt]){
					in[nxt]=true;
					q.push(nxt);
				}
			}
		}
	}
}


typedef int flowt;
namespace flow {
	const int M=22222,N=2222;
	int y[M],nxt[M],gap[N],fst[N],c[N],pre[N],q[N],dis[N];
	flowt f[M];
	int S,T,tot,Tn;
	void init(int s,int t,int tn) {//从s到t 共tn个点 
		tot=1; assert(tn<N);
		fur(i,0,tn) fst[i]=0;
		S=s;T=t;Tn=tn;
	}
	void add(int u,int v,flowt c1,flowt c2=0) {
		tot++;y[tot]=v;f[tot]=c1;nxt[tot]=fst[u];fst[u]=tot;
		tot++;y[tot]=u;f[tot]=c2;nxt[tot]=fst[v];fst[v]=tot;
	}
	flowt sap() {				//最大流 
		int u=S,t=1;flowt flow=0;
		for(int i = 0;i <= Tn; ++i) c[i]=fst[i],dis[i]=Tn,gap[i]=0;
		q[0]=T;dis[T]=0;pre[S]=0;
		for(int i = 0; i <= t; ++i) {
			int u=q[i];
			for (int j=fst[u];j;j=nxt[j]) if (dis[y[j]]>dis[u]+1&&f[j^1]) 
				q[t++]=y[j],dis[y[j]]=dis[u]+1;
		}
		for(int i = 0; i <= Tn; ++i) gap[dis[i]]++;
		while (dis[S]<=Tn) {
			while (c[u]&&(!f[c[u]]||dis[y[c[u]]]+1!=dis[u])) c[u]=nxt[c[u]];
			if (c[u]) {
				pre[y[c[u]]]=c[u]^1;
				u=y[c[u]];
				if (u==T) {
					flowt minf=inf;
					for (int p=pre[T];p;p=pre[y[p]]) minf=min(minf,f[p^1]);
					for (int p=pre[T];p;p=pre[y[p]]) f[p^1]-=minf,f[p]+=minf;
					flow+=minf;u=S;
				}
			} else {
				if (!(--gap[dis[u]])) break;
				int mind=Tn;
				c[u]=fst[u];
				for (int j=fst[u];j;j=nxt[j]) if (f[j]&&dis[y[j]]<mind) 
					mind=dis[y[j]],c[u]=j;
				dis[u]=mind+1;
				gap[dis[u]]++;
				if (u!=S) u=y[pre[u]];
			}
		}
		return flow;
	}
};

void bfs2(){
	flow::init(1,n,n);
	fur(i,1,n)in[i]=false;
	in[n]=true;
	queue<int>q;q.push(n);
	while(!q.empty()){
		int now = q.front();
		q.pop();in[now]=false;
		int sz = pre[now].size();
		for(int i = 0; i < sz; ++i){
			int pr = edge[pre[now][i]].from;
			flow::add(pr,now,edge[pre[now][i]].cost);
			if(!in[pr]){
				q.push(pr);
				in[pr]=true;
			}
		}
	}
//	fur(i,1,n) if(!)
}




int main(){

	int T,a,b,c;
	gn(T);
	while(T--){
		gn(n);gn(m);
		fur(i,1,n)
		{
			E[i].clear();
			pre[i].clear();
		}
	cnt=0;
		fur(i,1,m){
			gn(a);gn(b);gn(c);
			addEdge(a,b,c);
			addEdge(b,a,c);
		}
		bfs();
		bfs2();
		printf("%d\n",flow::sap());
	}


	return 0;
}

