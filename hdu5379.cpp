#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int f[222];//����ÿ��״̬����
int vis[222];//��¼ÿ��״̬�ĺ��״̬
int sg[222];
int main()
{
    //memset(f,0,sizeof(f));
    f[0]=0;
    int i,j,k;
    for(i=1;i<=100;i++)
    {
        memset(vis,0,sizeof(vis));//i���зֳ�3�ѵ����
        for(j=0;j<i;j++)
            vis[f[j]]=1;//i��ȥ����������к��״̬

        for( j=1;j<i;j++){
            for(k=1;k<i-j;k++){
                vis[f[j]^f[k]^f[i-k-j]]=true;
            }
        }
        for(j=1;vis[j];j++);
        f[i]=j;//���ϵ���С��0
    }
    for(int i=0;i<=100;i++)
        cout<<i<<":"<<f[i]<<endl;

    return 0;
}
