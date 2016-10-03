#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int T;
	char s[1111];
	scanf("%d",&T);
	for(int ca=1;ca<=T;ca++)
	{
		scanf("%s",s);
//		cout<<s<<endl;
		//23333
		int len =strlen(s);
		for(int i=0;i<len/2;i++)
		{
			s[len-i]=s[i];
			
		}	
		cout<<s<<endl;
	}
	return 0;
}