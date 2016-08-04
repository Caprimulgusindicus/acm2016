#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;
char s[1500];
int main()
{
	//gets(s);
	scanf("%s",s);
	int n=strlen(s);
	int flag=0;
	//cout<<n<<endl;
	//cout<<n/2<<endl;
	 if(n==1)
	{
		int middle=0;
		if(s[middle]!='H'&&s[middle]!='I'&&s[middle]!='M'&&s[middle]!='o'&&s[middle]!='O'&&
			s[middle]!='T'&&s[middle]!='U'&&s[middle]!='V'&&s[middle]!='v'&&s[middle]!='x'&&s[middle]!='X'&&
			s[middle]!='w'&&s[middle]!='W'&&
			s[middle]!='Y'&&s[middle]!='A')
			flag=1;

	}
	else if(n%2==0) //如果是偶数长度
	{
		for(int i=0;i<n/2;i++)
		{
			int m=n-i-1;
			if((s[i]=='b'&&s[m]=='d')||(s[i]=='M'&&s[m]=='M')
				||(s[i]=='o'&&s[m]=='o')||(s[i]=='O'&&s[m]=='O')||(s[i]=='p'&&s[m]=='q')
				||(s[i]=='q'&&s[m]=='p')||(s[i]=='d'&&s[m]=='b')
			||(s[i]=='U'&&s[m]=='U')||(s[i]=='v'&&s[m]=='v')||(s[i]=='V'&&s[m]=='V')
			||(s[i]=='w'&&s[m]=='w')||(s[i]=='W'&&s[m]=='W')||(s[i]=='x'&&s[m]=='x')
			||(s[i]=='X'&&s[m]=='X')||(s[i]=='I'&&s[m]=='I')||(s[i]=='H'&&s[m]=='H')
			||(s[i]=='T'&&s[m]=='T')||(s[i]=='Y'&&s[m]=='Y')||(s[i]=='A'&&s[m]=='A')) continue;
				else {flag=1;break;}
		}
	}
	else 
	{
		for(int i=0;i<n/2;i++)
		{
			int m=n-i-1;
			if((s[i]=='b'&&s[m]=='d')||(s[i]=='M'&&s[m]=='M')
				||(s[i]=='o'&&s[m]=='o')||(s[i]=='O'&&s[m]=='O')||(s[i]=='p'&&s[m]=='q')
			||(s[i]=='U'&&s[m]=='U')||(s[i]=='v'&&s[m]=='v')||(s[i]=='V'&&s[m]=='V')
			||(s[i]=='w'&&s[m]=='w')||(s[i]=='W'&&s[m]=='W')||(s[i]=='x'&&s[m]=='x')
			||(s[i]=='X'&&s[m]=='X')||(s[i]=='I'&&s[m]=='I')||(s[i]=='H'&&s[m]=='H')
			||(s[i]=='T'&&s[m]=='T')||(s[i]=='Y'&&s[m]=='Y')||(s[i]=='A'&&s[m]=='A')
			||(s[i]=='q'&&s[m]=='p')||(s[i]=='d'&&s[m]=='b')
			) continue;
				else {flag=1;break;}
		}
		int middle=n/2;
		if(s[middle]!='H'&&s[middle]!='I'&&s[middle]!='M'&&s[middle]!='o'&&s[middle]!='O'&&
			s[middle]!='T'&&s[middle]!='U'&&s[middle]!='V'&&s[middle]!='v'&&s[middle]!='x'&&s[middle]!='X'&&
			s[middle]!='w'&&s[middle]!='W'&&
			s[middle]!='Y'&&s[middle]!='A')
			flag=1;
	}
	if(flag==1) puts("NIE");
	else puts("TAK");
	return 0;
}