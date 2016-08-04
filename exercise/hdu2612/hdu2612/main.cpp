#include <iostream>
#include <stdio.h>
#include <cstring>
#include <queue>
using namespace std;
char ma[222][222];
int vis[222][222];

struct point
{
    int x;
    int y;
};

int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        point start1,start2;
        getchar();
        for(int i=1;i<=n;i++)
        {    for(int j=1;j<=m;j++)
            {
                scanf("%c",&ma[i][j]);
                if(ma[i][j]=='Y') {start1.x=i;start1.y=j;}
                if(ma[i][j]=='M') {start2.x=i;start2.y=j;}
            }
            getchar();
        }
    
        
    }
    return 0;
}