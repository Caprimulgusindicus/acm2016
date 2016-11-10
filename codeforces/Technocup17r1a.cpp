#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	
		int aans=b;
		int flag=0;
		stack <int> ans;
		while(b>a)
		{
			if((b-1)%10==0)
				b=(b-1)/10,ans.push(b);
			else if(b%2==0)
				b/=2,ans.push(b);
			else {flag=1;break;}
			//cout<<b<<endl;
		}
		if(a==b) flag=1;
		else flag=0;
		if(!flag) puts("NO");
		else 
		{
			puts("YES");
			int cnt=ans.size()+1;
			cout<<cnt<<endl;
			while(!ans.empty())
			{
				int x=ans.top();
				printf("%d ",x);
				ans.pop();
			}
			printf("%d\n",aans);
		}

	
	return 0;
}