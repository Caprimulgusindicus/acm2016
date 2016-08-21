#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int res[3000003];//记录一个数在第几轮
int ans[3000003];//记录这个轮次是否已经出现过
int rnk[3000003];//记录一个数是它所在轮次的第几个
int cnt[3000003];//去数每一轮有几个
//int final[3333333];//最终答案序列

struct N
{
	int val;
	int rnk;
}num[3000003];

bool cmp(N a1,N a2)
{
	return a1.rnk<a2.rnk;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(cnt,0,sizeof(cnt));
		int n,k,q;
		scanf("%d%d%d",&n,&k,&q);
		int maxround=1;
		res[0]=1;
		rnk[0]=0;
		cnt[1]=1;
		for(int i=1;i<n;i++)
		{
			//a[i]=i;
			//cout<<i<<endl;
			if(i%k==0) 
				{
					res[i]=1;
					rnk[i]=i; 
					//cout<<i<<" "<<vis[res[i]]<<endl;
					cnt[1]++;
					continue;
				}	

			int j=i-i/k-1;
			res[i]=res[j]+1;//当前这个数所在的轮次
			rnk[i]=rnk[j];
			cnt[res[i]]++;

			maxround=max(res[i],maxround);
		}
		
		for(int i=1;i<=maxround;i++)
			cnt[i]+=cnt[i-1];

		for(int i=0;i<n;i++)
			ans[cnt[res[i]-1]+rnk[i]/k+1]=i+1;
			
		
		for(int i=1;i<=q;i++)
		{
			int m;
			scanf("%d",&m);
			printf("%d\n",ans[m]);
		}
	}
	return 0;
}