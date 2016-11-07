#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int maxx(int a,int b)
{
	if(a>b) return a;
	else return b;
}
int main()
{
	char s[111];
	char t[111];
	int dis;
	int vis[111];
	scanf("%s",t);
	int len=strlen(t);
	for(int i=1;i<=len;i++)
		s[i]=t[i-1];
	int tmp=0;
	int cnt=0;
	int ans=0;
	for(int i=1;i<=len;i++)
		if(s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='Y'||s[i]=='U')
		{
			//cout<<i<<" ";
			dis=i-tmp;
			//cout<<dis<<" ";
			cnt++;
			vis[i]=1;
			ans=maxx(dis,ans);
			tmp=i;
			//cout<<ans<<endl;
		}	
	ans=max(len+1-tmp,ans);
	cout<<ans<<endl;
	return 0;

}