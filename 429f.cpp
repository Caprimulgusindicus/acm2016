#include <cstdio>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
int a[135];
char s[111111];
int main()
{
	while(gets(s)) 
	{
		int space_flag=0;
		for (int i=0;i<strlen(s);i++)
		{
			int pos=s[i];
			a[i]=1;
		}
		if(a[32]==1) space_flag=1;
		cout<<space_flag<<endl;
		int nowstart=48;
		string numres="";
		for(int i=48;i<=122;i++)
		{
			if(a[i]==1&&a[i+1]!=1) 
			{
				string tmp;
				sprintf()
				numres+=nowstart+i;
				nowstart=i;	
			}
		}
	}
}