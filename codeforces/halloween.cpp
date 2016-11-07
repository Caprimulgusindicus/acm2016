#include <cstdio>
#include <cstring>
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	char s[111]="dehtzhfeshllssneeghalleenuirsh";
	char s2[111]="halloweenhalloweenhalloweenhal";
	//cout<<strlen(s)<<" "<<strlen(s2)<<endl;
	for(int i=0;i<30;i++)
	{
		char ss=s[i]+abs(s2[i]-'a');
		if(ss>'z') 
			while(ss>'z') ss-=26;
		else if(ss<'a') 
			while(ss<'a') ss+=26;
		
		printf("%c",ss);
	}
	cout<<endl;
	return 0;
}