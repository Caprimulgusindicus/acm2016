#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
typedef long long ll;
long long op[1111111];
long long x[1111111];

int main()
{
	priority_queue <ll,vector<ll>,greater<ll> > pq;
	priority_queue <ll,vector<ll>,greater<ll> > pq2;

	long long n;
	char s[22];
	scanf("%I64d",&n);
	getchar();
	for(long long i=1;i<=n;i++)
	{
		scanf("%s",s);
		if(s[0]=='i') op[i]=1;
		else if(s[0]=='r') op[i]=2;
		else if(s[0]=='g') op[i]=3;
		if(op[i]==1||op[i]==3)
		scanf("%I64d",&x[i]);
	}
//cout<<op[1]<<" "<<x[1]<<endl;


int cnt=0;
for(long long i=1;i<=n;i++)
	{
		
		long long xx;
		xx=x[i];
		if(op[i]==1)//insert
		{
			pq.push(xx);
			cnt+=1;
			//printf("insert %I64d\n",x);		
		}
		else if(op[i]==2)//remove
		{
			if(pq.empty())
			{
				//printf("insert 0\n");
				pq.push(0);
				cnt+=1;
				pq.pop();
				cnt+=1;
			}
			else{
			pq.pop();cnt+=1;}
			
			//printf("removeMin %I64d\n",x);		
		}
		else if(op[i]==3)//getmin
		{
			if(pq.empty())
			{
				pq.push(xx);
				cnt+=1;
			}
			else if(pq.top()!=xx&&xx>pq.top())
			{
				//printf("removeMin\n");
				pq.pop();
				//printf("insert %I64d\n",x);
				pq.push(xx);
				cnt+=2;
			}
			else if(pq.top()!=xx&&xx<pq.top())
			{
				//printf("insert %I64d\n",x);
				pq.push(xx);
				cnt+=1;
			}
			//printf("getMin %I64d\n",x);
			cnt+=1;
		}
	}
	printf("%d\n",cnt);
	for(long long i=1;i<=n;i++)
	{
		
		long long xx;
		xx=x[i];
		if(op[i]==1)//insert
		{
			pq2.push(xx);
			printf("insert %I64d\n",xx);		
		}
		else if(op[i]==2)//remove
		{
			if(pq2.empty())
			{
				printf("insert 0\n");
				pq2.push(0);
				printf("removeMin\n");	
				pq2.pop();
				//cout<<pq2.size()<<"233"<<endl;
				//cnt+=1; 
			}
			else{
			pq2.pop();
			printf("removeMin\n");	}
				
		}
		else if(op[i]==3)//getmin
		{
			if(pq2.empty())
			{
				printf("insert %I64d\n",xx);
				pq2.push(xx);
				//cnt+=1;
			}
			else if(pq2.top()!=xx&&xx>pq2.top())
			{
				printf("removeMin\n");
				pq2.pop();
				printf("insert %I64d\n",xx);
				pq2.push(xx);
			}
			else if(pq2.top()!=xx&&xx<pq2.top())
			{
				printf("insert %I64d\n",xx);
				pq2.push(xx);
			}
			printf("getMin %I64d\n",xx);
		}
	}

	return 0;
}