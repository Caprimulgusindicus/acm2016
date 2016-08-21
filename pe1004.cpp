#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
	char s[7];
	int maxx=0;
	for(int i=999;i>=100;i--)
		for(int j=999;j>=100;j--)
		{
			int t=i*j;
			s[0]=t-t/10*10;
			s[1]=(t-t/100*100)/10;
			s[2]=(t-t/1000*1000)/100;
			s[3]=(t-t/10000*10000)/1000;
			s[4]=(t-t/100000*100000)/10000;
			s[5]=(t-t/1000000*1000000)/100000;
			if((s[0]==s[5])&&(s[1]==s[4])&&s[2]==s[3])
			{
				cout<<i<<" "<<j<<" "<<t<<endl;
				maxx=max(maxx,t);
			}	
			cout<<maxx<<endl;
		}
	return 0;
}