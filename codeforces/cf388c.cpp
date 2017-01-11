#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
char s[222222];
int main()
{
	int n;
	while(~scanf("%d",&n)){
	getchar();
	long long cntd=0;long long cntr=0;
	scanf("%s",s);
	for(int i=0;i<n;i++)
		if(s[i]=='D') cntd++;
		else cntr++;
	int flag=0;
	int i=0;
	long long tmpd=0;
	long long tmpr=0;
	if(cntd==0) puts("R");
	else if(cntr==0) puts("D");
	else{
	while(cntd!=0&&cntr!=0)
	{
				//	cout<<cntd<<" "<<cntr<<endl;

		//if(s[i]=='0') continue;
		if(s[i]=='D'&&tmpr==0) 
		{
			tmpd++;
			cntr--;
		}
		else if(s[i]=='D'&&tmpr!=0) tmpr--;
		else if(s[i]=='R'&&tmpd==0)
		{ 
			tmpr++;
			cntd--;
		}
		else if(s[i]=='R'&&tmpd!=0) tmpd--; 
		if(cntr==0) {flag=1;break;}
		if(cntd==0) {flag=2;break;}
		if(i==n-1) i=0;
		else i++;
	}
	if(flag==1) puts("D");
	else puts("R");
}
}
	return 0;
}