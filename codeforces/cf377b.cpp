#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int a[555];
int b[555];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int cnt=0;
	for(int i=2;i<=n;i++)
	{
		int tmp=k-a[i]-a[i-1];
		if(tmp>0)
			a[i]+=tmp,cnt+=tmp;
	}
	cout<<cnt<<endl;
	for(int i=1;i<n;i++)
		printf("%d ",a[i]);
	printf("%d\n",a[n]);
	return 0;
}