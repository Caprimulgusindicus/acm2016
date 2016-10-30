#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
long long s[222];
long long e[222];
int cnt;
int cross(int l,int r)
{
	for(int j=1;j<=cnt;j++)//跟之前的安排对
		if(!(l>e[j]||r<s[j])) return 0;
	return 1;
}
int main()
{
	int n;
	cnt=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		long long d;
		scanf("%lld%lld",&s[i],&d);//开始时间和duration
		e[i]=s[i]+d-1;//结束时间
		
		if(cross(s[i],e[i]))//如果有交集
			s[++cnt]=s[i],e[cnt]=e[i];
		else
			for(int j=0;j<=cnt;j++)
				if(cross(e[j]+1,e[j]+d))
				{
					s[++cnt]=e[j]+1;e[cnt]=e[j]+d;
					break;
				}
		cout<<s[i]<<" "<<e[i]<<endl;
		for(int j=1;j<cnt;j++)//每加入一个，对已经存在的排一次序
			for(int k=j+1;k<=cnt;k++)
				if(s[j]>s[k]) swap(s[j],s[k]),swap(e[j],e[k]);
	}	

	return 0;
}

