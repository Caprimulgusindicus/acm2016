#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	string s1;
	string s2;
	cin>>s1;
	cin>>s2;
	if(s1==s2) puts("YES");
	else
	{
		if(s1=="sunday")
		{
			if(s2=="wednesday"||s2=="tuesday") puts("YES");
			else puts("NO");
		}
		if(s1=="monday")
		{
			if(s2=="thursday"||s2=="wednesday") puts("YES");
			else puts("NO");
		}
			
		if(s1=="tuesday")
		{
			if(s2=="friday"||s2=="thursday") puts("YES");
				else puts("NO");

		}	
		if(s1=="wednesday")
		{	if(s2=="saturday"||s2=="friday") puts("YES");
			else puts("NO");}
		if(s1=="thursday"){
			if(s2=="sunday"||s2=="saturday") puts("YES");
			else puts("NO");
		}
			
		if(s1=="friday"){
			if(s2=="sunday"||s2=="monday") puts("YES");
			else puts("NO");
		}
			
		if(s1=="saturday"){
			if(s2=="tuesday"||s2=="monday") puts("YES");
			else puts("NO");
		}
			
		

	}
	return 0;
}