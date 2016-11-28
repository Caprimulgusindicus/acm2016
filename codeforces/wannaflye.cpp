#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[111111];
int main()
{
	int n;
	while(~scanf("%d",&n)){
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	if(a[n-1]==a[0]&&n>=2) cout<<1<<endl<<a[0]<<endl;
	else if(n==1) cout<<-1<<endl;
	else if(n==2)
	{
		int d=a[1]-a[0];
		if((a[0]+a[1])%2==0) cout<<"3"<<endl<<a[0]-d<<" "<<(a[0]+a[1])/2<<" "<<a[1]+d<<endl;
		else cout<<2<<endl<<a[0]-d<<" "<<a[1]+d<<endl;
	}
	
	else if(n>=3)
	{
		int d=a[1]-a[0];
		int d2=a[2]-a[1];
		int c1=0,c2=0;
		if(d2!=d)
		for(int i=3;i<n;i++)
		{
			if(a[i]-a[i-1]==d) c1++;
			else if(a[i]-a[i-1]==d2) c2++;
			if(c1>=2||c2>=2) break;
		}
		if(c2>=c1)
			d=min(d,d2);
		int cnt=0;
		int flag=0;
		int ans=0;
		for(int i=1;i<n;i++)
		{
			if(a[i]-a[i-1]!=d) 
			{
				cnt++;
				if((a[i-1]+a[i])%2!=0||a[i-1]+2*d!=a[i])
					{flag=1;break;}
				else ans=a[i-1]+d;
			}
		}
		if(!flag)
		{
			if(!cnt) cout<<2<<endl<<a[0]-d<<" "<<a[n-1]+d<<endl;
			else if(cnt==1) cout<<1<<endl<<ans<<endl;
			else cout<<0<<endl;
		
		}
		else cout<<0<<endl;

	}
}
	return 0;
}