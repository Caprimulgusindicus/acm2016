#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=100;
int main()
{
	int winning[maxn][maxn];
	winning[1][1]=0;
	for(int n=1;n<5;n++)
	{
		for(int m=1;m<5;m++)
		{
			//int m=k-n;
			winning[n][m]=0;
			for(int i=1;i<n;i++)
				if(!winning[i][n-i]) winning[n][m]=1;
			for(int i=1;i<m;i++)
				if(!winning[i][m-1]) winning[n][m]=1;
			if(n<=m&&!winning[n][m]) printf("%d %d\n",m,n);
		}
	}

	return 0;
}