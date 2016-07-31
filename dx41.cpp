#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int a[111111];
int vis[111111];
int maxvis[111111];

int main()
{
	int T;
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		int n;
		int cnt=0;
		scanf("%d",&n);
		if(n<=0) continue;
		int lala;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			int t=a[i];
			vis[t]=0;
			if(a[i]==i) lala++;
		}	
		//cout<<endl;
		printf("Case #%d: ",tt);
		//for(int i=1;i<=n;i++)
		//	cout<<maxvis[i]<<" "<<minvis[i]<<endl;
	if(lala==n)
	{
				printf("0 0 0\n");
				continue;
	}
else
    {bool exchange = false;  
      int index = 0;  
      int mark = n- 1;  
      for (int i = 1; i < n; ++i) {  
            for (int j = 0; j < mark; ++j) {  
                  if (a[j] > a[j + 1]) {  
                  	cnt++;
                  	vis[a[j]]++;
                  	vis[a[j+1]]++;
                        swap(a[j],a[j+1]); 
                        exchange = true ;  
                       index = j;  
                 }  
           }  
            if (!exchange) {  
                  break ;  
           }  
           mark = index;  
     }
     }  

		
		if(n==1)
		printf("0\n");
		else for(int i=1;i<=n;i++)
		{
			if(i!=n) printf("%d ",vis[i]);
			else printf("%d\n",vis[i]);
			//cout<<maxvis[i]<<" "<<minvis[i]<<endl;
		}
			
		
	}

	return 0;
}