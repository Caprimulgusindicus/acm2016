#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int ans;
int n;
int nn;
int an[11];
int a[12][12];

int abs(int x)
{
	if(x>0) return x;
	else return -x;
}
int can(int x,int y)
{
	for(int i=1;i<=x;i++)
		for(int j=1;j<=n;j++)
			if((a[i][j]==1)&&(j==y||abs(x-i)==abs(y-j)))
				return 0;
	return 1;
}
void dfs(int i)
{
	if(i==n+1) ans++;
	for(int j=1;j<=n;j++)
	{
		if(can(i,j))
		{
			a[i][j]=1;
			dfs(i+1);
			a[i][j]=0;
		}
	}

}

int main()
{
		for(int k=1;k<=10;k++)
		{
			ans=0;
			n=k;
			memset(a,0,sizeof(a));
			dfs(1);
			an[k]=ans;
		}		
	while(~scanf("%d",&nn)&&nn)
	{
		printf("%d\n",an[nn]);
	}
	return 0;
}