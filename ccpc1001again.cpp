#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
char s[1111111111];
const int MOD=10001;
int main()
{
	int ca=1;
	long long ans=0;
	while(~scanf("%s",s))
	{
		int len=strlen(s);
		for(int i=0;i<len;i++)
		{
			ans=ans*10+(s[i]-'0');
			//ans%=MOD;
			//cout<<ans<<endl;
//			printf("%c",s[i]);
		}

	}
	return 0;
}