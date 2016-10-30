#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int a[111111];
int d[111111];
int _d[111111];
int vis[111111];
int m;
int judge(int x)
{
	memset(vis,0,sizeof(vis));
	for(int i=x;i>=1;i--)
	{
		_d[i]=d[i];
		if(!vis[_d[i]]) vis[_d[i]]=1;
		else _d[i]=0;//只考虑最后的考试时间，在规定时间内，能最后考则最后考
	}
	int t=0;int cnt=0;
	for(int i=1;i<=x;i++)
	{
		if(_d[i])//如果这天能考试
		{
			if(a[_d[i]]<=t) //如果考这门已经准备够了时间
				t-=a[_d[i]],cnt++;//把空闲时间减去某一门课所需要的准备时间（这是因为能断断续续复习）
			else return 0;//如果有某门课哪怕拖到最后，所需要的准备时间是不够的，那么返回0
		}
		else t++;//可用的准备天数++
	}
	if(cnt==m) return 1;
	else return 0;
}

int main()
{
	int n;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)//每天能考的是第几门
		scanf("%d",&d[i]);

	for(int i=1;i<=m;i++)//每科需要的复习时间
		scanf("%d",&a[i]);
	//sort(a+1,a+1+n);

	int left=1;
	int right=n+1;
	while(left<right)
	{
		int mid=(left+right)>>1;
		if(judge(mid))
		{
			right=mid;
		}
		else left=mid+1;
	}
	if(left>n) cout<<-1<<endl;
	else
	cout<<left<<endl;
	return 0;
}