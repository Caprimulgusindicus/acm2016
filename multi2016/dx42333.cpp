#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
long long arr[111111];
long long vis[111111];
long long maxvis[111111];
const long long LENGTH=100;
long long temp[LENGTH];  //额外的辅助数组
long long cou=0;

void Merge(long long * arr,long long first,long long med,long long last)
{
	long long i=first,j=med+1;
	long long cur=0;
	while (i<=med&&j<=last)
	{
		
		if (arr[i]<arr[j])
		{
			temp[cur++]=arr[i++];
		}
		else
		{
			vis[arr[i]]+=1+med;
			vis[arr[j]]+=1+med;
			temp[cur++]=arr[j++];
			
			cou+=med-i+1;  //核心代码，逆序数增加
		}
	}
	while (i<=med)
	{
		temp[cur++]=arr[i++];
	}
	while (j<=last)
	{
		temp[cur++]=arr[j++];
	}
	for (long long m=0;m<cur;m++)
	{
		arr[first++]=temp[m++];
	}
}

void MergeSort(long long *arr,long long first,long long last)
{
	if (first==last)
	{
		return ;
	}
	long long med=first+(last-first)/2;
	MergeSort(arr,first,med);
	MergeSort(arr,med+1,last);
	Merge(arr,first,med,last);
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		memset(vis,0,sizeof(vis));
		long long n;
		long long cnt=0;
		scanf("%lld",&n);
		if(n<=0) continue;
		for(long long i=1;i<=n;i++)
		{
			scanf("%lld",&arr[i]);
		}	
		//for(int i=1;i<=n;i++)
		//	cout<<maxvis[i]<<" "<<minvis[i]<<endl;
		int flag=1;
		MergeSort(arr,1,n);
	
		printf("Case #%d: ",tt);
		if(n==1||cou==0)
		printf("0\n");
		else for(long long i=1;i<=n;i++)
		{
			if(i!=n) printf("%lld ",vis[i]);
			else printf("%lld\n",vis[i]);
			
		}
			
		
	}

	return 0;
}