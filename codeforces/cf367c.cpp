#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<ll,int> pli;
const int maxn=2e5+5;
const ll INF=1LL<<59;
int head[maxn],tot,val[maxn];
string st[maxn];
ll d[maxn];

void init()
{
    memset(head,-1,sizeof(head));
    tot=0;
}

struct edge
{
    int to,next,w;
} G[maxn<<2];


void addedge(int u,int v,int w)
{
    G[tot].to=v;
    G[tot].next=head[u];
    G[tot].w=w;
    head[u]=tot++;
}

ll dijkstra(int s,int t)
{
    priority_queue<pli,vector<pli>,greater<pli> > pque;
    fill(d,d+t+1,INF);
    d[s]=0;
    pque.push(pli(d[s],s));
    while(!pque.empty())
    {
        pli p=pque.top();
        pque.pop();
        int u=p.second;
        if(d[u] != p.first) continue;
        for(int i=head[u];~i;i=G[i].next)
        {
            edge e=G[i];
            if(d[e.to] > d[u]+e.w)
            {
                d[e.to]=d[u]+e.w;
                pque.push(pli(d[e.to],e.to));
            }
        }
    }
    return d[t];
}

int main()
{
    init();
    int n;
    cin>>n;
    int s=0,t=n<<1|1;
    for(int i=1;i<=n;++i) cin>>val[i];
    addedge(s,1,0);
    addedge(s,1+n,val[1]);
    addedge(n,t,0);
    addedge(n+n,t,0);
    for(int i=1;i<=n;++i)
    {
        cin>>st[i];
        int j=i+n;
        st[j]=st[i];
        reverse(st[j].begin(),st[j].end());
        if(i > 1)
        {
            int k=i-1+n;
            if(st[i-1]<=st[i]) addedge(i-1,i,0);
            if(st[i-1]<=st[j]) addedge(i-1,j,val[i]);
            if(st[k]<=st[i]) addedge(k,i,0);
            if(st[k]<=st[j]) addedge(k,j,val[i]);
        }
    }
    ll ans=dijkstra(s,t);
    if(ans<INF) cout<<ans<<endl;
    else cout<<"-1"<<endl;
    return 0;