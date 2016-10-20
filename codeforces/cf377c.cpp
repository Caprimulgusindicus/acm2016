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
	ans=a[1]-a[0];
	if(a[2]-a[1]>1)
		ans+=2*(a[2]-a[1]-1);
	if(a[2]==a[1]) ans--;
	if(ans>0) cout<<ans<<endl;
	else cout<<0<<endl;
	return 0;
}