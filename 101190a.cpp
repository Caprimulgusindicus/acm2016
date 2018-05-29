#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char s[220];
int main()
{
	//freopen("abbreviation.in","r",stdin);
	//freopen("abbreviation.out","w",stdout);
	while(gets(s))
	{
		string res;
		int len=strlen(s);
		int start_flag=0;
		char st;
		for(int i=0;i<len;i++)
		{
			if(s[i]>='A'&&s[i]<='Z'&&(s[i+1]>='a'&&s[i+1]<='z'))
				start_flag=1,st=s[i];
			if(start_flag==1)
			{
				if(s[i-1]==' '&&s[i]>='A'&&s[i]<='Z'&&(s[i+1]>='a'&&s[i+1]<='z'))
			}
		}
		cout<<res;
	}
	return 0;
}