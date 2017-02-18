#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int n;
	int cnt=0;
	int cnt2=0;
	char t[111][111];
	scanf("%d",&n);
	getchar();
	char s[4];
	scanf("%s",s);
	getchar();
	for(int i=1;i<=n;i++)
	{	
		scanf("%s",t[i]); 
		if(t[i][5]==s[0]&&t[i][6]==s[1]&&t[i][7]==s[2])
		cnt++;
		else cnt2++;
		getchar();}
	
	if(cnt==cnt2) puts("home");
	else puts("contest");
	return 0;
}