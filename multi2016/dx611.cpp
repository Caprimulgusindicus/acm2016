#include<stdio.h>
#include<string.h>
#include <string>
#include <iostream>
using namespace std;

const int N = 10008;
int s[108],t;
int sg[N];
bool hash[N];
void sg_solve(int *s,int t,int N)   //N求解范围 S[]数组是可以每次取的值，t是s的长度。
{
    int i,j;
    memset(sg,0,sizeof(sg));
    for(i=1;i<=N;i++)
    {
        memset(hash,0,sizeof(hash));
        for(j=0;j<t;j++)
            if(i - s[j] >= 0)
                hash[sg[i-s[j]]] = 1;
        for(j=0;j<=N;j++)
            if(!hash[j])
                break;
        sg[i] = j;
    }
}

int main()
{
    int i,j,n,m,h;
    while(scanf("%d",&t),t)
    {
        string ans="";
        for(i=0;i<t;i++)
            scanf("%d",&s[i]);
        sg_solve(s,t,N);
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&m);
            int res = 0;
            for(j=0;j<m;j++)
            {
                scanf("%d",&h);
                res ^= sg[h];
            }
            ans+=res?'W':'L';
        }
        cout<<ans<<endl;
    }
    return 0;
}
