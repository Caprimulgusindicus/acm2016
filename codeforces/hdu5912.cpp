#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int a[11];
int b[11];
int ggcd(int a,int b)
{
	return (a%b) ? ggcd(b, a%b) : b;

}

int main()
{
	int T;
	scanf("%d",&T);
	for(int ca=1;ca<=T;ca++)
	{
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		if(n==0) continue;
		else
		{


			int fenzi=b[n];
			int fenmu=a[n];
			for(int i=n-1;i>=1;i--)
			{
				int yfenzi=fenzi;
				int yfenmu=fenmu;
				fenmu=a[i]*yfenmu+yfenzi;
				fenzi=yfenmu*b[i];
				//cout<<fenzi<<" "<<fenmu<<endl;
			}
			if(n==1) fenzi=b[1],fenmu=a[1];	
			int gcd=ggcd(fenzi,fenmu);

			
			printf("Case #%d: %d %d\n",ca,fenzi/gcd,fenmu/gcd);
			//cout<<fenzi<<" "<<fenmu<<endl;
		}
	}
	return 0;
}