#include <cstdio>
#include <iostream>
using namespace std;
char a[1111][10];
int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		gets(a[i]);
		//cout<<a[i]<<endl;
	}	
	for(int i=1;i<=n;i++)
			if(a[i][0]=='O'&&a[i][1]=='O') {flag=1;a[i][0]='+';a[i][1]='+';break;}
			else if (a[i][3]=='O'&&a[i][4]=='O') {flag=1;a[i][3]='+';a[i][4]='+';break;}
	if(!flag) puts("NO");
	else
	{
		puts("YES");
		for(int i=1;i<=n;i++)
			printf("%s\n",a[i]);
	}
	return 0;
}