#include <cstring>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
char s[333];
int main()
{
	for(int i=0;i<333;i++)
		s[i]='0';
	int cntin=0;
	int cntout=0;
	int tmpout=0;
	int n;
	scanf("%d",&n);
	getchar();
	gets(s);
	bool flag=0;
	if(n==1)
	{
		int i=0;
		if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
		{
			cout<<"1 0"<<endl;
		}
		else cout<<"0 0"<<endl;
	}
	else
	{
		for(int i=0;i<=n;i++)
			{
		//cout<<s[i]<<endl;
				
				if(!flag)
				{
					if(s[i]=='_'||s[i]=='('||s[i]=='\0') cntout=max(cntout,tmpout),tmpout=0;
					if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
					{
						tmpout++;//cout<<tmpout<<endl;
					}
				}
				else
				{
					if(((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))&&(s[i+1]=='_'||s[i+1]==')'||s[i+1]=='\0'))
						cntin++;
				}
				if(s[i]=='(') flag=1;
				if(s[i]==')') flag=0;
			}	
			cout<<cntout<<" "<<cntin<<endl;
	}
	
	return 0;
}