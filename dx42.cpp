#include <stdio.h>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;


int main()
{
	int t;
	scanf("%d",&t);
	getchar();
	if(t==0) return 0;
	else for(int tt=1;tt<=t;tt++)
	{
		
		char s[40];
		gets(s);
		int ans=0;
		if(!strcmp(s,"San Antonio Spurs")) printf("Case #%d: %d\n",tt,5);
		else if(!strcmp(s,"Miami Heat")) printf("Case #%d: %d\n",tt,3);
		else if(!strcmp(s,"Minneapolis Lakers")) printf("Case #%d: %d\n",tt,5);
		else if(!strcmp(s,"Boston Celtics")) printf("Case #%d: %d\n",tt,17);
		else if(!strcmp(s,"L.A. Lakers")) printf("Case #%d: %d\n",tt,11);
		else if(!strcmp(s,"Chicago Bulls")) printf("Case #%d: %d\n",tt,6);
		else if(!strcmp(s,"Detroit Pistons")) printf("Case #%d: %d\n",tt,3);
		else if(!strcmp(s,"Golden State Warriors")) printf("Case #%d: %d\n",tt,2);
		else if(!strcmp(s,"Houston Rockets")) printf("Case #%d: %d\n",tt,2);
		else if(!strcmp(s,"Washington Bullets")) printf("Case #%d: %d\n",tt,1);
		else if(!strcmp(s,"Baltimore Bullets")) printf("Case #%d: %d\n",tt,1);
		else if(!strcmp(s,"Philadelphia Warriors")) printf("Case #%d: %d\n",tt,2);
		else if(!strcmp(s,"St. Louis Hawks")) printf("Case #%d: %d\n",tt,1);
		else if(!strcmp(s,"Cleveland Cavaliers")) printf("Case #%d: %d\n",tt,1);
		else if(!strcmp(s,"Dallas Mavericks")) printf("Case #%d: %d\n",tt,1);
		else if(!strcmp(s,"Seattle Sonics")) printf("Case #%d: %d\n",tt,1);
		else if(!strcmp(s,"Philadelphia 76ers")) printf("Case #%d: %d\n",tt,2);
		else if(!strcmp(s,"New York Knicks")) printf("Case #%d: %d\n",tt,2);
		else if(!strcmp(s,"Milwaukee Bucks")) printf("Case #%d: %d\n",tt,1);
		else if(!strcmp(s,"Rochester Royals")) printf("Case #%d: %d\n",tt,1);
		else if(!strcmp(s,"Syracuse Nats")) printf("Case #%d: %d\n",tt,1);
		else if(!strcmp(s,"Portland Trail Blazers")) printf("Case #%d: %d\n",tt,1);

		
		else printf("Case #%d: %d\n",tt,0);
	}
	return 0;
}