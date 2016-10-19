#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	int k,r;
	scanf("%d%d",&k,&r);
	int ans=1;
	int flag=ans*k;
	if(flag%10==0||(flag-r)%10==0)
		cout<<1<<endl;
	else
	{
		while(flag%10!=0&&(flag-r)%10!=0)
		{
			ans++;
			flag=ans*k;
		}
			cout<<ans<<endl;

	}
	return 0;
}