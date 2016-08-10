#include <iostream>
#include <stdio.h>
using namespace std;
int num[333333];
int vis[333333];
int shunxu[333333];


int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	int cnt=0;//未读
	int now=0;//总数
	int time=1;
	for(int i=1;i<=q;i++)
	{
		int op;int x;
		scanf("%d%d",&op,&x);
		if(op==1)//x +1 noti
		{
			num[x]++;
			cnt++;//new ones 
			shunxu[now++]=x;//第now个消息是x类型
		}
		if(op==2) //clear x
		{
			vis[x]=now;//把清一个数组时的时间记下来
			cnt-=num[x]; //left to be read
			num[x]=0; 
		}
		if(op==3) //t first be read
		{
			while(time<=x)
			{
				if(vis[vis[x]]<time)	
				{
					num[vis[x]]--;
					cnt--;
				}
			}
		}
		printf("%d\n",cnt);

	}
	return 0;
}