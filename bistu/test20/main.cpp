#include<stdio.h>
#include<math.h>
int main()
{
	int n,k,i,l=0;
        double a,b;
	printf("Please input money and k:");
	scanf("%d %d",&n,&k);
	printf("Output:\n");
	for(i=1;i<=20;i++)
	{
		a=n*i;
		b=pow(1+double(k)/100,i-1);
		if(a>=200*b)
		{
			printf("Need %d years\n",i);
			l=1;
			break;
		}
	}
	if(l==0)
		printf("Impossible\n");

	return 0;
}
