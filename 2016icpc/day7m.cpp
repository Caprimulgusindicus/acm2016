//#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <queue>
#include <sstream>
#include <map>
#include <bitset>
#include <ctime>
#define INF 0x3f3f3f3f
#define EPS 1e-10
#define PI acos(-1.0)
#define LL long long
#define ULL unsigned long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define MP make_pair
#define sf(x) scanf("%d",&x)
#define sqr(x) ((x)*(x))
template <class T>
inline void rd(T &x) { char c = getchar(); x = 0;while(!isdigit(c)) c = getchar();
while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }}
#define IN freopen("in.txt","r",stdin);
#define OUT freopen("out.txt","w",stdout);
#define X first
#define Y second
using namespace std;
const int N= 22;
const int M= 22;
int a[N],b[N][N],c[N];
int na,ma,nb,mb,tag;
int f[N][N];
void sol(int x)
{
    int nx=x,tot=0;
    while (nx)
    {
        tot+=nx&1;
        nx>>=1;
    }  
    if (tot!=ma) return;
    memset(c,0,sizeof(c));
    rep(i,1,nb+1)
        rep(j,0,mb)
        if ((1<<j)&x)
        c[i]=(c[i]<<1)|b[i][j];
    // // rep(i,1,na+1)
    // // cout<<a[i]<<endl;
    // puts("");
    // rep(i,1,nb+1)
    // cout<<c[i]<<endl;
    memset(f,0,sizeof(f));
    rep(i,1,nb+1)
        rep(j,1,na+1)
        {
            if (c[i]==a[j]) f[i][j]=f[i-1][j-1]+1;
            else f[i][j]=max(f[i-1][j],f[i][j-1]);
        }
    //cout<<f[nb][na]<<endl;
    if (f[nb][na]==na) tag=1;

}
int main()
{
    scanf("%d%d",&na,&ma);
    int x;
    rep(i,1,na+1)
        rep(j,0,ma)
        {
            scanf("%1d",&x);
            a[i]=(a[i]<<1)|x;
        }
    scanf("%d%d",&nb,&mb);
    rep(i,1,nb+1)  
        rep(j,0,mb)
            scanf("%1d",&b[i][j]);
    int big=1<<mb;
    tag=0;
    rep(i,0,big)
    {
        if (tag) break;
        sol(i);
    }
    if (tag) puts("Yes");
    else puts("No");
}
