#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int ans[111111];
int a[11111];
int _a[11111][11111];
int fin[11111][11111];
int main()
{
	int T;
	scanf("%d",&T);
	for(int ca=1;ca<=T;ca++)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			int j=1;
			int len=0;
			scanf("%d",&a[i]);
			while(a[i])
			{
				_a[i][j++]=a[i]&1;
				a[i]/=2;
				len++;
			}
			for(int j=1;j<=len;j++)
				fin[i][len-j+1]=_a[i][j];
			
			for(int j=1;j<=len;j++)
				cout<<fin[i][j]<<" ";
			cout<<endl;
		}
	}/*
	int a;
	a=2;
	int len=0;
	int c[20];
	memset(c,0,sizeof(c));
	int i=1;
	while(a)
	{
		c[i++]=a&1;
		a/=2;
		len++;
	}
	int fin[22];
	cout<<len<<endl;
	for(int i=1;i<=len;i++)
		fin[len-i+1]=c[i];//cout<<c[i]<<endl;
	for(int i=1;i<=len;i++)
		cout<<fin[i]<<endl;*/
	return 0;
}