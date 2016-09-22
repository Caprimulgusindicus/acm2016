#include <cstdio>
#include <iostream>
using namespace std;
int x[2333][2333];
int y[2333][2333];
void init()
{
	
	for(int i=0;i<=9;i++)
	{
		if(i&1) y[1][i]=1;
		else  x[1][i]=1;
	}
	for(int i=1;i<=19;i++)
		for(int j=0;j<=9;j++)
			if(j&1)
			{
				for(int k=1;k<=9;k+=2)
					y[i+1][k]+=x[i][j];
				for(int k=0;k<=8;k+=2)
					x[i+1][k]+=x[i][j];
				for(int k=1;k<=9;k+=2)
					x[i+1][k]+=y[i][j];
			}
			else 
			{
				for(int k=1;k<=9;k+=2)
					y[i+1][k]+=x[i][j];
				for(int k=0;k<=9;k+=2)
					y[i+1][k]+=x[i][j];
				for(int k=0;k<=9;k+=2)
					x[i+1][k]+=y[i][j];
			}
}
int main()
{
	int T;
	long long begin,end;
	scanf("%d",&T);
	for(int ca=1;ca<=T;ca++)
	{
			scanf("%lld%lld",&begin,&end);
			int k1=x[1][begin]+y[1][begin];
			int k2=x[1][end]+y[1][end];
			cout<<k2-k1<<endl;
	}

	return 0;
}