#include <iostream>
#include <cstdio>
using namespace std;
char op[10];
char x;
int a[111111];
int b[111111];

int main()
{
	int n;
	int cnt=1;
	
	while(~scanf("%d",&n)&&n)
	{
		for(int i=1;i<=n;i++)
		{
			int num;
			scanf("%s",op);
			scanf("%c",&x);
			scanf("%c",&x);
			scanf("%d",&num);
			if(strcmp(op,"push")==0)
			{

			}
			else if(strcmp(op,"pop")==0)
			{

			}
			else if(strcmp(op,"merge")==0)
			{
				
			}
		}
		printf("Case #%d:\n",cnt++);

	}
	return 0;
}