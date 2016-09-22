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
	sort(b+1,b+1+m);
	int flag=0;
	
	int begin=a[n];
	int end=b[1];
	int v;
	int ans;
	//cout<<begin<<endl;
	//cout<<end<<endl;
	for(v=begin;v<end;++v)
	{
	//∫	cout<<v<<endl;
		for(int i=1;i<=n;i++)
		{
			int aa=v-2*a[i];
			if(aa>=0) {flag=1;ans=v;break;}
		}
		if(flag==1) break;
	}
	if(flag) printf("%d\n",ans);
	else puts("-1");
	return 0;
}