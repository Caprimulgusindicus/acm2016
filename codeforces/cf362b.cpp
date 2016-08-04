#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string.h>
using namespace std;
int xs=0,cnte=0,flagxs=0,flage=0;
char s[333];

int main()
{
	gets(s);
	int len=strlen(s);
	int t=0;
	int kaka=0;
	int tata=0;
	for(int i=0;i<len;i++)
	{
		if(flage) cnte++; 
		if(flagxs==1) xs++;
		if(s[i]=='.') flagxs=1;
		if(s[i]=='e') {flage=1;flagxs=-1;t=i;}
		if(s[i]=='0'&&!flage) tata++; 
		if(flagxs&&s[i]=='0') kaka++;
	}
	xs--;
	kaka--;
	int ee;
	if(cnte==1) ee=s[t+1]-'0';
	else if(cnte==2) ee=10*(s[t+1]-'0')+(s[t+2]-'0');
	else if(cnte==3) ee=100*(s[t+1]-'0')+10*(s[t+2]-'0')+(s[t+3]-'0');
	int cnt=0;
	int fflag=0;
	if(tata==len-3&&ee==0) printf("0");
	else if(ee==0)
	{
		if(kaka!=xs)
			for(int i=0;i<t;i++)
				printf("%c",s[i]);
		else 
			for(int i=0;i<t-xs-1;i++)
				printf("%c",s[i]);
	}
	
	else if(s[0]!='0')
	{
		for(int i=0;i<t;i++)//从第一位输出到e之前
		{
			if(fflag==1) cnt++;//让计数＋1，表示的是当前小数点应该在的位置；
			if(s[i]=='.') {fflag=1;continue;} //表示已经到达了小数部分
			if(cnt==ee+1) printf(".");
			if(s[i]=='0'&&i==0) continue; 
			else printf("%c",s[i]);
		}
		int lala=ee-xs;
		if(lala>0)
		for(int i=1;i<=lala;i++)
			printf("0");

}	
	
	puts("");	
	return 0;
}