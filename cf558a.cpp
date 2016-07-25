#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;


pair<int,int> positive[111],negative[111];

int main()
{
	int n;
	int cnt1=0;//>0
	int cnt2=0;//<0
	int ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int pos,a;
		scanf("%d%d",&pos,&a);
		if(pos>0) positive[cnt1++]=make_pair(pos,a);
		else negative[cnt2++]=make_pair(-pos,a);
	}

	sort(&positive[0],&positive[cnt1]);
	sort(&negative[0],&negative[cnt2]);
	if(cnt1>cnt2)
	{
		for(int i=0;i<cnt2;i++)
			ans+=positive[i].second+negative[i].second;
		ans+=positive[cnt2+0].second;
	}
	else 
	{
		for(int i=0;i<cnt1;i++)
			ans+=positive[i].second+negative[i].second;
		if(cnt2>cnt1)
			ans+=negative[cnt1+0].second;
	}
	
	cout<<ans<<endl;
	return 0;
}