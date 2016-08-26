#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
	char cd[3];
	gets(cd);
	int flagz=0;
	int flagy=0;
	int flags=0;
	int flagx=0;
	if(cd[0]=='a') flagz=1;
	if(cd[0]=='h') flagy=1;
	if(cd[1]=='8') flags=1;
	if(cd[1]=='1') flagx=1;
	if((flagz==1&&flags==1)||(flagy==1&&flags==1)|| (flagz==1&&flagx==1)||(flagy==1&&flagx==1) )
		puts("3");
	else if(flagx==1||flags==1||flagz==1||flagy==1)
		puts("5");
	else puts("8");
	return 0;
}