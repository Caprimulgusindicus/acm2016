#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	char s[6];
	getchar();
	scanf("%s",s);
	//cout<<s[0]<<endl;
	//	cout<<s[1]<<endl;

	//cout<<s[2]<<endl;

	//cout<<s[3]<<endl;

	//cout<<s[4]<<endl;

	if(n==12)
	{
		//for hour
		if(s[0]=='1'&&s[1]=='2'&&s[3]=='0'&&s[4]=='0') s[0]='0';
		else if(s[0]=='1'&&s[1]>'2') s[0]='0';//,cout<<"?";
		else if(s[0]=='0'&&s[1]=='0') s[1]='1';
		else if(s[0]>'1'&&s[1]!='0') s[0]='0';
		else if(s[0]>'1'&&s[1]=='0') s[0]='1';
		else if(s[0]!='0'&&s[1]>'2') s[1]='1';


	}
	if(n==24)
	{
		if(s[0]=='2'&&s[1]=='4'&&s[3]=='0'&&s[4]=='0') s[0]='0';
		else if(s[0]=='2'&&s[1]>'4') s[1]='1';
		else if(s[0]>'2') s[0]='1'; 
	}
	//for minute
	if(s[3]>'5') s[3]='5';
	for(int i=0;i<5;i++)
		printf("%c",s[i]);
	cout<<endl;
	return 0;
}