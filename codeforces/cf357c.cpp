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
	memset(x,0,sizeof(x));
	memset(op,0,sizeof(op));
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
			cnt++;
			//printf("insert %I64d\n",xx);		
		}
		else if(op[i]==2)//remove
		{
			if(pq.empty())
			{
				//printf("insert 0\n");
				pq.push(0);
				cnt++;
				//printf("removeMin\n");	
				pq.pop();
				cnt++;
			}
			else{
			pq.pop();
			cnt++;
			//printf("removeMin\n");	
		}
				
		}
		else if(op[i]==3)//getmin
		{
			if(pq.empty())
			{
				//printf("insert %I64d\n",xx);
				pq.push(xx);
				cnt++;
				//cnt+=1;
			}
			else  if(pq.top()!=xx&&xx>pq.top())
			{
				while(xx>pq.top()&&(!pq.empty()))
				{cnt++;
					//printf("removeMin\n");
					pq.pop();
				}	
				if(pq.empty())
				{cnt++;
					//printf("insert %I64d\n",xx);
					pq.push(xx);
				}
				else if(pq.top()!=xx)
				{cnt++;
					//printf("insert %I64d\n",xx);
					pq.push(xx);
				}
				
			}
			else if(pq.top()!=xx&&xx<pq.top())
			{cnt++;
				//printf("insert %I64d\n",xx);
				pq.push(xx);
			}
			cnt++;//printf("getMin %I64d\n",xx);
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
			else  if(pq2.top()!=xx&&xx>pq2.top())
			{
				while(xx>pq2.top()&&(!pq2.empty()))
				{
					printf("removeMin\n");
					pq2.pop();
				}	
				if(pq2.empty())
				{
					printf("insert %I64d\n",xx);
					pq2.push(xx);
				}
				else if(pq2.top()!=xx)
				{
					printf("insert %I64d\n",xx);
					pq2.push(xx);
				}
				
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