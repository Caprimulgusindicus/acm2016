#include <cstdio>
#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
char s[111111];
char ans[111111];
int main()
{
	memset(s,0,sizeof(s));
	memset(ans,0,sizeof(ans));
	gets(s);
	strcpy(ans,s);
	//cout<<s<<endl;
	int len=strlen(s);
	int flag=0;
	for(int i=0;i<len;i++)
		if(s[i]>'a') 
			{
				s[i]-=1;
				flag=1;
			}
		//else if(s[i]=='a'&&i==0) {flag=1;}

		else if(s[i]=='a'&&flag) break;
		else if(s[i]>'a') s[i]-=1;
		//cout<<ans<<endl;
	if(strcmp(s,ans)) cout<<s<<endl;
	else 
	{
		for(int i=0;i<len-1;i++)
			printf("%c",s[i]);
		if(s[len-1]-1<'a')
		printf("%c\n",'z');
		else printf("%c\n",s[len-1]-1);
	}
	return 0;
}