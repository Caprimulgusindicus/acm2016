#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
char lala[55]="abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
int abs(int n)
{
	return n>0?n:-n;
}
int main()
{
	char s[111];
	scanf("%s",s);

	int ans=min(abs(s[0]-'a'),abs('z'-s[0]+1));
	//cout<<ans<<endl;
	int len=strlen(s);
	for(int i=1;i<len;i++)	
	{
		//cout<<s[i]-s[i-1]<<" "<<s[i]+26-s[i-1]<<"??"<<endl;
		int tmp=min(abs(s[i]-s[i-1]),abs(s[i]-26-s[i-1]));
		tmp=min(tmp,s[i]+26-s[i-1]);
		//cout<<tmp<<endl;
		ans+=tmp;
	}
	cout<<ans<<endl;

	return 0;
}