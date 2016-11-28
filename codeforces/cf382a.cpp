#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
	int n,k;char s[111];
	while(~scanf("%d%d",&n,&k)){
		memset(s,0,sizeof(s));
		getchar();
	scanf("%s",s);
	int st=0,end=0;
	for(int i=0;i<n;i++)
		if(s[i]=='T') end=i;
		else if(s[i]=='G') st=i;
	int flag=0;
	for(int i=st;i>=0;i-=k)
	{
		//cout<<i<<" ";
		if(s[i]=='#') break;
		else if(s[i]=='.') continue;
		else if(s[i]=='T') flag=1;
	}
	for(int i=st;i<n;i+=k)
		if(s[i]=='#') break;
		else if(s[i]=='.') continue;
		else if(s[i]=='T') flag=1;
	if(flag) puts("YES");
	else puts("NO");
}
	return 0;
}