#include <cstdio>
#include <set>
#include <cstring>
#include <string.h>
 char s[111111];
 
 int main()
 {
 	int T;
 	scanf("%d",&T);
 	for(int t=1;t<=T;t++)
 	{
 		scanf("%s",s);
 		int slen= strlen(s);
 		std::set <char> sett;
 		for (int i=0;i<slen;i++)
 		{
 			sett.insert(s[i]);
 		}
 		printf("Case #%d: %d\n",t,sett.size());
 		
 	}
 	return 0;
 }