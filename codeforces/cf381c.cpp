#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
int a[111111];

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int ans=1e9;
	for(int i=1;i<=m;i++)
	{
		int l;int r;
		scanf("%d%d",&l,&r);
		ans=min(ans,r-l+1);
	}
	int index=0;
	for(int i=1;i<=n;i++)
	{
		
		a[i]=index;
		index++;
		index%=ans; 
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}