#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int ans1=abs(a-c)+abs(b-c);
	int ans2=abs(a-b)+abs(c-b);
	int ans3=abs(b-a)+abs(c-a);
	//cout<<ave<<endl;
	int ans=min(ans1,ans2);
	ans=min(ans,ans3);
	cout<<ans<<endl;
	return 0;
}