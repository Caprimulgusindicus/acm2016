#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int par[1005];
int rank[1005];
int n, m, ans;

void INIT() {
    for(int i = 1; i <= n; i++) 
        par[i] = i,rank[i]=0;
}

//查询根节点 
int find(int x) {           
    return par[x] == x ? x : par[x] = find(par[x]);
}

//合并两个集合 
void unite(int x, int y) {
    x = find(x);
    y = find(y);
    //if(x == y) return;
    //ans--;
    
}

int main() {
    while(scanf("%d", &n), n) {
        scanf("%d", &m);
        ans = n - 1;
        INIT();
        for(int i = 0; i < m; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            unite(a, b);
        }
        for(int i=1;i<=n;i++)
        	cout<<par[i]<<endl;
    }
    return 0;
}