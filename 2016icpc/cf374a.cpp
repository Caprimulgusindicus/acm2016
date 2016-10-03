#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n;
char s[111];
	int ans[111];
int main()
{
	
	while(~scanf("%d",&n)){
		memset(ans,0,sizeof(ans));
		memset(s,0,sizeof(s));
	
	getchar();
	gets(s);
	int len=strlen(s);
	int total=0;
	int cnt=0;
	for(int i=0;i<len;i++)
	{
		if(s[i]=='B') ans[cnt]++;
		if(s[i]=='B'&&s[i+1]!='B') total++,cnt++; 
	}
	cout<<total<<endl;
	if(total!=0){
	for(int i=0;i<=cnt;i++)
		if(!i&&ans[i]!=0) printf("%d",ans[i]);
		else if(i&&ans[i]!=0) printf(" %d",ans[i]);
	puts("");
	}
}
	return 0;
}