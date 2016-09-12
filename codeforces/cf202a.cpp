#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
//long long a[11111];
int main()
{
	int n;
	
	while(~scanf("%d",&n))
	{
		
		int flag=0;
		long long res=0;
		long long ershiwu=0;long long wushi=0;long long yibai=0;
		for(int i=1;i<=n;i++)
		{
			long long a; 
			scanf("%lld",&a);
			if(a==25) ershiwu++;
			else if(a==50)//找25
			{
				if(ershiwu>0) ershiwu--,wushi++;
				else flag=1;
			}
			else if(a==100)//找75＝50+25 || 找3*25
			{
				if(wushi>0&&ershiwu>0) ershiwu--,wushi--,yibai++;
				else if(ershiwu>2) ershiwu-=3,yibai++;
				else flag=1;
			}
		}
		if(flag==1) puts("NO");
		else puts("YES");
	}
	return 0;
}