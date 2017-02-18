#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
	char s[555];
	int vis[28];
	int flag=0;
void order()
{
	int n=0;
	for(int i=26;i>=0;i--)
		if(vis[i]!=0) {n=i;break;}
	for(int i=1;i<=n;i++)
		if(vis[i]==0) flag=1;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)//behind
		{
			//cout<<vis[i]<<" "<<vis[j]<<endl;
			if(vis[j]<vis[i]) {flag=1;}
		}

		for(int j=0;j<i;j++)//before
		{
			if(vis[j]>vis[i]) flag=1;
		}
	}
	
}
int main()
{
	flag=0;
	scanf("%s",s);
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		int now=s[i]-'a'+1;
		if(!vis[now]) {vis[now]=i+1;}
	}
	//for(int i=1;i<=26;i++)
	//	cout<<vis[i]<<" ";
	if(len==1)
	{
		if(vis[1]==0) flag=1; 
	}
	else order();
	if(!flag) puts("YES");
	else puts("NO");
 	return 0;
}