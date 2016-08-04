#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
const double pi=acos(-1.0);
int main()
{
	int a[10]={1,2,3,4,4,4,5,5,6,10};
	int k=lower_bound(a,a+9,4)-a;
	cout<<k<<endl;
	int n;
	vector <int> c;
	scanf("%d",&n);
	c.push_back(1);
	cout<<c.size()<<endl;
	return 0;
}