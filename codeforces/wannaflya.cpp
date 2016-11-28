#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char s[1111];
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		getchar();
		scanf("%s",s);
		int st=0;int end=0;
		char fc='0';
		int flag=0;
		int flag2=0;
		for(int i=0;i<n;i++)
		{
			if(s[i]!='.'&&!flag) st=i+1,fc=s[i],flag=1;
			if(fc!='0'&&fc!=s[i]&&s[i]!='.') flag2=1;
			if(fc!='0'&&fc!=s[i]) {end=i;break;}
		}
		if(!flag2)
		{ 
			if(fc=='L') swap(st,end),end--;
			if(fc=='R') end++;
		}
		cout<<st<<" "<<end<<endl;
	}
}