#include <stdio.h>
#include <iostream>
using namespace std;

int main()
{
	int n;
	char a[88],b[88],c[88],d[88];
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		double sale=0;
		int clas=0;
		int day=0;int time=0;int resttime=0;
		
		//gets(a);
		gets(a);
		gets(b);
		gets(c);
		gets(d);
		if(strcmp(a,"beginner")==0) clas=1;
		if(strcmp(a,"middle")==0) clas=2;
		if(strcmp(a,"higher")==0) clas=3;
		if(strcmp(d,"workday")==0) day=1;
		if(strcmp(d,"weekend")==0) day=2;
		if(clas==0) {puts("Wrong class!");continue;}
		
		int beginhour,beginmin,endhour,endmin=0;
		beginhour=(b[0]-'0')*10+(b[1]-'0');//cout<<b[0]<<endl;
		beginmin=(b[3]-'0')*10+(b[4]-'0');//cout<<b[1]<<endl;
		endhour=(c[0]-'0')*10+(c[1]-'0');//cout<<b[3]<<endl;
		endmin=(c[3]-'0')*10+(c[4]-'0');
		//cout<<b[0]<<" "<<b[1];
		//cout<<beginhour<<endl;
		if(beginhour>23||endhour>23||beginhour<0||endhour<0
			||beginmin>59||beginmin<0||endmin>59||endmin<0)
			{puts("Wrong time!");continue;}
		if(strlen(c)!=5||strlen(b)!=5||c[2]!=':'||b[2]!=':')
			{puts("Wrong time!");continue;}
		if(!b[0]||!b[1]||!b[3]||!b[4]||!c[0]||!c[1]||!c[3]||!c[4])
			{puts("Wrong time!");continue;}
		if(endhour<beginhour) {puts("Wrong time!");continue;}
		else if(endhour==beginhour&&beginmin>endmin)
			{puts("Wrong time!");continue;}
		else if(day==0) {puts("Wrong days!");continue;}
		else 
		{
				time=(endhour*60+endmin)-(beginhour*60+beginmin);		
		}
		//cout<<resttime<<endl;
		//cout<<time<<endl;
		if(clas==1)
			sale=double(time)/double(60)*10;
		else if(clas==2)
			sale=double(time)/double(60)*11;
		else if(clas==3)
			sale=double(time)/double(60)*12;
		if(day==2) sale=sale*1.5;
		if(endhour>=22)
		{
			resttime=(endhour-22)*60+endmin;
			if(clas==1) sale+=double(resttime)/double(60)*5.0;
			if(clas==2) sale+=double(resttime)/double(60)*5.5;
			if(clas==3) sale+=double(resttime)/double(60)*6.0;
			printf("%.2lf\n",sale);
		}
		else
			printf("%.2lf\n",sale);

	}
	return 0;
}