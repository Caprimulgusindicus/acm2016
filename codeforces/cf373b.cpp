#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char s[111111];
char s2[111111];
int main()
{
	int n;
	int r1=0;int r2=0;
	int b1=0;int b2=0;
	scanf("%d",&n);
	getchar();
	scanf("%s",s);
//	cout<<s2<<endl;
	//rbbbbb rbbbrrr
	for(int i=0;i<n;i++)
	{
		if(i&1)
		{
			if(s[i]=='r') r1++;
			else b1++;
		}
		else 
		{
			if(s[i]=='r') r2++;
			else b2++;
		}
		
	}
	cout<<min(max(r1,b2),max(b1,r2))<<endl;
	
	
	return 0;
}