#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

long long heng[555];


int main()
{
	int n;
	scanf("%d",&n);
	long long m=0;
	int tagi=0;
	int tagj=0;
	long long flagheng;
	int totflag=0;
	long long ans=0;
	memset(heng,0,sizeof(heng));

	for(int i=1;i<=n;i++)
	{
		heng[i]=0;
		for(int j=1;j<=n;j++)
		{
			scanf("%lld",&m);
			if(m==0) 
				{tagi=i;tagj=j;}
			heng[i]+=m;
		 }
	}

	if(n>1)
	{
		int h=0;
		for(h=1;h<=n;h++)
			if(h!=tagi) 
				{flagheng=heng[h];break;} 

		for(int i=1;i<=n;i++)
			if(i!=tagi && i!=h) 
				if(heng[i]!=flagheng)
					{totflag=1;break;}


		ans=flagheng-heng[tagi];
		if(n>2)
		{
		 if(totflag==1||ans<=0)
		 	puts("-1");
		 else if(ans>0)
		 	printf("%lld\n",ans);
		}
			else 
		{
			totflag=0;
			flagheng=0;
			flag
		}
	}
	
	if(n==1)
			if(m==0) printf("1\n");

	return 0;
}