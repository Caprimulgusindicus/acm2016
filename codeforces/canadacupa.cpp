#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char s[222222];
int n;
int check(int x)
{
	int flag=1;
	while(flag)
	{
		if(x-1<0&&s[x]=='<') {flag=0;break;}
		if(x+1>n-1&&s[x]=='>') {flag=0;break;}
		if(s[x]=='>'&&s[x+1]=='<') {flag=-1;break;}
		if(s[x]=='<'&&s[x-1]=='>') {flag=-1;break;}
		if(s[x]=='>') x++;
		else if(s[x]=='<') x--; 
		//cout<<s[x]<<" ";
	}
	if(flag==-1) return 0;
	else if(flag==0) return 1;
}
//>><<
//0123
int main()
{
	while(~scanf("%d",&n))
	{
		int ans=0;
		memset(s,0,sizeof(s));
		getchar();
		gets(s);
		int cnt=0;
		for(int i=0;i<n-1;i++)
		{
			if(s[i]=='>'&&s[i+1]=='<')
			{
				cnt+=2;
				for(int j=i-1;j>=0;j--)
					if(s[j]=='<') break;
					else cnt++;
				for(int j=i+2;j<n;j++)
					if(s[j]=='>') break;
					else cnt++;
			//cout<<endl;
			}
		}
		cout<<n-cnt<<endl;
	}
	return 0;
}