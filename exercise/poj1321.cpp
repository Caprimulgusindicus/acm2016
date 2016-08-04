#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
int vis[11];
char ma[11][11];
int main()
{
	int n,k;
	while(~scanf("%d%d",&n,&k))
	{
		getchar();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;i++)
				scanf("%c",&ma[i][j]);
			getchar();
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cout<<ma[i][j];

	}
	return 0;
}