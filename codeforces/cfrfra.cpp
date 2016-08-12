#include <cstdio>
int main()
{
	//freopen("D:\\code\\in.txt","r",stdin);
	//read(n);
	int n;
	scanf("%d",&n);
	for(int i=20;i>=0;i--)
	{
		if(n>=(1<<i))
		{
			n-=(1<<i);
			printf("%d ",i+1);
		}
	}
    return 0;
}