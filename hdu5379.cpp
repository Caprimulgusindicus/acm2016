#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int f[222];//对于每个状态而言
int vis[222];//记录每个状态的后继状态
int sg[222];
int main()
{
    //memset(f,0,sizeof(f));
    f[0]=0;
    int i,j,k;
    for(i=1;i<=100;i++)
    {
        memset(vis,0,sizeof(vis));//i所有分成3堆的情况
        for(j=0;j<i;j++)
            vis[f[j]]=1;//i拿去任意个的所有后继状态

        for( j=1;j<i;j++){
            for(k=1;k<i-j;k++){
                vis[f[j]^f[k]^f[i-k-j]]=true;
            }
        }
        for(j=1;vis[j];j++);
        f[i]=j;//符合的最小非0
    }
    for(int i=0;i<=100;i++)
        cout<<i<<":"<<f[i]<<endl;

    return 0;
}
