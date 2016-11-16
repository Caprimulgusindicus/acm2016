#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
	char s[111111];

int main()
{
	int n;
	int cnta=0,cntb=0,cntc=0;
	scanf("%d",&n);
	getchar();
	scanf("%s",s);
	for(int i=0;i<n;i++)
		if(s[i]=='A') cnta++;
		else if(s[i]=='D') cntb++;
	if(cnta==cntb) puts("Friendship");
	else if(cnta>cntb) puts("Anton");
	else puts("Danik");
	return 0;
}