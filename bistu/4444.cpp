#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int a,b,c,d,e,f,g;
	int a1,b1,c1,d1,e1,f1,g1;
	while(~scanf("%d%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&g))
	{
		for(int aa=0;aa<=1;aa++)
		{
			if(aa==0) a1=a;
			else a1=0;
			for(int bb=0;bb<=1;bb++)
			{
				if(bb==0)
					b1=b;
				else b1=0;
				for(int cc=0;cc<=1;cc++)
				{
					if(cc==0) c1=c;
					else c1=0;
					for(int dd=0;dd<=1;dd++)
					{
						if(dd==0) d1=d;
						else d1=0;
						for(int ee=0;ee<=1;ee++)
						{
							if(ee==0) e1=e;
							else e1=0;
							for(int ff=0;ff<=1;ff++)
							{
								if(ff==0) f1=f;
								else f1=0;
								for(int gg=0;gg<=1;gg++)
								{
									if(gg==0) g1=g;
									else g1=0;
									if(a1+b1+c1+d1+e1+f1+g1==100)
										{
											int i=0;
											
										}
								}
							}
						}
					}
				}
			}
		}


	}
	return 0;
}