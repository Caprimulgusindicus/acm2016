#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[111];
int b[111];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	int flag=0;
	int v=a[n];
	if((v-2*a[1])>=0&&v<b[1]) flag=1;
	else if()
	if(flag) printf("%d\n",v);
	else puts("-1");
	return 0;
}