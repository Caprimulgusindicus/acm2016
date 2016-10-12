#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int sg[111];
int main()
{
	sg[0]=0;
	sg[1]=0;
	sg[2]=0;
	for(int n=3;n<=100;n++)
		for(int a=1;a<=100;a++)
			for(int b=1;b<=100;b++)
			{
				c=n-a-b;
				sg[n]=sg[a]^sg[b]^sg[c];
			}
	
	return 0;
}