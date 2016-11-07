#include <cstdio>
#include <cstring>
#include <stack>
#include <iostream>
using namespace std;
int ll[222];
int rr[222];
int aans[222];


long long pow(long long a,long long b)//a^b
{
	long long ans=1;
	while(b>0)
	{
		if(b&1)
			ans=ans*a;
		b=b>>1;
		a=a*a;
	}
	return ans;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(aans,0,sizeof(aans));
		memset(ll,0,sizeof(ll));
		memset(rr,0,sizeof(rr));
		long long l,r;
		scanf("%lld%lld",&l,&r);
		int len2=0;
		if(l==r) cout<<l<<endl;
		else 
		{
			//cout<<l<<" "<<r<<endl;
			stack <int> a;
			stack <int> b;
			while(r)   {b.push(r%2);r/=2;}
			while(!b.empty())   {rr[len2++]=b.top();b.pop();}
			while(l)   {a.push(l%2);l/=2;}
			int cnt=len2-a.size();
			while(!a.empty())   {ll[cnt++]=a.top();a.pop();}
			
			
			//for(int i=0;i<len2;i++)
			//	cout<<ll[i]<<" "<<rr[i]<<endl;

			int flag=0;
			long long  ans=0;
			for(int i=0;i<len2;i++)
			{
				if(ll[i]!=rr[i]) flag=1; 
				if(flag) ans+=pow(2,(len2-i-1));
				else if(flag==0&&rr[i]==1) //cout<<"here"<<endl,
					ans+=pow(2,(len2-i-1));

			}	
/*
			for(int i=0;i<len2;i++)
			{
				long long t=pow(2,(len2-i-1));
					if(aans[i]!=0) ans+=t;
			}*/
			cout<<ans<<endl;
		}
	}
}

