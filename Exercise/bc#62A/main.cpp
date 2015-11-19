#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int w[111111];
int d[111111];
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {

    	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		{
		    scanf("%d",&w[i]);
		    //cout<<w[i]<<endl;
		}
    sort(w+1,w+1+n);
    //cout<<n<<" "<<m<<" "<<endl;
	int ans=0;
	int sum=0;
	for(int i=1;i<=n;i++)
    {
        sum+=w[i];
        if(sum>m) break;
        ans++;
    }
       printf("%d\n",ans);
    }
    return 0;
  }
