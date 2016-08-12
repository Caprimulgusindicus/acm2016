#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int a[2222];
int b[2222];
int num1[1111];
int num2[1111];
int vis[2222];
int vv[2222];

int cmp(int a,int b)
{
	return a<b;
}

int abs(int x)
{
	if(x>0) return x;
	else return -x;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		memset(vv,0,sizeof(vv));
		memset(vis,0,sizeof(vis));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(num1,0,sizeof(num1));
		memset(num2,0,sizeof(num2));
		int n,m;
		int cnt1=0;int cnt2=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			num1[a[i]]++;
			cnt1++;
		}
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&b[i]);
			num2[b[i]]++;
			cnt2++;
		}	
		
		for(int i=1;i<=n;i++)
		{
			int minn=23333;
			for(int j=1;j<=n;j++)
			{
				if(a[i]==b[j]&&!vv[j]) 
					{
						//int dis=abs(i-j);
						//if(i==4) cout<<dis<<"?"<<endl;
						//if(dis<minn)
							vis[i]=j;break;
					}
			}
			vv[vis[i]]=1;
		}
		
		//for(int i=1;i<=n;i++)
		//	cout<<vis[i]<<" ";
		//cout<<endl;

int flag=0;
int flag1[2222];
//int flag1=0;//fei xiajiang
		for(int i=1;i<=m;i++)
		{
			int l,r;
			scanf("%d%d",&l,&r);
			//cout<<l<<" "<<r<<endl;
			stable_sort(vis+l,vis+r+1);
		//	for(int i=1;i<=n;i++)
		//		printf("%d ",vis[i]);
			//cout<<endl;
		}

					
		
		int lala=0;
		for(int i=1;i<=n;i++)
			if(num1[i]!=num2[i]) flag=1;
		if(cnt1!=cnt2) flag=1;
		if(flag) puts("No");
		if(!flag)
		{
			for(int i=1;i<n;i++)
				if(vis[i]>vis[i+1])
				{
					//cout<<flag1[i]<<endl;
					lala=1;break;
				}
			if(lala) puts("No");
			else puts("Yes");
		}
		
//cout<<endl;*/
	}
	return 0;
}