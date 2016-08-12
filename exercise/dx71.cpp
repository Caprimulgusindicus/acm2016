#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char s[1111111];
int vis[111111];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(s,0,sizeof(s));
		memset(vis,0,sizeof(vis));
		int n;
		scanf("%d",&n);
		int pair=0;
		int k=n/2;
		
		getchar();
		
			scanf("%s",s);	
	
		if(n&1) puts("No");
		else
		{
			for(int i=0;i<n-1;i++)
				for(int j=i+1;j<n;j++)
					if(!vis[i]&&!vis[j]&&s[i]=='('&&s[j]==')')
					{
						vis[i]=1;vis[j]=1;
						pair++;
					}
		//cout<<k<<endl;
		//cout<<t<<endl;
		}
		
		if(n==2&&s[0]==')'&&s[1]=='(') puts("Yes");
		else if(k-pair<=1&&n>2) puts("Yes");
		else puts("No");
	}
	return 0;
}