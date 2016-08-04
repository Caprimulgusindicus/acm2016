#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string.h>
#include <string>
using namespace std;
int main()
{
	int n;
	int ans=111111111;
	char s[111111];
	int vis[1111];//cong 0 kaishi
	int vis2[1111];
	int cnt=0;
	int cnt2=0;
	scanf("%d",&n);
	getchar();
	gets(s);
	int j=0;
	int len=strlen(s);
	for(int i=0;i<len;i++)
	{
		int ch=s[i]-'A';
		//cout<<ch<<endl;
		if(vis[ch]==0) vis[ch]++,cnt++;
	}
	//cout<<cnt<<endl;
	for(int i=0;i<len;i++)
	{
		int ch=s[i]-'A';
		if(vis2[ch]==0) cnt2++;
		vis2[ch]++;
		if(cnt==cnt2)
		{
			while(vis2[s[j]-'A']>1)
			{
				vis2[s[j]-'A']--;j++;
			}
			ans=min(ans,i-j+1);
		}
		
	}
	cout<<ans<<endl;
	return 0;
}