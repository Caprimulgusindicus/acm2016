#include <cstring>
#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int n,k;
	int a[222];
	while(~scanf("%d%d",&n,&k))
	{
		memset(a,0,sizeof(a));
		getchar();
		int cnt=0;
		string ss;
		for(int i=1;i<=n;i++)
		{
			cin>>ss;
			a[cnt++]=ss.size();
		}	
		string ans;
		cin>>ans;
		//cout<<cnt<<endl;
		int len=ans.size();
		sort(a,a+cnt);	
		//for(int i=0;i<cnt;i++)
		//	cout<<a[i]<<endl;
		int tmin=0;int ansmax=0;
		int tmax=0;	int ansmin=0;
		for(int i=0;i<cnt;i++)
		{
			if(a[i]>len) break; 
			if(tmax>=k) ansmax+=5,tmax=0;
			//cout<<a[i]<<" "<<ansmax<<endl;
			tmax++;
			ansmax++;
			
		}

		for(int i=0;i<cnt;i++)
		{
			if(tmin>=k) ansmin+=5,tmin=0;
			ansmin++;
			if(a[i]==len) {break;}
			
			tmin++;
		}
		cout<<ansmin<<" "<<ansmax<<endl;
	}
	return 0;
}