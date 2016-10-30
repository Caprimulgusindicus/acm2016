#include <cstring>
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
pair<int,int> tt[111];
bool ans[111111][111];
int anss;

int main()
{
	int n; 
	scanf("%d",&n);
	for(int i=0;i<n;i++) 
	{
		tt[i].second = i;
		cin >> tt[i].first;
		tt[i].first = -tt[i].first;

	}
	sort(tt, tt+n);
	while (tt[0].first != tt[n - 1].first) 
	{
		int i = 1;
		if (i < n - 1 && tt[i + 1].first == tt[0].first && tt[i + 2].first == tt[n - 1].first && tt[i + 2].first == tt[0].first + 1)
			i++;

		for(int j=0;j<=i;j++)
		{
			ans[anss][tt[j].second] = 1;
			tt[j].first++;
			if (tt[j].first>0)tt[j].first = 0;
		}
		anss++;
		sort(tt, tt + n);
	}
	cout << abs(tt[0].first) << endl;
	cout << anss << endl;
	for(int i=0;i<anss;i++) 
	{
		for(int j=0;j<n;j++)
			cout << ans[i][j];
		cout << "\n";

	}
	return 0;
}