#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
long long a[4];
int main()
{
	long long ans=0;
	scanf("%I64d%I64d%I64d",&a[0],&a[1],&a[2]);
	sort(a,a+3);
	if(a[0]!=0&&a[1]!=0&&a[2]!=0)
		ans=a[2]-a[1];
	else if((a[0]==0)&&a[1]!=0&&a[2]!=0)
		ans=a[2]-1;
	else if(a[0]==0&&a[1]==0&&a[2]!=0)
		ans=a[2]-a[0]-1;
	else ans=0;
	cout<<ans<<endl;
	return 0;
}