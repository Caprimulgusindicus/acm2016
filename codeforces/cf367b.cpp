#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int x[111111];
int m[111111];

int bs(int a[], int low, int high, int key) {
    while (low < high) {
        int mid = (low + high + 1)/2;
        if (a[mid] > key) {
            high = mid -1;
        } else { //a[mid] <= key
            low = mid;
        }
    }
 
    if (a[low] <= key) {
        return low;
    } else {
        return -1;
    }
}




int main()
{
	int n,q;
	int ans;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&x[i]);
	sort(x,x+n);

	scanf("%d",&q);
	//for(int i=1;i<=n;i++)
	//	cout<<x[i]<<" ";
	for(int i=0;i<q;i++)
	{
		 ans=0;
		int m;
		scanf("%d",&m);
		
		int ans=bs(x,0,n-1,m);

		if(ans==-1) 
		 ans=0;
		else ans+=1;
		//for(int j=1;j<=n;j++)
		//	if(m>=x[j]) ans++;
		//	else break;		
		printf("%d\n",ans);

	}	//scanf("%d",&m[i]);
	return 0;
}