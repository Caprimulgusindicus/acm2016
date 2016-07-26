#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
int n;
double cou[1111];
double cou2[1111];
int h[1111];
int c[1111];
int main()
{

	for(int i=1;i<=1111;i++)
		h[i]=i;
	cout<<7*6*5*4*3*2<<endl;
	while(~scanf("%d",&n))
	{
		
		h[n+1]=0;h[0]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&c[i]);
		}
		int cnt=0;//zong permutationshu
		int sum=0;
		do
		{
			cnt++;

			for(int i=1;i<=n;i++)
				{
					if(h[i]>h[i-1]&&h[i]>h[i+1])
						sum+=c[i];
				}
		} while (next_permutation(h+1,h+1+n));
		
		//cout<<cnt<<endl;
		double ans=double(sum)/double(cnt);
		printf("%.6lf\n",ans);
	}
	return 0;
}