#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
long long a[555][555];
long long heng[555];
long long shu[555];

long long ab(long long x)
{
	if(x>0) return x;
	else return -x;
}

int main()
{
	memset(a,0,sizeof(a));
	memset(heng,0,sizeof(heng));
	memset(shu,0,sizeof(shu));
	long long xie1=0;
	long long xie2=0;
	long long ans=0;
	long long n;
	scanf("%I64d",&n);
	long long tagi=0;long long tagj=0;
	long long totflag=0;
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=n;j++)
		{
			scanf("%I64d",&a[i][j]);
			if(a[i][j]==0) {tagi=i;tagj=j;}
			heng[i]+=a[i][j];
			shu[j]+=a[i][j];
		}
	}
	if(n==1) puts("1");
	else
	{
			long long now;
			if(tagi==1)
				now=2;
			else now=1;
			
			a[tagi][tagj]=ab(heng[now]-heng[tagi]);

			heng[tagi]+=a[tagi][tagj];
			shu[tagj]+=a[tagi][tagj];
			

			for(long long i=1;i<=n;i++)
				for(long long j=1;j<=n;j++)
				{
					if(i==j) xie1+=a[i][j];
					if(i+j-1==n) xie2+=a[i][j];
				}

			

			if(xie1!=xie2) totflag=1;
			else if(a[tagi][tagj]<=0) totflag=1;
			else
			{
				if(heng[1]!=xie1||heng[1]!=xie2) totflag=1;
				for(long long i=2;i<=n;i++)
					if(heng[i]!=heng[1]||shu[i]!=shu[1]||xie1!=heng[i]||xie2!=heng[i]||shu[i]!=xie1||shu[i]!=xie2)
						{totflag=1;break;}
			}
			if(totflag==0) printf("%I64d\n",a[tagi][tagj]);
			else puts("-1");
	}
	return 0;
}