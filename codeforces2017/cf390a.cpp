#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
char s[5][5];

bool judge()
{
	if(s[0][1]=='x'&&s[0][2]=='x'&&s[0][3]=='x') return 1;
	else if (s[1][1]=='x'&&s[1][2]=='x'&&s[1][3]=='x') return 1;
	else if (s[2][1]=='x'&&s[2][2]=='x'&&s[2][3]=='x') return 1;
	else if (s[3][1]=='x'&&s[3][2]=='x'&&s[3][3]=='x') return 1;

	else if (s[0][0]=='x'&&s[0][1]=='x'&&s[0][2]=='x') return 1;
	else if (s[1][0]=='x'&&s[1][1]=='x'&&s[1][2]=='x') return 1;
	else if (s[2][0]=='x'&&s[2][1]=='x'&&s[2][2]=='x') return 1;
	else if (s[3][0]=='x'&&s[3][1]=='x'&&s[3][2]=='x') return 1;

	else if (s[0][0]=='x'&&s[1][0]=='x'&&s[2][0]=='x') return 1;
	else if (s[0][1]=='x'&&s[1][1]=='x'&&s[2][1]=='x') return 1;
	else if (s[0][2]=='x'&&s[1][2]=='x'&&s[2][2]=='x') return 1;
	else if (s[0][3]=='x'&&s[1][3]=='x'&&s[2][3]=='x') return 1;

	else if (s[1][0]=='x'&&s[2][0]=='x'&&s[3][0]=='x') return 1;
	else if (s[1][1]=='x'&&s[2][1]=='x'&&s[3][1]=='x') return 1;
	else if (s[1][2]=='x'&&s[2][2]=='x'&&s[3][2]=='x') return 1;
	else if (s[1][3]=='x'&&s[2][3]=='x'&&s[3][3]=='x') return 1;

	else if (s[0][0]=='x'&&s[1][1]=='x'&&s[2][2]=='x') return 1;
	else if (s[2][2]=='x'&&s[1][1]=='x'&&s[3][3]=='x') return 1;
	else if (s[0][1]=='x'&&s[1][2]=='x'&&s[2][3]=='x') return 1;
	else if (s[1][0]=='x'&&s[2][1]=='x'&&s[3][2]=='x') return 1;

	else if (s[0][3]=='x'&&s[1][2]=='x'&&s[2][1]=='x') return 1;
	else if (s[1][2]=='x'&&s[2][1]=='x'&&s[3][0]=='x') return 1;
	else if (s[0][2]=='x'&&s[1][1]=='x'&&s[2][0]=='x') return 1;
	else if (s[1][3]=='x'&&s[2][2]=='x'&&s[3][1]=='x') return 1;
	return 0;
}
int main()
{
	scanf("%s",s[0]);getchar();
	scanf("%s",s[1]);getchar();
	scanf("%s",s[2]);getchar();
	scanf("%s",s[3]);getchar();
	
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			if(s[i][j]=='.') 
				{
					s[i][j]='x';
					if(judge()) {puts("YES");return 0;}
					else s[i][j]='.';
				}
	puts("NO");
	return 0;
}