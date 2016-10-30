#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char s[111][111];
int del[111];
int vis[111];
char ans[111];
int main()
{
	memset(ans,0,sizeof(ans));
	memset(s,'A',sizeof(s));
	int m,n;
	int flag=0;
	scanf("%d%d",&n,&m);
	getchar();
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s[i]);
	}
	
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&del[i]);//,cout<<del[i]<<endl;
		vis[del[i]]=1;
		//cout<<s[del[i]]<<endl;
	}
	int len=strlen(s[del[1]]);
	//cout<<len<<endl;
	for(int i=1;i<=m;i++)
		if(strlen(s[del[i]])!=len) flag=1;


	if(!flag)
	{
		for(int j=0;j<len;j++)
		{
			flag=0;
			for(int i=2;i<=m;i++)
			{	
				//cout<<s[del[i]][j];
				//cout<<s[del[1]][j];
				//printf("%d",s[del[i]][j]==s[del[1]][j]);
				if(s[del[i]][j]!=s[del[1]][j]) ans[j]='?',flag=1;
				if(s[del[i]][j]==s[del[1]][j]&&!flag) ans[j]=s[del[1]][j];
				//				cout<<ans[j]<<endl;

				//cout<<endl;
			}
		}
		for(int i=1;i<=n;i++)
			if(!vis[i]&&strlen(s[i])==len)
			{
				int ff=1;
				for(int j=0;j<len;j++)
					ff=ff&&(s[i][j]==ans[j]||ans[j]=='?');
				if(ff){
					cout<<"No"<<endl;
					return 0;}
			}
		//cout<<ans[0]<<endl;
		//cout<<ans[1]<<endl;
		
		if(m==1)
			cout<<"Yes"<<endl<<s[del[1]]<<endl;
		else
		{
		cout<<"Yes"<<endl;
		for(int i=0;i<len;i++)
			cout<<ans[i];
		cout<<endl;
		}
	}
	else cout<<"No"<<endl;
	return 0;
}
