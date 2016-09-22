#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
double biao[2500000];
int cou[2500000];



int main()
{

	char n[11111111];
	double sum=0;
	int presum=0;
	int cnt=1;
	for(int i=1;i<=2500000;i++)
	{
		double ii=double(i);
		sum+=1.0/double(ii*ii);
		biao[i]=sum;
	}
	//cout<<cnt<<endl;
	while(~scanf("%s",n))
	{
		
		int len=strlen(n);
		if(len<=6)
		{
			int i=0;
			for(int ii=0;ii<len;ii++)
				i*=10,i+=n[ii]-'0';

			printf("%.5lf\n",biao[i]);

		} 
		else 
			printf("1.64493\n");
	}
	//cout<<biao[4]<<endl;
	return 0;
}